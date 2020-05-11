
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


scheduling::task::task(){
    pid = -1;
    IO = false;
    CPUT = IOT = 0;
    arrivaltime = timeRemain = priority = 0;
    waitT = cyclingT = responseT = 0;
}

scheduling::task::task(int p,int a, int arr){
    pid = p;
    IO = false;
    CPUT = IOT = 0;
    timeRemain = a;
    waitT = priority = 0;
    cyclingT = responseT = 0;
    arrivaltime = arr;
}

scheduling::scheduling(){
    selectAlgo();
    getCondition();
    TCy = AverCy = MaxCy = MinCy = 0;
    Twait = AverWait = MaxWait = MinWait = 0;
    TResp = AverResp = MaxResp = MinResp = 0;
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
    int ratio1 = (a->waitT + a->timeRemain) / a->timeRemain;
    int ratio2 = (b->waitT + b->timeRemain) / b->timeRemain;
    return ratio1 < ratio2;
}

bool scheduling::cmpRemain(task* a, task* b){
    if (a->timeRemain == b->timeRemain) return a->pid < b->pid;
    return a->timeRemain < b->timeRemain;
}

bool scheduling::comparision(task * a, task * b){
    if      (algorithm == _FCFS)    return cmpArrivalt(a, b);
    else if (algorithm == _SJF)     return cmpRemain(a, b);
    else if (algorithm == _SRT)     return cmpRemain(a, b);
    else if (algorithm == _HRRN)    return cmpwaitT(a, b);
//    else if (algorithm == _RR)      return

    return false; // uselesssssss
}

void scheduling::enqueue(vector<task *> & Q, task * & a){
    int position = Q.size();
    Q.push_back(a);
    if (position == 0) return;

    task* parent = Q[(position-1)/2];
    while (comparision(a, parent)){
        task* buffer;
        buffer = parent;
        Q[(position-1)/2] = a;
        Q[position] = parent;
        position = (position-1)/2;
        if (position==0) break;
        parent = Q[(position-1)/2];
    }
}

bool scheduling::sortQueue(vector<task *> & Q){
    size_t position = 0;
    size_t newPosition = 0;
    while (position*2+1 < Q.size()){         // keep the queue in a heap structure of BST
        if (position*2+2 < Q.size()){        // always the highest priority task at the front
            newPosition = comparision(Q[position*2+1], Q[position*2+2]) ? position*2+1 : position*2+2;
            newPosition = comparision(Q[position], Q[newPosition]) ? position : newPosition;
        }else {
            newPosition = comparision(Q[position], Q[position*2+1]) ? position : position*2+1;
        }

        if (newPosition == position) break;
        task * buffer = Q[position];
        Q[position] = Q[newPosition];
        Q[newPosition] = buffer;
        position = newPosition;
    }
    if (position!=0) return true;
    return false;
}

void scheduling::selectAlgo(){
    int index;
    cout << "Enter the scheduling algorithm (int number from [0,7]) >>> ";
    cin >> index;
    algorithm = (schedulingAlgos) index;
}

void scheduling::getCondition(){
    int buffer;
    vector<int> timeDuration, arrivalt, priority;
    cout << "Please enter the total number of processes >>> ";
    cin >> Tprocess;

    cout << "Process    Brust Time" << endl;
    cout << "-------    ----------" << endl;
    for (int i=0; i<Tprocess; i++)                                           // set pid and brustime for each process
    {
        cout << "   P" << i+1 << "          ";
        cin >> buffer;
        timeDuration.push_back(buffer);
    }

    cout << "Process    Arrival Time (moment)" << endl;
    cout << "-------    ---------------------" << endl;
    for (int i=0; i<Tprocess; i++)
    {
        cout << "   P" << i+1 << "                ";
        cin >> buffer;
        arrivalt.push_back(buffer);
    }

    cout << "Process    Priority" << endl;
    cout << "-------    --------" << endl;
    for (int i=0; i<Tprocess; i++)
    {
        cout << "   P" << i+1 << "         ";
        cin >> buffer;
        priority.push_back(buffer);                                         // priority could be the same
    }

    for (int i=0; i<Tprocess; i++){
        task *a = new task;
        a->pid = i;
        a->timeRemain = timeDuration[i];
        a->arrivaltime = arrivalt[i];
        a->priority = priority[i];
        enqueue(pqueue, a);
    }


}

void scheduling::efficiency(){                                      // need to later change to make operations on individual tasks/process attributes
    int max=-1, min=-1, maxC=-1, minC=-1;
    set<task *> responsed;                                          // store tasks that has already being responsed to
    set<task *> finished;                                           // store tasks that has already finished execution

    // this is the first draft of <code>efficienvy</code> which, basically can just dealt with FIFS algorithm //
    for (size_t i=0; i<exeQ.size(); i++) {                          // if this is a blank period placeholder, ignore it
        if (exeQ[i]->pid==-1 || exeQ[i+1]->pid==-1) continue;       // when come across blank period, no waiting time or response time or cycling time required

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
    sort(pqueue.begin(), pqueue.end(), cmpArrivalt);
    for (size_t i=0; i<pqueue.size()-1; i++){
        exeQ.push_back(pqueue[i]);                                  // push this task in

        int this_end = pqueue[i]->arrivaltime+pqueue[i]->timeRemain;
        if (this_end < pqueue[i+1]->arrivaltime){                   // check if there is any time blank in between this and the next
            int blank = pqueue[i+1]->arrivaltime - this_end;
            task * nope = new task;                                 // create a nope task whose PID is -1 to indicate a blank period
            nope->timeRemain = blank;
            exeQ.push_back(nope);
        }
    }
    exeQ.push_back(pqueue[pqueue.size()-1]);                        // push in the last task

    task * blank = new task(-1, exeQ[0]->arrivaltime, 0);
    exeQ.insert(exeQ.begin(), blank);                               // always insert a blank task according to the starting time of the first process

    return 0;
}

int scheduling::SRT(){
    sort(pqueue.begin(), pqueue.end(), cmpArrivalt);
    vector<task*> copyQ(pqueue);
    vector<task*> runQ;                                             // queue of task that is under execution
    set<int> responsed;
    set<int> finished;

    int startP = 0;                                                 // <code>processStart<code> is for recording the starting point of a process
    int clock = 0, arrive, pid;

    while (finished.size()!=pqueue.size()){
        // process execution //
        if (runQ.size()!=0){
            pid = runQ[0]->pid;
            arrive = runQ[0]->arrivaltime;
            runQ[0]->timeRemain--;                                    // the highest priority task execute for one clock time
            responsed.insert(runQ[0]->pid);

            if (runQ[0]->timeRemain == 0) {
                finished.insert(runQ[0]->pid);
                runQ[0]->cyclingT = clock - runQ[0]->arrivaltime;     // time from creating to completing
                runQ.erase(runQ.begin());
                if (runQ.size()!=0) runQ[0]->waitT++;
                task * period = new task(pid, clock-startP, arrive);
                startP = clock;
                exeQ.push_back(period);
            }
        }
        // efficiency attributes //
        for (size_t i=0; i<runQ.size(); i++){                         // for every remaining tasks inside the task queue

            if (responsed.find(runQ[i]->pid) == responsed.end()) runQ[i]->responseT++;
            if (i != 0) runQ[i]->waitT++;
        }
        // reorder the execution queue //
        if (sortQueue(runQ)){
            task * period = new task(pid, clock-startP, arrive);     // if the running task changes, need to record the period execution
            startP = clock;
            exeQ.push_back(period);
        }
        // process creation //
        if (clock == copyQ[0]->arrivaltime && copyQ.size() != 0) {    // since erase will leave the last element at <code>vec[0]</code>
            enqueue(runQ, copyQ[0]);                                  // shallow copy, therefore all changes to <code>runQ[i]</code>, will affect pqueue
            copyQ.erase(copyQ.begin());
            if (runQ.size()==1){                                      // if last period is blank
                task * nope = new task(-1, clock-startP, -1);
                startP = clock;
                exeQ.push_back(nope);
            }
        }
        clock++;
    }
    return 0;
}


int scheduling::SJF(){
    sort(pqueue.begin(), pqueue.end(), cmpArrivalt);
    vector<task*> copyQ(pqueue);
    vector<task*> runQ;                                             // queue of task that is under execution
    set<int> responsed;
    set<int> finished;

    int pid, arrive;
    int clock = 0, startP = 0;

    while (finished.size()!=pqueue.size()){
        // process execution //
        if (runQ.size()!=0){
            pid = runQ[0]->pid;
            arrive = runQ[0]->arrivaltime;
            runQ[0]->timeRemain--;                                    // the highest priority task execute for one clock time
            responsed.insert(runQ[0]->pid);
        }

        // efficiency attributes //
        for (size_t i=0; i<runQ.size(); i++){                         // for every remaining tasks inside the task queue
            if (responsed.find(runQ[i]->pid) == responsed.end()) runQ[i]->responseT++;
            if (i != 0) runQ[i]->waitT++;
        }

        // process termination //
        if (runQ[0]->timeRemain == 0) {
            finished.insert(runQ[0]->pid);
            runQ[0]->cyclingT = clock - runQ[0]->arrivaltime;     // time from creating to completing
            runQ.erase(runQ.begin());
            task * period = new task(pid, clock-startP, arrive);
            startP = clock;
            exeQ.push_back(period);
        }

        // process creation //
        if (clock == copyQ[0]->arrivaltime && copyQ.size() != 0) {
            enqueue(runQ, copyQ[0]);
            copyQ.erase(copyQ.begin());
            if (runQ.size()==1){
                task * nope = new task(-1, clock-startP, -1);
                startP = clock;
                exeQ.push_back(nope);
            }
        }
        clock++;
    }
}





void scheduling::test(){
    cout << "-----------------------------------------------------------------" << endl;
    for (size_t i=0; i<pqueue.size(); i++){
        cout << "P" << i << ":    ";
        cout << "pid: " << pqueue[i]->pid;
        cout << "   time remain: " << pqueue[i]->timeRemain;
        cout << "   arrive time: " << pqueue[i]->arrivaltime;
        cout << "   priority: " << pqueue[i]->priority;
        cout << "   waitT: " << pqueue[i]->waitT;
        cout << "   respT: " << pqueue[i]->responseT;
        cout << "   cyT: " << pqueue[i]->cyclingT << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    for (size_t i=0; i<exeQ.size(); i++){
        cout << "P" << i << ":    ";
        cout << "pid: " << exeQ[i]->pid;
        cout << "   time remain: " << exeQ[i]->timeRemain;
        cout << "   arrive time: " << exeQ[i]->arrivaltime;
        cout << "   priority: " << exeQ[i]->priority;
        if (exeQ[i]->pid == -1) {
            cout << endl;
            continue;
        }
        cout << "   waitT: " << exeQ[i]->waitT;
        cout << "   respT: " << exeQ[i]->responseT;
        cout << "   cyT: " << exeQ[i]->cyclingT << endl;


    }
    cout << "-----------------------------------------------------------------" << endl;
}








