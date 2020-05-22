
/*
 * File: cpuMon.cpp
 * ----------------
 * This file implements the cpu monitor class.
 */

#include "monitor/cpuMon.h"
#include <cmath>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <QDebug>
#include <QVariant>
#include <iostream>

using namespace std;


const int REFRESHING_SLICE = 2;
const int kernel_pid = 0;
const int launchd_pid = 1;
const int window_pid = 2;
const int INITIAL_IDLE = 5;
const int INITIAL_THREAD = 5;
const double INITIAL_CPUT = .2;
const double INITIAL_CPUPER = .1;
const QVariant PID = "PID";
const QVariant USER = "User";
const QVariant CPUPER = "CPU %";
const QVariant THREAD = "Thread";
const QVariant CPUTIME = "CPU Time";
const QVariant IDLEW = "Idle wake ups";
const QVariant PNAME = "Process Name";


process::process(){
    pid = cpuT = cpuPer = pre_cpuT = 0;
    thread = idle_wake = 0;
    name = "none";
    psion = user;
}

process::process(QVariant Pname, permission per,
                 int id, int threadN, int idle, double cpu_t, double cpu_p){
    name = Pname;
    psion = per;
    pid = id;
    thread = threadN;
    cpuT = pre_cpuT = cpu_t;
    cpuPer = cpu_p;
    idle_wake = idle;
}

cpuMon::cpuMon(){
    TThread = 0;
    cputemp = 26.5;               // normal temperature
    operation = false;
    TcpuPercentage = 0;
    mostRecent = new int(3);
    for (int i=0; i<3; i++){
        mostRecent[i] = 0;
    }

    name_of_attrs.push_back(PNAME);
    name_of_attrs.push_back(CPUTIME);
    name_of_attrs.push_back(CPUPER);
    name_of_attrs.push_back(THREAD);
    name_of_attrs.push_back(IDLEW);
    name_of_attrs.push_back(PID);
    name_of_attrs.push_back(USER);

    createKernelT();            // create three initial system process
    createLaunchd();
    createWindowT();
    kernel_task(fluctuation);   // and initialize them
    launchd(fluctuation);
    window_server(fluctuation);
    Tstatistics();
    CPUTem();
}

cpuMon::~cpuMon(){
    for (vector<process*>::iterator i=processes.begin(); i< processes.end(); i++){
        delete *i;
    }
    processes.clear();
}

void cpuMon::createKernelT(){
    createP(kernel_pid, "kernel_task", root);
}

void cpuMon::createWindowT(){
    createP(window_pid, "window_serve", root);
}

void cpuMon::createLaunchd(){
    createP(launchd_pid, "launchd", root);
}

void cpuMon::createP(int pid, QVariant name, permission per){
    process * P = new process(name, per, pid,
                              INITIAL_THREAD, INITIAL_IDLE, INITIAL_CPUT, INITIAL_CPUPER);
    processes.push_back(P);
}

void cpuMon::terminateP(int pid){
    for (vector<process*>::iterator i=processes.begin(); i<processes.end(); i++){
        if ((*i)->pid==pid){
            delete (*i);                        // avoid memory leak
            processes.erase(i);
            break;
        }
    }
}

bool cpuMon::isBusy(){
    return TcpuPercentage > .75;
}

int cpuMon::TcpuPer(){
    return TcpuPercentage;
}

int cpuMon::Tthread(){
    return TThread;
}

int cpuMon::Tprocess(){
    return processes.size();
}

vector<process*> cpuMon::getQ(){
    return processes;
}

void cpuMon::recentIn(process * P){
    mostRecent[2] = mostRecent[1];
    mostRecent[1] = mostRecent[0];
    mostRecent[0] = P->pid;
}

void cpuMon::Tstatistics(){
    TcpuPercentage = TThread = TIDLE = 0;
    for (vector<process*>::iterator i=processes.begin(); i<processes.end(); i++){
        TcpuPercentage = TcpuPercentage + (*i)->cpuPer;
        TThread = TThread + (*i)->thread;
        TIDLE = TIDLE + (*i)->idle_wake;
    }
    if (TcpuPercentage>1) TcpuPercentage=1;
}

void cpuMon::operationDet(int pid, opType op){  // whenever GUI detect a kind of operation, this is the function invoke the resource usage simulation
    if (op == fluctuation) {                    // control the consistent parallel thread <code>fluctuate</code> function
        operation = false;
        return;
    }
    else                   operation = true;

    vector<process*>::iterator it;
    it = processes.begin()+3;                   // the beginning three processes are root processes
    while (it != processes.end()){
        if ((*it)->pid==pid){
            operationMon((*it), op);            // update the operated process
            break;
        }
        it++;
    }
    kernel_task(op);                            // update root processes
    launchd(op);
    window_server(op);

//    cout << "hhhhhhhcrushed?" << endl;
    recentIn(*(it));                          // record the most recent processes
    inactiveP(*(it));                         // update processes that is not currently updated
    Tstatistics();                              // calculate statistics
    CPUTem();                                   // update cpu temperature
    check();
    cout << "op princt" << endl;
}

void cpuMon::kernel_task(opType op){
    srand(((int) time(NULL))+TThread+TIDLE);
    static bool initial=true;
    double periodCPUT;
    if (initial){
        cout << "init" << endl;
        processes[0]->cpuT = (100+rand()%150)/double(1000);             // 10%-12.5%
        processes[0]->cpuPer = processes[0]->cpuT/REFRESHING_SLICE;
        processes[0]->thread = 70;
        processes[0]->idle_wake = 100;
        initial = false;
    } else{

        if (cputemp>70) {                                               // when CPU is functioning in high temperature
            periodCPUT = (950+rand()%100)/double(1000);
            processes[0]->cpuT = processes[0]->cpuT+periodCPUT;         // kernel task will automatically rise and slow down the CPU usage
            processes[0]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[0]->thread = 70+rand()%20;
            processes[0]->idle_wake = 100+rand()%20;
            if (op==fluctuation) cputemp-=5;                            // when nothing is under execution, tem will decrease sharper
            cputemp-=2;                                                 // lower the temperature
            return;
        }
        switch (op) {
        case simpleClick: case movingAround: case fluctuation:          // as far as kernel is concern, these three are having little effect
            cout << "i'm here!!!!!!!!!!!!!" << endl;
            periodCPUT = (300+rand()%500) / double(10000);              // around 1.5-4% of the %CPU
            processes[0]->cpuT = processes[0]->cpuT+periodCPUT;
            processes[0]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+rand()%9-5;     // overall decreasing
            processes[0]->idle_wake = rand()%35+10;
            if (processes[0]->thread<40) processes[0]->thread = 40;
            break;

        case effectClick:                                               // assuming the user will not consistently click effectively
            periodCPUT = (200+rand()%200)/double(1000);                 // around 10%-20% of the %CPU
            processes[0]->cpuT = processes[0]->cpuT+periodCPUT;
            processes[0]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+10;
            processes[0]->idle_wake = 70+rand()%30;
            break;

        case refreshing: case fileMan:
            periodCPUT = (100+rand()%200)/double(1000);                 // around 5%-15% of the %CPU
            processes[0]->cpuT = processes[0]->cpuT+periodCPUT;
            processes[0]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+rand()%5-2;
            processes[0]->idle_wake = 60+rand()%20;
            if (processes[0]->thread<40) processes[0]->thread = 40;
            break;

        case calculation: case textIn:
            periodCPUT = (rand()%200)/double (1000);                    // around 0-10%
            processes[0]->cpuT = processes[0]->cpuT+periodCPUT;
            processes[0]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+rand()%7-3;
            processes[0]->idle_wake = 50 + rand()%10;
            if (processes[0]->thread<40) processes[0]->thread = 40;
            break;
        }
    }
}

void cpuMon::window_server(opType op){
    srand(((int) time(NULL))+TThread+TIDLE);
    static bool initial=true;
    if (initial){
        processes[2]->cpuT = (150+rand()%200)/double(1000);                 // 7.5%-17.5%
        processes[2]->cpuPer = processes[2]->cpuT/REFRESHING_SLICE;
        processes[2]->thread = 7+rand()%5;
        processes[2]->idle_wake = 30+rand()%20;
        initial=false;
    } else {
        double periodCPUT;
        switch (op) {
            case simpleClick: case calculation:
            case textIn:      case fluctuation:
                periodCPUT = (100+rand()%100)/double(1000);                 // around 5%-10%
                processes[2]->cpuT = processes[2]->cpuT+periodCPUT;
                processes[2]->cpuPer = periodCPUT/REFRESHING_SLICE;
                processes[2]->thread = rand()%10+5;
                processes[2]->idle_wake = rand()%15+10;
                break;

            case effectClick: case fileMan:                                 // most likely result in graphical changing
                periodCPUT = (200+rand()%100)/double(1000);                 // around 10%-15%
                processes[2]->cpuT = processes[2]->cpuT+periodCPUT;
                processes[2]->cpuPer = periodCPUT/REFRESHING_SLICE;
                processes[2]->thread = 7+rand()%5;
                processes[2]->idle_wake = 15+rand()%20;
                break;

            case movingAround: case refreshing:                             // graph in game case or refreshing cursor
                periodCPUT = (300+rand()%200)/double(1000);                 // around 20%-30%
                processes[2]->cpuT = processes[2]->cpuT+periodCPUT;
                processes[2]->cpuPer = periodCPUT/REFRESHING_SLICE;
                processes[2]->thread = 10+rand()%10;
                processes[2]->idle_wake = 30+rand()%40;
                break;
        }
    }
}

void cpuMon::launchd(opType op){                                            // launchd is an important initial process
    srand(((int) time(NULL))+TThread+TIDLE);                                // but usually has low cpu percentage
    static bool initial=true;
    if (initial){
        processes[1]->cpuT = (100+rand()%100)/double(10000);                // 0.5%-1%
        processes[1]->cpuPer = processes[1]->cpuT/REFRESHING_SLICE;
        processes[1]->thread = rand()%2+1;
        processes[1]->idle_wake = rand()%2;
    } else{
        double periodCPUT;
        switch (op) {
            case simpleClick: case movingAround:
            case refreshing:  case calculation:
            case textIn:      case fileMan:
            case fluctuation:
                periodCPUT = (10+rand()%100)/double(10000);                 // around 0-0.5%
                processes[1]->cpuT = processes[1]->cpuT+periodCPUT;
                processes[1]->cpuPer = periodCPUT/REFRESHING_SLICE;
                processes[1]->thread = 1+rand()%10;
                processes[1]->idle_wake = rand()%3;
                if (processes[1]->thread<3) processes[1]->thread=3;
                break;

            case effectClick:
                periodCPUT = (100+rand()%300)/double(10000);                // around 0.5%-2%
                processes[1]->cpuT = processes[1]->cpuT+periodCPUT;
                processes[1]->cpuPer = periodCPUT/REFRESHING_SLICE;
                processes[1]->thread = processes[1]->thread+4;
                processes[1]->idle_wake = rand()%3;
                break;
        }
    }
}

void cpuMon::operationMon(process * & P, opType op){                    // this function serves all processes created other than kernel_task,
    srand(((int) time(NULL))+TThread+TIDLE);                            // window_server, launchd. According to the operation enumeration passed
    double periodCPUT;                                                  // in, reasonable updates are performed on statistics of the give process
    switch (op) {
        case simpleClick: case movingAround:                            // during the three type of condition, current process attributes is low
//            periodCPUT = (200+rand()%200)/double(10000);                // around 1%-2%
//            P->cpuT = P->cpuT+periodCPUT;
//            P->cpuPer = periodCPUT/REFRESHING_SLICE;
//            P->thread = rand()%7+1;
//            P->idle_wake = rand()%2;
//            P->pre_cpuT = periodCPUT;
            break;

        case effectClick:
            periodCPUT = (200+rand()%200)/double(1000);                 // around 10%-20%
            P->cpuT = P->cpuT+periodCPUT;
            P->cpuPer = periodCPUT/REFRESHING_SLICE;
            P->thread = 10+rand()%10;
            P->idle_wake = rand()%5;
            P->pre_cpuT = periodCPUT;
            break;

        case refreshing:
            periodCPUT = (150+rand()%150)/double(1000);                 // around 7.5%-15%
            P->cpuT = P->cpuT+periodCPUT;
            P->cpuPer = periodCPUT/REFRESHING_SLICE;
            P->thread = 5+rand()%10;
            P->idle_wake = rand()%10;
            P->pre_cpuT = periodCPUT;
            break;

        case calculation:
            periodCPUT = (100+rand()%100)/double(1000);                 // around 5%-10%
            P->cpuT = P->cpuT+periodCPUT;
            P->cpuPer = periodCPUT/REFRESHING_SLICE;
            P->thread = rand()%5+1;
            P->idle_wake = rand()%3;
            P->pre_cpuT = periodCPUT;
            break;

        case textIn:
            periodCPUT = (rand()%150)/double(1000);                     // around 0-7.5%
            P->cpuT = P->cpuT+periodCPUT;
            P->cpuPer = periodCPUT/REFRESHING_SLICE;
            P->thread = rand()%3+1;
            P->idle_wake = rand()%3;
            P->pre_cpuT = periodCPUT;
            break;
        case fileMan:
            periodCPUT = (100+rand()%300)/double(1000);                 // around 5%-20%
            P->cpuT = P->cpuT+periodCPUT;
            P->cpuPer = periodCPUT/REFRESHING_SLICE;
            P->thread = rand()%10+1;
            P->idle_wake = rand()%5;
            P->pre_cpuT = periodCPUT;
            break;
        case fluctuation:                                               // left for <code>fluctuation to deal with
            break;
    }
}

void cpuMon::inactiveP(process * active){
    srand(((int) time(NULL))+TThread+TIDLE);
    double periodCPUT;
    vector<process*>::iterator it;
    it= processes.begin()+3;                                            // starts from the forth process which is not a root process
    while (it != processes.end()){
        if ((*it)!=active){
            periodCPUT = (*it)->pre_cpuT - rand()%20/double(1000);
            (*it)->thread = (*it)->thread - rand()%3;
            (*it)->idle_wake = rand()%2;

            if (periodCPUT<0) periodCPUT=0;                             // when period cpu time is less than 0, meaning the process is completely waiting
            if ((*it)->thread<=0) (*it)->thread=rand()%3+1;             // thread number can not be smaller than or equal to zero

            (*it)->cpuT = (*it)->cpuT+periodCPUT;                       // update the inactive process according to the period cpu time
            (*it)->cpuPer = periodCPUT / REFRESHING_SLICE;

            (*it)->pre_cpuT = periodCPUT;                               // record the cpu time of this peroid so that next peroid can further reduce
        }                                                               // the cpu time if the process will still be inactive
        it++;
    }
}

void cpuMon::CPUTem(){
    srand(((int) time(NULL))+TThread+TIDLE);
    if      (TcpuPercentage>.8) cputemp+=(200+rand()%300)/double(100);
    else if (TcpuPercentage>.6) cputemp+=(100+rand()%250)/double(100);
    else if (TcpuPercentage>.4) cputemp+=(rand()%200)/double(100);      // when 50% of real cpu time is used up, temperature goes up
    else if (TcpuPercentage>.2) cputemp-=(rand()%200)/double(100);
    else                        cputemp-=(rand()%1000)/double(1000);

    if (cputemp<25)             cputemp=(2600+rand()%100)/double(100);  // make sure the temperature is in reasonable range
    if (cputemp>75)             cputemp=(7300+rand()%200)/double(100);
}

void cpuMon::leisure(){
    process * nope = new process;

    inactiveP(nope);
    kernel_task(fluctuation);
    launchd(fluctuation);
    window_server(fluctuation);
    Tstatistics();
    CPUTem();
    delete nope;
}

void fluctuate(cpuMon & monitor){                               // OS gradually goes into idle mode

    if (!monitor.operation){                                    // freshing does not equal to fluctuate
        monitor.leisure();
        monitor.check();
        cout << "fl print" << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));           // call oneself again after the sleep, making this function a parallel thread
    thread next(ref(fluctuate), ref(monitor));                  // detach to allow the resources of this function been collected
    next.detach();

}

void cpuMon::check(){
    vector<process*>::iterator it;
    it = processes.begin();
    cout << "  Process name        cpuT         cpuPer       thread      idle_wake_up      permission" << endl;
    cout << "  ------------      --------      --------      ------      ------------      ----------" << endl;
    while (it!=processes.end()){
        cout << "                    " << left << fixed;
//        qDebug() << (*it)->name.toString() << ":     ";
        cout << setprecision(4);
        cout << setw(8) << (*it)->cpuT << "      ";
        cout << setw(7) << (*it)->cpuPer*100 << "%       ";
        cout << setw(6) << (*it)->thread << "         ";
        cout << setw(12) << (*it)->idle_wake << "     ";
        cout << setw(10) << (*it)->psion << endl;
        it++;
    }
    cout << "CPU Temperature: " << cputemp << endl;
    cout << "Total CPU percentage: " << TcpuPercentage*100 << "%" << endl;
    cout << "Total Threads: " << TThread << endl;
}


