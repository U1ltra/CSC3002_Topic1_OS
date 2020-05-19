
/*
 * File: cpuMon.h
 * --------------
 * This file exports <code>cpuMon</code> class which simulates
 * the cpu usage monitoring of real operating system. The created
 * class object could interact with our constructed GUI by taking in
 * user's operation. Reasonable changes are then performed on activity
 * statistics.
 */

#ifndef CPU_H
#define CPU_H

#include <string>
#include <vector>



/*
 * Type: permission
 * ----------------
 * Used to represent two possible permission of a process.
 */
enum permission{root, user};

/*
 * Type: opType
 * ------------
 * Used to represent simlpe operations that may occur in our
 * simulator each should have different effect on resources
 * allocation
 */
enum opType{simpleClick, effectClick, movingAround,
            refreshing,calculation, textIn, fileMan,
            fluctuation};


/*
 * Class: cpuMon
 * -------------
 * This class provide simulated statistic information about
 * CPU allocation. By intercting with GUI module, this class
 * may output reasonable numbers to support task monitor
 * application, which illustrates what is happening inside
 * the operating system.
 */
class cpuMon{

public:

    /*
     * Intialize object
     */
    cpuMon();

    /*
     * Release process structures constructed on heap
     */
    ~cpuMon();

    /*
     * Create a process according the intruction given by GUI module
     */
    void createP(int pid, std::string name, permission);

    /*
     * Terminate or remove the process specified by <code>pid</code>
     */
    void terminateP(int pid);

    /*
     * Update the usage indicating statistics whenever the user is
     * performing operation on the GUI module. The amount of effect
     * is specially handled for different kinds of operation or
     * application being used.
     */
    void operationDet(int pid, opType);

    /*
     * Simulate the fluctuation of the statistics when no operation
     * is conducted.
     */
    void fluctuate();                   // iterate through all processes and call update functions to simulate fluctuation


private:

    // private data field //

    struct process{
        std::string name;
        permission psion;
        int pid;
        int cpuT;
        int thread;
        int idle_wake;
        double cpuPer;
    };

    int cputemp;                        // cpu temperature
    bool operation;                     // indicate in current time slice, whether any operations happened
    std::vector<process*> processes;    // processes created and havenot terminated


    // private functions //

    /*
     * Update the <code>cpuT</code> of given process according to
     * the operation type
     */
    void CPUT(process*, opType);

    /*
     * Update the <code>cpuPer</code> of gicen process considering
     * the specified operation
     */
    void CPUPer(process*, opType);

    /*
     * Update the <code>thread</code> number of given thread considering
     * the operation type
     */
    void Thread(process*, opType);

    /*
     * Update the <code>idle_wake</code> of given thread with regard
     * to the given operation type
     */
    void IDLE(process*, opType);


    /*
     * Disable copying constructor and copying assignment
     */
    cpuMon(const cpuMon &);
    cpuMon & operator=(const cpuMon &);


};

#endif // CPU_H
