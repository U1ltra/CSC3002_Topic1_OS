
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
            refreshing, calculation, textIn, fileMan,
            fluctuation};

/*
 * Type: process
 * -------------
 * This type represents a created process
 */
struct process{
    std::string name;
    permission psion;
    int pid;
    int thread;
    int idle_wake;
    double cpuT;
    double cpuPer;

    process();
    process(std::string, permission, int, int, int, int, double);
    ~process() = default;
};

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
    void createP(int pid, std::string name, permission per);

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
     * is conducted. This function makes use of <thread> lib so that
     * it can consistently running in the background to simulate
     * fluctuation of the statistics when no opeartion is given.
     */
    void fluctuate();                       // iterate through all processes and call update functions to simulate fluctuation
                                            // use clk inside operationDet to slow down the changing of <code>operation</code>
                                            // to simulate the periodical fluctuation
    /*
     * Return the process queue
     */
    std::vector<process*> getQ();

    /*
     * Return true if total cpu percentage surpasses 75%
     */
    bool isBusy();

    /*
     * Return total percentage of cpu usage
     */
    int TcpuPer();

    /*
     * Return total number of threads
     */
    int Tthread();

    /*
     * Return total number of processes
     */
    int Tprocess();

private:

    // private data field //

    int * mostRecent;
    int TcpuPercentage;
    int TThread;
    int cputemp;                        // cpu temperature
    bool operation;                     // indicate in current time slice, whether any operations happened
    std::vector<process*> processes;    // processes created and havenot terminated


    // private functions //

    /*
     * Update the <code>cpuT</code> of given process according to
     * the operation type
     */
    void CPUT(process* &, opType);

    /*
     * Update the <code>cpuPer</code> of gicen process considering
     * the specified operation
     */
    void CPUPer(process* &, opType);

    /*
     * Update the <code>thread</code> number of given thread considering
     * the operation type
     */
    void Thread(process* &, opType);

    /*
     * Update the <code>idle_wake</code> of given thread with regard
     * to the given operation type
     */
    void IDLE(process*, opType);

    /*
     * Simulate the resource usage behavior of kernel task
     */
    void kernel_task(opType);

    /*
     * Simulate the resource usage behavior of window_server
     */
    void window_server(opType);

    /*
     * Simulate the resource usage behavior of launchd
     */
    void launchd(opType);

    /*
     * Create kernel task with highest priority / <code>root</code>
     * permission.
     */
    void createKernelT();

    /*
     * Create window_server process which simulates the process to
     * maintaining the graphical interface in real operating system
     */
    void createWindowT();

    /*
     * Create launchd process which is the initial process created by
     * kernel.
     */
    void createLaunchd();

    /*
     * Lower the process statistics of processes other than the current
     * active process
     */
    void inactiveP(process *);

    /*
     * Adjuct the queue of most recent processes
     */
    void recentIn(process *);

    /*
     * Calculate the total statistics
     */
    void Tstatistics();

    /*
     * Disable copying constructor and copying assignment
     */
    cpuMon(const cpuMon &);
    cpuMon & operator=(const cpuMon &);
};


#endif // CPU_H
