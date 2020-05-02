
/* File: scheduling_algo.h
 * -----------------------
 * This file simulates FCFS, SPN, SJF, SRT, HRRN, RR, MFQ,
 * FSS task scheduling algorithms
 */

#include "scheduling_algo.h"
#include "taskstuc.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<taskStuc> PROCESSES;

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





