
/*
 * File: Buddy.cpp
 * ---------------
 * This file implements <code>Buddy</code> class.
 */

#include <math.h>
#include "memoryGame/Buddy.h"
#include "memoryGame/pair.h"

using namespace std;

Buddy::Buddy(int s){
    size = s;
    int num = (int) ceil(log(s) / log(2));
    arr = vector<list<Pair>>(num + 1);
    arr[num].push_front(Pair(0,size-1));
}

bool Buddy::mem_allocation(m_task &current){
    int s = current.memory;
    if (size<s) return false;
    int num = (int) ceil(log(s) / log(2));
    if (arr[num].size() > 0){
        Pair tem = arr[num].back();
        arr[num].pop_back();
        current.starting_Address = tem.lb;
        Bu_map[current] = tem.ub - tem.lb + 1;
        return true;
    }
    size_t i;
    for (i = num+1; i < arr.size(); i++){
        if (arr[i].size() == 0) continue;
        break;
    }

    if (i == arr.size()){
        return false;
    }
    Pair tem = arr[i].back();
    arr[i].pop_back();
    i--;
    for (; static_cast<int>(i) >= num; i--) {
        Pair newpair = Pair(tem.lb, tem.lb + (tem.ub - tem.lb)/2);
        Pair newpair2= Pair(tem.lb + (tem.ub - tem.lb) / 2 + 1, tem.ub);
        arr[i].push_front(newpair);
        arr[i].push_front(newpair2);
        tem = arr[i].back();
        arr[i].pop_back();
    }
    current.starting_Address = tem.lb;
    Bu_map[current] = tem.ub - tem.lb + 1;
    return true;
}



bool Buddy::deallocate(m_task &current){
    int index = current.starting_Address;
    if (!Bu_map.count(current)){
        return false;
    }
    int num = (int) ceil(log(Bu_map[current]) / log(2));
    arr[num].push_front(Pair(index, index + (int)pow(2,num) - 1));
    merge(num,index);
    Bu_map.erase(current);
    return true;
}

void Buddy::merge(int num, int index){
    int buddyNum = index / pow(2,num);
    int buddyAddress;
    if (buddyNum % 2 != 0)
        buddyAddress = index - (int) pow(2,num);
    else
        buddyAddress = index + (int) pow(2,num);

    list<Pair>::iterator it;
    for (it = arr[num].begin(); it != arr[num].end(); it++){
        if (it->lb == buddyAddress){
            if (buddyNum % 2 == 0){
                arr[num+1].push_front(Pair(index, index + 2 * ((int)pow(2,num)) - 1));
            }else {
                arr[num+1].push_front(Pair(buddyAddress, buddyAddress + 2 * ((int)pow(2,num)) - 1));
            }
            arr[num].erase(it);
            arr[num].pop_front();
            break;
        }
    }
    //If coalescing still can take place, keep on merging.
    if (++num <  log(this->size) / log(2))
        merge(num, index);
    else return;
}


bool Buddy::mem_allocation(int PID,int size){
    m_task *task = new m_task(PID,size);
    return mem_allocation(*task);
}

bool Buddy::deallocate(int PID,int size){
    m_task *task = new m_task(PID,size);
    return deallocate(*task);
}

int Buddy::getsize(){
    return size;
}
