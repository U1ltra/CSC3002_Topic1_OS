
/*
 * File: cpuMon.cpp
 * ----------------
 * This file implements the cpu monitor class.
 */

#include "cpuMon.h"
#include <ctime>
#include <thread>
#include <random>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


const int REFRESHING_SLICE = 2;
const int kernel_pid = 0;
const int launchd_pid = 1;
const int window_pid = 2;
const int INITIAL_CPUT = 0;
const int INITIAL_THREAD = 0;
const int INITIAL_IDLE = 0;
const double INITIAL_CPUPER = .1;


process::process(){
    pid = cpuT = cpuPer = 0;
    thread = idle_wake = 0;
    name = "none";
    psion = user;
}

process::process(string Pname, permission per,
                 int id, int cpu_t, int threadN, int idle, double cpu_p){
    name = Pname;
    psion = per;
    pid = id;
    thread = threadN;
    cpuT = cpu_t;
    cpuPer = cpu_p;
    idle_wake = idle;
}

cpuMon::cpuMon(){
    TThread = 0;
    cputemp = 26;           // normal temperature
    operation = false;
    TcpuPercentage = 0;
    mostRecent = new int(3);
    for (int i=0; i<3; i++){
        mostRecent[i] = 0;
    }
    createKernelT();
    createLaunchd();
    createWindowT();
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
    createP(window_pid, "window_server", root);
}

void cpuMon::createLaunchd(){
    createP(launchd_pid, "launchd", root);
}

void cpuMon::createP(int pid, std::string name, permission per){
    process * P = new process(name, per, pid,
                              INITIAL_CPUT, INITIAL_THREAD, INITIAL_IDLE, INITIAL_CPUPER);
    processes.push_back(P);
}

void cpuMon::terminateP(int pid){
    for (vector<process*>::iterator i=processes.begin(); i<processes.end(); i++){
        if ((*i)->pid==pid){
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
    mostRecent[2] = P->pid;
}

void cpuMon::Tstatistics(){
    TcpuPercentage = TThread = 0;
    for (vector<process*>::iterator i=processes.begin(); i<processes.end(); i++){
        TcpuPercentage = TcpuPercentage + (*i)->cpuPer;
        TThread = TThread + (*i)->thread;
    }
}

void cpuMon::operationDet(int pid, opType op){
    if (op == fluctuation) operation = false;
    else                   operation = true;

    vector<process*>::iterator it;
    it = processes.begin();
    while (it != processes.end()){
        if ((*it)->pid==pid){
            CPUT((*it), op);
            Thread((*it), op);
            break;
        }
    }
}

void cpuMon::fluctuate(){                       // OS gradually goes into idle mode
    if (operation){                             // freshing does not equal to fluctuate

    }
}

void cpuMon::kernel_task(opType op){
    static bool initial=true;
    if (initial){
        processes[0]->thread = 70;
        initial = false;
    }
    srand((int) time(NULL));
    double periodCPUT;
    switch (op) {
        case simpleClick: case movingAround: case fluctuation:
            periodCPUT =
            processes[0]->cpuT = processes[0]->cpuT-0.02;
            processes[0]->thread = processes[0]->thread-2;
            if (processes[0]->cpuT<0.02) processes[0]->cpuT = 0.02+rand()%3 / double(500);
            if (processes[0]->thread<70) processes[0]->thread = 70+rand()%9-4;
            break;
        case effectClick:                                   // assuming the user will not consistently click effectively
            processes[0]->cpuT = processes[0]->cpuT+0.1;
            processes[0]->cpuPer = processes[0]->cpuT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+10;
            break;
        case refreshing:
            if (processes[0]->cpuT>.8) {
                processes[0]->cpuT = processes[0]->cpuT-0.01;
                processes[0]->cpuPer = processes[0]->cpuT/REFRESHING_SLICE;
            }
            processes[0]->cpuT = processes[0]->cpuT+0.03;
            processes[0]->cpuPer = processes[0]->cpuT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+rand()%5-2;
            break;
        case calculation:
            processes[0]->cpuT = processes[0]->cpuT+0.01;
            processes[0]->cpuPer = processes[0]->cpuT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+rand()%5-2;
            break;
        case textIn:
            processes[0]->cpuT = processes[0]->cpuT+0.01;
            if (processes[0]->cpuT>.5) processes[0]->cpuT = .3+rand()%4 / double(10);
            processes[0]->cpuPer = processes[0]->cpuT/REFRESHING_SLICE;
            break;
        case fileMan:
            processes[0]->cpuT = processes[0]->cpuT+0.1;
            processes[0]->cpuPer = processes[0]->cpuT/REFRESHING_SLICE;
            processes[0]->thread = processes[0]->thread+5;
            break;
    }
}

void cpuMon::window_server(opType op){
    srand((int) time(NULL));
    double periodCPUT;
    switch (op) {
        case simpleClick: case calculation:
        case textIn:      case fluctuation:
            periodCPUT = (100+rand()%100)/double(1000);
            processes[2]->cpuT = processes[2]->cpuT+periodCPUT;
            processes[2]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[2]->thread = rand()%10+5;
            break;
        case effectClick: case fileMan:
            periodCPUT = (300+rand()%100)/double(1000);
            processes[2]->cpuT = processes[2]->cpuT+periodCPUT;
            processes[2]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[2]->thread = 7+rand()%5;
            break;
        case movingAround: case refreshing:
            periodCPUT = (600+rand()%100)/double(1000);
            processes[2]->cpuT = processes[2]->cpuT+periodCPUT;
            processes[2]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[2]->thread = 10+rand()%10;
            break;
    }
}

void cpuMon::launchd(opType op){
    srand((int) time(NULL));
    double periodCPUT;
    switch (op) {
        case simpleClick: case movingAround:
        case refreshing:  case calculation:
        case textIn:      case fileMan:
        case fluctuation:
            periodCPUT = (rand()%50)/double(10000);
            processes[1]->cpuT = processes[1]->cpuT+periodCPUT;
            processes[1]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[1]->thread = rand()%10;
            if (processes[1]->thread<3) processes[1]->thread=3;
            break;
        case effectClick:
            periodCPUT = 0.2;
            processes[1]->cpuT = processes[1]->cpuT+periodCPUT;
            processes[1]->cpuPer = periodCPUT/REFRESHING_SLICE;
            processes[1]->thread = processes[1]->thread+4;
            break;
    }
}

void cpuMon::CPUT(process * & P, opType op){
    srand((int) time(NULL));
    switch (op) {
        case simpleClick:
            if (P->cpuT>.1) return;
            P->cpuT = P->cpuT + rand()%5 / double(1000);
            break;
        case effectClick:
            if (P->cpuT>.2) return;
            P->cpuT = P->cpuT + rand()%10 / double(1000);
            break;
        case movingAround:                  // for simple moving, only windows server will react
            break;
        case refreshing:
            if (P->cpuT>.4) return;
            P->cpuT = P->cpuT + rand()%30 / double(1000);
            break;
        case calculation:
            if (P->cpuT>.2) return;
            P->cpuT = P->cpuT + rand()%15 / double(1000);
            break;
        case textIn:
            if (P->cpuT>.2) return;
            P->cpuT = P->cpuT + rand()%5 / double(1000);
            break;
        case fileMan:
            if (P->cpuT>.3) return;
            P->cpuT = P->cpuT + rand()%20 / double(1000);
            break;
        case fluctuation:                   // leave for fluctuation function
            break;
    }

    P->cpuPer = P->cpuT / REFRESHING_SLICE;
}

void cpuMon::Thread(process * & P, opType op){
    srand((int) time(NULL));
    switch (op) {
        case simpleClick: case movingAround: case fluctuation:
            break;
        case effectClick:
            if (P->thread>10) return;
            P->thread = P->thread + rand()%5;
            break;
        case refreshing:
            P->thread = P->thread + rand()%7 - 3;
            break;
        case calculation:
            P->thread = P->thread + rand()%5 - 2;
            break;
        case textIn:
            P->thread = P->thread + rand()%3 - 1;
            break;
        case fileMan:
            P->thread = P->thread + rand()%5 - 2;
            break;
    }
}

void cpuMon::inactiveP(process * active){
    srand((int) time(NULL));
    vector<process*>::iterator it = processes.begin();
    while (it < processes.end()){
        if ((*it)!=active){
            (*it)->cpuT = (*it)->cpuT - rand()%20 / double(1000);
            (*it)->thread = (*it)->thread - rand()%3;
            if ((*it)->cpuT<0) (*it)->cpuT=0;
            if ((*it)->thread<0) (*it)->thread=0;
            (*it)->cpuPer = (*it)->cpuT / REFRESHING_SLICE;
        }
    }
}


//void cpuMon::IDLE(process * P, opType op){
//    switch (op) {
//        case simpleClick:
//            break;
//        case effectClick:
//            break;
//        case movingAround:
//            break;
//        case refreshing:
//            break;
//        case calculation:
//            break;
//        case textIn:
//            break;
//        case fileMan:
//            break;
//        case fluctuation:
//            break;
//    }
//}



