
/* File: scheduling_algo.h
 * -----------------------
 * This file implements algorithms simulation functions of
 * scheduling class.
 */

#include "scheduling.h"
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


const int PID_BLANK = -1;

int scheduling::FCFS(){                                             // it is also possible to get individual task's attributions here ////
    sort(pqueue.begin(), pqueue.end(), cmpArrivalt);
    int clock=pqueue[0]->arrivaltime;
    for (size_t i=0; i<pqueue.size(); i++){
        pqueue[i]->waitT = clock-pqueue[i]->arrivaltime;
        pqueue[i]->responseT = pqueue[i]->waitT;
        pqueue[i]->cyclingT = pqueue[i]->waitT+pqueue[i]->timeRemain;
        clock = clock+pqueue[i]->timeRemain;
        exeQ.push_back(pqueue[i]);                                  // push this task in

        if (i!=pqueue.size()-1 && clock < pqueue[i+1]->arrivaltime){// check if there is any time blank in between this and the next
            int blank = pqueue[i+1]->arrivaltime - clock;
            task * nope = new task(PID_BLANK, blank, clock);        // create a nope task whose PID is -1 to indicate a blank period
            exeQ.push_back(nope);
            clock = clock + blank;
        }
    }

    task * blank = new task(PID_BLANK, exeQ[0]->arrivaltime, 0);
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
    int clock = 0, pid = -1, arrive;

    while (finished.size()!=pqueue.size()){
        // process execution //
        if (runQ.size()!=0){
            pid = runQ[0]->pid;
            arrive = runQ[0]->arrivaltime;
            runQ[0]->timeRemain--;                                  // the highest priority task execute for one clock time
            responsed.insert(runQ[0]->pid);

            if (runQ[0]->timeRemain == 0) {
                finished.insert(runQ[0]->pid);
                runQ[0]->cyclingT = clock - runQ[0]->arrivaltime;   // time from creating to completing
                runQ[0] = *(runQ.end()-1);
                runQ.erase(runQ.end()-1);
                if (runQ.size()!=0) runQ[0]->waitT++;

                task * period = new task(pid, clock-startP, arrive);
                exeQ.push_back(period);

                startP = clock;
            }
        }
        // efficiency attributes //
        for (size_t i=0; i<runQ.size(); i++){                       // for every remaining tasks inside the task queue
            if (responsed.find(runQ[i]->pid) == responsed.end()) runQ[i]->responseT++;
            if (i != 0) runQ[i]->waitT++;
        }
        // reorder the execution queue //
        if (sortQueue(runQ)){                                       // sort the queue at every cycle
            task * period = new task(pid, clock-startP, arrive);    // if the running task changes, need to record the period execution
            startP = clock;
            exeQ.push_back(period);
        }
        // process creation //
        if (clock == copyQ[0]->arrivaltime && copyQ.size() != 0) {   // since erase will leave the last element at <code>vec[0]</code>
            enqueue(runQ, copyQ[0]);                                 // shallow copy, therefore all changes to <code>runQ[i]</code>, will affect pqueue
            copyQ.erase(copyQ.begin());
            if (runQ[0]->pid!=pid && pid!=-1) {                      // if the currently executing task changed
                task * period = new task(pid, clock-startP, arrive);
                startP = clock;
                exeQ.push_back(period);
            }
            if (runQ.size()==1){                                     // if last period is blank
                task * nope = new task(PID_BLANK, clock-startP, -1);
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
    task * current;                                                 // separate the executing task so that the rest of the vector can keep the structure of heap

    bool operation = false;
    int pid, arrive;
    int clock = 0, startP = 0;


    while (finished.size()!=pqueue.size()){
        // process execution //
        if (operation){
            pid = current->pid;
            arrive = current->arrivaltime;
            current->timeRemain--;                                    // the highest priority task execute for one clock time
            responsed.insert(current->pid);
        }

        // efficiency attributes //
        for (size_t i=0; i<runQ.size(); i++){                         // for every remaining tasks inside the task queue
            if (responsed.find(runQ[i]->pid) == responsed.end()) runQ[i]->responseT++;
            runQ[i]->waitT++;                                         // unlike SRT, the runQ now are all waiting tasks
        }

        // process termination //
        if (operation && current->timeRemain == 0) {
            finished.insert(current->pid);
            current->cyclingT = clock - current->arrivaltime;     // time from creating to completing
            task * period = new task(pid, clock-startP, arrive);
            exeQ.push_back(period);                               // terminate and record the finished task

            startP = clock;                                       // start a new task
            if (runQ.size()!=0){
                current = runQ[0];
                runQ[0] = *(runQ.end()-1);
                runQ.erase(runQ.end()-1);
                sortQueue(runQ);
            }else operation = false;
        }

        // process creation //
        if (clock == copyQ[0]->arrivaltime && copyQ.size() != 0) {
            enqueue(runQ, copyQ[0]);
            copyQ.erase(copyQ.begin());
            if (!operation && runQ.size()==1){                    // meaning just now, there is a blank period
                task * nope = new task(PID_BLANK, clock-startP, -1);
                exeQ.push_back(nope);

                startP = clock;
                operation = true;
                current = runQ[0];                                // the current executing task
                runQ.erase(runQ.begin());                         // leave the rest be in the BST order
            }
        }
        clock++;
    }
    return 0;
}

int scheduling::HRRN(){
    sort(pqueue.begin(), pqueue.end(), cmpArrivalt);
    vector<task*> copyQ(pqueue);
    vector<task*> runQ;                                             // queue of task that is under execution
    set<int> responsed;
    set<int> finished;

    int pid, arrive;
    int clock = 0, startP = 0;

    while (finished.size()!=pqueue.size()) {
        if (runQ.size()!=0){
            pid = runQ[0]->pid;
            arrive = runQ[0]->arrivaltime;
            runQ[0]->timeRemain--;
            responsed.insert(runQ[0]->pid);
        }
        for (size_t i=1; i<runQ.size(); i++){
            if (responsed.find(runQ[i]->pid) == responsed.end()) runQ[i]->responseT++;
            runQ[i]->waitT++;
        }
        if (runQ.size()!=0 && runQ[0]->timeRemain==0) {
            finished.insert(runQ[0]->pid);
            runQ[0]->cyclingT = clock - runQ[0]->arrivaltime;     // time from creating to completing
            task * period = new task(pid, clock-startP, arrive);
            exeQ.push_back(period);                               // terminate and record the finished task
            startP = clock;
            runQ.erase(runQ.begin());
            if (runQ.size()!=0){
                calPriority(runQ.begin(), runQ.end());            // priority calculation only when a task finishes
                sort(runQ.begin(), runQ.end(), cmpPriority);
            }
        }
        if (clock == copyQ[0]->arrivaltime && copyQ.size() != 0) {
            runQ.push_back(copyQ[0]);                             // just add to the end and wait for termination of the current task
            copyQ.erase(copyQ.begin());
            if (runQ.size()==1){                                  // meaning just now, there is a blank period
                task * nope = new task(PID_BLANK, clock-startP, -1);
                exeQ.push_back(nope);

                startP = clock;
            }
        }
        clock++;
    }
    return 0;
}

int scheduling::RR(){
    sort(pqueue.begin(), pqueue.end(), cmpArrivalt);
    vector<task*> copyQ(pqueue);
    vector<task*> runQ;                                             // queue of task that is under execution
    set<int> responsed;
    set<int> finished;

    int pid, arrive, pSlice = -1;
    int clock = 0, startP = 0, slice = 4;

    while (finished.size()!=pqueue.size()) {
        if (runQ.size()!=0){
            pid = runQ[0]->pid;
            arrive = runQ[0]->arrivaltime;
            runQ[0]->timeRemain--;
            responsed.insert(runQ[0]->pid);

        }
        for (size_t i=1; i<runQ.size(); i++){
            if (responsed.find(runQ[i]->pid) == responsed.end()) runQ[i]->responseT++;
            runQ[i]->waitT++;
        }
        if (runQ.size()!=0 && runQ[0]->timeRemain==0) {
            finished.insert(runQ[0]->pid);
            runQ[0]->cyclingT = clock - runQ[0]->arrivaltime;       // time from creating to completing
            task * period = new task(pid, pSlice+1, arrive);
            exeQ.push_back(period);                                 // terminate and record the finished task
            runQ.erase(runQ.begin());
            pSlice = -1;
            if (runQ.size()==0) startP = clock;
        }
        if (clock == copyQ[0]->arrivaltime && copyQ.size() != 0) {
            runQ.push_back(copyQ[0]);                               // just add to the end and wait for termination of the current task
            copyQ.erase(copyQ.begin());
            if (runQ.size()==1){                                    // meaning just now, there is a blank period
                task * nope = new task(PID_BLANK, clock-startP, -1);
                exeQ.push_back(nope);
                startP = clock;
                pSlice = -1;
            }
        }
        if (pSlice == slice-1 && runQ.size()!=0){                   // make sure that the executed one has not being terminated
            runQ.push_back(runQ[0]);
            runQ.erase(runQ.begin());
            pSlice = -1;
            task * oneSlice = new task(pid, slice, arrive);
            exeQ.push_back(oneSlice);
        }

        pSlice++;
        clock++;
    }
    return 0;
}







