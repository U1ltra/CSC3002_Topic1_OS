


#include <iostream>
#include "cpuMon.h"
#include <stdlib.h>
#include <thread>

using namespace std;


/*
 * This is just a simple console test case.
 */
int main(){
    cpuMon a;
    a.createP(4, "demo", user);
    a.check();
    fluctuate(a);
    a.operationDet(4, refreshing);
    a.operationDet(4, refreshing);
    a.operationDet(4, refreshing);
    a.operationDet(4, fluctuation);
    this_thread::sleep_for(chrono::milliseconds(1000));
}

