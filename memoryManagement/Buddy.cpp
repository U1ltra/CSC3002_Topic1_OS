#include <Buddy.h>
#include <pair.h>
#include <vector>
#include <list>
#include <iostream>
#include <math.h>
#include <map>
#include <m_task.h>

using namespace std;

Buddy::Buddy(int s){
    size = s;
    int num = (int) ceil(log(s) / log(2));
    arr = vector<list<Pair>>(num + 1);
    arr[num].push_front(Pair(0,size-1));
}

bool Buddy::allocate(m_task &current){
    int s = current.memory;
    int num = (int) ceil(log(s) / log(2));
    if (arr[num].size() > 0){
        Pair tem = arr[num].back();
        arr[num].pop_back();
        current.starting_Address = tem.lb;
        Bu_map[current] = tem.ub - tem.lb + 1;
        cout << "memory from " << tem.lb << " to " << tem.ub << " " << "allocated." << endl;
        return true;
    }
    int i;
    for (i = num+1; i < arr.size(); i++){
        if (arr[i].size() == 0) continue;
        break;
    }

    if (i == arr.size()){
        cout << "Fail to allocate memory" << endl;
        return false;
    }
    Pair tem = arr[i].back();
    arr[i].pop_back();
    i--;
    for (; i >= num; i--){
        Pair newpair = Pair(tem.lb, tem.lb + (tem.ub - tem.lb)/2);
        Pair newpair2= Pair(tem.lb + (tem.ub - tem.lb) / 2 + 1, tem.ub);
        arr[i].push_front(newpair);
        arr[i].push_front(newpair2);
        tem = arr[i].back();
        arr[i].pop_back();
    }
    current.starting_Address = tem.lb;
    Bu_map[current] = tem.ub - tem.lb + 1;
    cout << "Memory from " << tem.lb << " to " << tem.ub << " allocated" << endl;
    return true;
}



bool Buddy::deallocate(m_task &current){
    int index = current.starting_Address;
    if (!Bu_map.count(current)){
        cout << "Sorry, invalid free request" << endl;
        return false;
    }

    int num = (int) ceil(log(Bu_map[current] / log(2)));
    int buddyNum, buddyAddress;
    arr[num].push_front(Pair(index, index + (int)pow(2,num) - 1));
    cout << "Memory from " << index << " to " << index + (int)pow(2,num) - 1 << " freed." << endl;
    buddyNum = index / Bu_map[current];
    if (buddyNum % 2 != 0)
        buddyAddress = index - (int) pow(2,num);
    else
        buddyAddress = index + (int) pow(2,num);

    list<Pair>::iterator it;
    for (it = arr[num].begin(); it != arr[num].end(); it++){
        if (it->lb == buddyAddress){
            if (buddyNum % 2 == 0){
                arr[num+1].push_front(Pair(index, index + 2 * ((int)pow(2,num)) - 1));
                cout << "Coalescing of blocks starting at " << index << " and " <<
                        buddyAddress << " was done " << endl;
            }else {
                arr[num+1].push_front(Pair(buddyAddress, buddyAddress + 2 * ((int)pow(2,num)) - 1));
                cout << "Coalescing of blocks starting at " << buddyAddress <<" and " <<
                        index << " was done " << endl;
            }
            arr[num].erase(it);
            arr[num].pop_front();
            break;
        }
    }
    Bu_map.erase(current);
    return true;
}
