
/* File: scheduling_algo.h
 * -----------------------
 * This file implements scheduling class.
 */

#include "scheduling_algo.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



scheduling::scheduling(){
    selectAlgo();
    if (algorithm == _FCFS) setFCFS();
    Twait = 0;
    TResp = 0;
    TCy = 0;
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

void scheduling::setFCFS(){
    int nPR; task *a; int buffer;
    cout << "Please enter the total number of processes >>> ";
    cin >> nPR;
    cout << "Process    Brust Time    Arrival Time (moment)" << endl;
    cout << "-------    ----------    ---------------------" << endl;
    for (int i=0; i<nPR; i++)                                   // set pid and brustime for each process
    {
        a->pid = i;
        cout << "   P" << i+1 << "          " << endl;
        cin >> buffer;
        a->timeRemain = buffer;
        cout << "                " << endl;
        cin >> buffer;
        a->arrivaltime = buffer;
        enqueue(a);
    }
}

void scheduling::efficiency(){                                      // need to later change to make operations on individual task distributions
    int max=-1, min=-1, maxC=-1, minC=-1;
    for (size_t i=1; i<pqueue.size(); i++) {
        if (pqueue[i]->arrivaltime < pqueue[i-1]->timeRemain){
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

int scheduling::FCFS(){
    exeQ = pqueue;                              // for FCFS, the execution queue is jus the same as task queue sorted according to arriveq
}






/*
int FCFS(){
    int nPR; taskStuc a; int buffer; string press;
    cout << "Please enter the total number of processes >>> ";
    cin >> nPR;
    cout << "Process    Brust Time" << endl;
    cout << "-------    ----------" << endl;
    for (int i=0; i<nPR; i++)                                   // set pid and brustime for each process
    {
        a.setAttributes("pid", i);
        cout << "   P" << i+1 << "          " << endl;
        cin >> buffer;
        a.setAttributes("brustime", buffer);
        PROCESSES.push_back(a);
    }

    cout << "Do you want to specify an arrival queue? (Y/N) >>> ";
    cin >> press;
    if (press == "Y" || press == "y"){
        cout << "Process    Arrival Queue" << endl;
        cout << "-------    -------------" << endl;
        for (int i=0; i<nPR; i++){
            cout << "   P" << i+1 << "            ";
            cin >> buffer;
            PROCESSES[i].setAttributes("arrivalq", buffer);
        }
        sort(PROCESSES.begin(), PROCESSES.end(), a);
    }

    PROCESSES.clear();          // clear the global vector when one simulation is done
}


int avgWaitingT(){

}
*/






