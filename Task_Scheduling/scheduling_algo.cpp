
/* File: scheduling_algo.h
 * -----------------------
 * This file implements scheduling class.
 */

#include "scheduling_algo.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;



scheduling::scheduling(){
    selectAlgo();
    getCondition();
    Twait = AverWait = MaxWait = MinWait = 0;
    TResp = AverResp = MaxResp = MinResp = 0;
    TCy = AverCy = MaxCy = MinCy = 0;
}

bool scheduling::cmpArrivalq(task* a, task* b){
    if (a->arrivalq == b->arrivalq) return a->pid < b->pid;
    return  a->arrivalq < b->arrivalq;
}

bool scheduling::cmpPriority(task* a, task* b){
    if (a->priority == b->priority) return a->pid < b->pid;
    return a->priority < b->priority;
}

bool scheduling::cmpArrivalt(task* a, task* b){
    if (a->priority != b->priority)       return a->priority < b->priority;
    if (a->arrivaltime == b->arrivaltime) return a->pid < b->pid;
    return a->arrivaltime < b->arrivaltime;
}

bool scheduling::cmpwaitT(task* a, task* b){
    if (a->waitT == b->waitT) return a->pid < b->pid;
    return a->waitT < b->waitT;
}

bool scheduling::cmpRemain(task* a, task* b){
    if (a->timeRemain == b->timeRemain) return a->pid < b->pid;
    return a->timeRemain < b->timeRemain;
}

bool scheduling::comparision(task * a, task * b){

    if (algorithm == 0) return cmpArrivalt(a, b);
}

void scheduling::enqueue(task * a){


    int position = pqueue.size();
    cout << "..." << endl;
    pqueue.push_back(a);

    if (position == 0) return;

    task* parent = pqueue[(position-1)/2];
    while (comparision(a, parent)){
        task* buffer;
        buffer = parent;
        pqueue[(position-1)/2] = a;
        pqueue[position] = parent;
        position = (position-1)/2;
        if (position==0) break;
        parent = pqueue[(position-1)/2];
    }
}

void scheduling::selectAlgo(){
    int index;
    cout << "Enter the scheduling algorithm (int number from [0,7]) >>> ";
    cin >> index;
    algorithm = (schedulingAlgos) index;
}

void scheduling::getCondition(){
    int nPR; task *a; int buffer;
    vector<int> timeDuration, arrivalt, priority;
    cout << "Please enter the total number of processes >>> ";
    cin >> nPR;

    cout << "Process    Brust Time" << endl;
    cout << "-------    ----------" << endl;
    for (int i=0; i<nPR; i++)                                           // set pid and brustime for each process
    {
        a->pid = i;
        cout << "   P" << i+1 << "          ";
        cin >> buffer;
        timeDuration.push_back(buffer);
    }

    cout << "Process    Arrival Time (moment)" << endl;
    cout << "-------    ---------------------" << endl;
    for (int i=0; i<nPR; i++)
    {
        a->pid = i;
        cout << "   P" << i+1 << "                ";
        cin >> buffer;
        arrivalt.push_back(buffer);
    }

    cout << "Process    Priority" << endl;
    cout << "-------    --------" << endl;
    for (int i=0; i<nPR; i++)
    {
        a->pid = i;
        cout << "   P" << i+1 << "         ";
        cin >> buffer;
        priority.push_back(buffer);                                         // priority could be the same
    }

    for (int i=0; i<nPR; i++){
        a->pid = i;
        a->timeRemain = timeDuration[i];
        a->arrivaltime = arrivalt[i];
        a->priority = priority[i];
        enqueue(a);
    }


}

void scheduling::efficiency(){                                      // need to later change to make operations on individual tasks/process attributes
    int max=-1, min=-1, maxC=-1, minC=-1;
    set<task *> responsed;                                          // store tasks that has already being responsed to

    // this is the first draft of <code>efficienvy</code> which, basically can just dealt with FIFS algorithm //
    for (size_t i=0; i<exeQ.size(); i++) {                          // if this is a blank period placeholder, ignore it
        if (exeQ[i]->pid == -1){                                    // when come across blank period, no waiting time or response time or cycling time required
            continue;
        }
        if (pqueue[i]->arrivaltime < pqueue[i+1]->timeRemain){
            int waitTime = pqueue[i-1]->timeRemain - pqueue[i]->arrivaltime;
            Twait += waitTime;
            TCy += waitTime + pqueue[i]->timeRemain;                // total cycling time
            if (max==-1 || max < waitTime)  max = waitTime;
            if (min==-1 || min > waitTime)  min = waitTime;
            if (maxC==-1 || maxC < waitTime + pqueue[i]->timeRemain)    maxC = waitTime + pqueue[i]->timeRemain;
            if (minC==-1 || minC > waitTime + pqueue[i]->timeRemain)    minC = waitTime + pqueue[i]->timeRemain;
        }
        else TCy += pqueue[i]->timeRemain;
    }

    TResp = Twait;
    AverWait = AverResp = Twait / pqueue.size();
    MaxWait = MaxResp = max;
    MinWait = MinResp = min;
    AverCy = TCy / pqueue.size();

}


int scheduling::FCFS(){                                             // it is also possible to get individual task's attributions here ////
    for (size_t i=0; i<pqueue.size()-1; i++){
        exeQ.push_back(pqueue[i]);                                  // push this task in

        int this_end = pqueue[i]->arrivaltime+pqueue[i]->timeRemain;
        if (this_end < pqueue[i+1]->arrivaltime){                   // check if there is any time blank in between this and the next
            int blank = pqueue[i+1]->arrivaltime - this_end;
            task * nope;                                            // create a nope task whose PID is -1 to indicate a blank period
            nope->timeRemain = blank;
            exeQ.push_back(nope);
        }
    }
    exeQ.push_back(pqueue[pqueue.size()-1]);                        // push in the last task
    if (exeQ[0]->arrivaltime != 0){
        task * blank;
        blank->timeRemain = exeQ[0]->arrivaltime;
        exeQ.insert(exeQ.begin(), blank);
    }
}


int scheduling::SJF(){
    for (size_t i=0; i<pqueue.size(); i++){

    }
}







void scheduling::test(){
    cout << "---------------------------------" << endl;
    for (size_t i=0; i<pqueue.size(); i++){
        cout << "P1:    ";
        cout << "pid: " << pqueue[i]->pid;
        cout << "time remain: " << pqueue[i]->timeRemain;
        cout << "arrive time: " << pqueue[i]->arrivaltime;
        cout << "priority: " << pqueue[i]->priority;
    }
    cout << "---------------------------------" << endl;
    for (size_t i=0; i<exeQ.size(); i++){
        cout << "P1:    ";
        cout << "pid: " << exeQ[i]->pid;
        cout << "time remain: " << exeQ[i]->timeRemain;
        cout << "arrive time: " << exeQ[i]->arrivaltime;
        cout << "priority: " << exeQ[i]->priority;
    }
}








