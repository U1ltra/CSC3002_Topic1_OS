
/* File: scheduling_algo.h
 * -----------------------
 * This file implements support functions of scheduling class.
 */

#include "scheduling.h"
#include <iostream>
#include <vector>

using namespace std;



task::task(){
    pid = PID_BLANK;
    IO = false;
    CPUT = IOT = 0;
    arrivaltime = timeRemain = priority = 0;
    waitT = cyclingT = responseT = 0;
}

task::task(int p,int a, int arr){
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
    TCy = AverCy =  0;
    Twait = AverWait =  0;
    TResp = AverResp =  0;
    MaxWait = MinWait = -1;
    MaxResp = MinResp = -1;
    MaxCy = MinCy = -1;
}

scheduling::~scheduling(){
    for (vector<task*>::iterator i=pqueue.begin(); i<pqueue.end(); i++) delete *i;
    for (vector<task*>::iterator i=exeQ.begin(); i<exeQ.end(); i++) delete *i;
    pqueue.clear();
    exeQ.clear();
}

bool scheduling::cmpPriority(const task* a, const task* b){
    if (a->priority == b->priority) return a->pid < b->pid;
    return a->priority > b->priority;
}

bool scheduling::cmpArrivalt(const task* a, const task* b){
    if (a->arrivaltime == b->arrivaltime) return a->pid < b->pid;
    return a->arrivaltime < b->arrivaltime;
}

bool scheduling::cmpwaitT(const task* a, const task* b){
    if (a->waitT == b->waitT) return a->pid < b->pid;
    int ratio1 = (a->waitT + a->timeRemain) / a->timeRemain;
    int ratio2 = (b->waitT + b->timeRemain) / b->timeRemain;
    return ratio1 < ratio2;
}

bool scheduling::cmpRemain(const task* a, const task* b){
    if (a->timeRemain == b->timeRemain) return a->pid < b->pid;
    return a->timeRemain < b->timeRemain;
}

bool scheduling::comparision(const task * a, const task * b){
    if      (algorithm == _FCFS)    return cmpArrivalt(a, b);
    else if (algorithm == _SJF)     return cmpRemain(a, b);
    else if (algorithm == _SRT)     return cmpRemain(a, b);
    else if (algorithm == _HRRN)    return cmpPriority(a, b);
    else                            return cmpPID(a, b);
}

bool scheduling::cmpPID(const task * a, const task * b){
    return a->pid<b->pid;
}

void scheduling::calPriority(std::vector<task *>::iterator b, std::vector<task *>::iterator e){
    while (b<e) {
        (*b)->priority = ((*b)->waitT + (*b)->timeRemain) / (double) (*b)->timeRemain;
        b++;
    }
}

void scheduling::enqueue(vector<task *> & Q, task * & a){
    int position = Q.size();
    Q.push_back(a);
    if (position == 0) return;              // do nothing if the queue is empty

    task* parent = Q[(position-1)/2];       // maintain the heap structure
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

void scheduling::efficiency(){
    for (vector<task*>::iterator i=pqueue.begin(); i<pqueue.end(); i++){
        Twait = Twait + (*i)->waitT;
        TResp = TResp + (*i)->responseT;
        TCy = TCy + (*i)->cyclingT;
        if (MaxWait < (*i)->waitT || MaxWait == -1) MaxWait = (*i)->waitT;
        if (MinWait > (*i)->waitT || MinWait == -1) MinWait = (*i)->waitT;
        if (MaxResp < (*i)->responseT || MaxResp == -1) MaxResp = (*i)->responseT;
        if (MinResp < (*i)->responseT || MinResp == -1) MaxResp = (*i)->responseT;
        if (MaxCy < (*i)->cyclingT || MaxCy == -1) MaxCy = (*i)->cyclingT;
        if (MinCy < (*i)->cyclingT || MinCy == -1) MinCy = (*i)->cyclingT;
    }

    AverWait = Twait / Tprocess;
    AverResp = TResp / Tprocess;
    AverCy = TCy / Tprocess;

}


void scheduling::simulation(){
    if      (algorithm == _FCFS) FCFS();
    else if (algorithm == _SRT)  SRT();
    else if (algorithm == _SJF)  SJF();
    else if (algorithm == _HRRN) HRRN();
    else if (algorithm == _RR)   RR();
}


int scheduling::getWait(std::string name){
    if (name == "aver") return AverWait;
    if (name == "max")  return MaxWait;
    if (name == "min")  return  MinWait;
    return -1;
}

int scheduling::getRes(std::string name){
    if (name == "aver") return AverResp;
    if (name == "max")  return MaxResp;
    if (name == "min")  return  MinResp;
    return -1;
}

int scheduling::getCy(std::string name){
    if (name == "aver") return AverCy;
    if (name == "max")  return MaxCy;
    if (name == "min")  return  MinCy;
    return -1;
}

vector<task*> scheduling::getExeQ(){
    return exeQ;
}

vector<task*> scheduling::getPqueue(){
    sort(pqueue.begin(), pqueue.end(), cmpPID);
    return pqueue;
}

void scheduling::setCondition(int index, std::vector<int> bq, std::vector<int> aq, std::vector<int> pq, int sliceT=4){
    algorithm = (schedulingAlgos) index;
    if (algorithm == _RR) slice = sliceT;

    for (size_t i=0; i<bq.size(); i++){
        task * process = new task;
        process->pid = i+1;
        process->timeRemain = bq[i];
        process->arrivaltime = aq[i];
        process->priority = pq[i];
        enqueue(pqueue, process);
    }
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
        a->pid = i+1;
        a->timeRemain = timeDuration[i];
        a->arrivaltime = arrivalt[i];
        a->priority = priority[i];
        enqueue(pqueue, a);
    }
}

void scheduling::check(){
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


