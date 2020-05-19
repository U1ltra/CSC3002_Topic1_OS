
/*
 * File: schedule_algo.h
 * ---------------------
 * This file exports a sheduling simulation class where several traditional
 * task scheduling algorithms are defined.
 */

#ifndef SCHEDULING_ALGO_H
#define SCHEDULING_ALGO_H

#include <string>
#include <vector>                           // use vector for now -- remember to revise to dynamic array


/*
 * Type: schedulingAlgos
 * ---------------------
 * This type respresents the eight scheduling algorithms.
 */
enum schedulingAlgos {_FCFS, _SRT, _SJF, _HRRN, _RR, _MFQ, _FSS};

/*
 * Class: scheduling
 * -----------------
 * This class models a specific period of task scheduling algorithms
 * of the operating system. Pros and cons of different scheduling
 * algorithms could be revealed by comparing obtained efficiency
 * determinants from the simulation.
 */
class scheduling{
public:

    /*
     * Initialize the private data
     */
    scheduling();
    scheduling(const scheduling &) = default;

    /*
     * Release <code>task</code> object created on heap
     */
    ~scheduling();


    // function for widget-based interation //

    /*
     * Set the tasks and their attributes to be scheduled, according
     * to the algorithm selected. This is the setting function interface
     * for data inputted from the GUI.
     */
    void setCondition(int, std::vector<int>, std::vector<int>, std::vector<int>, int);


    // functions for console-based interaction //

    /*
     * Determine scheduling algo to be used
     */
    void selectAlgo();

    /*
     * This function is used to get conditions inside terminal interaction.
     */
    void getCondition();

    /*
     * This is just a simple test function used to check the correctness of
     * private field in console
     */
    void check();


    /////////////////////////////
    /// Scheduling Algorithms ///
    /////////////////////////////

    /*
     * Following algorithms functions will generate a execution queue which
     * demonstrates the whole execution duration of processes of the given
     * condition.
     */

    /// First-Come First-Served Scheduling ///
    /*
     * Schedule solely according to the arrive sequence
     */
    int FCFS();

    /// Shortest-Job First Scheduling ///
    /*
     * Execute the job with shortest execution time in the list
     */
    int SJF();

    /// Shortest-Remaining Time Scheduling ///
    /*
     * Execute the process with the shortest remaining time in the queue.
     * allows race to control
     */
    int SRT();

    /// Highest-Response Ratio Next Scheduling ///
    /*
     * Calculate the response ratio everytime when CPU finishes one task
     */
    int HRRN();

    /// Round_Robin Scheduling ///
    /*
     * Preeptive method. Check the priority at the end of every specified
     * time slice.
     */
    int RR();

    /// Multipule-Feedback Queque Scheduling ///
    int MFQ();

    /// Fair-Sharing Scheduling ///
    int FSS();

    /*
     * Start the simulation
     */
    void simulation();

    /*
     * Get private data related to waiting time
     */
    int getWait(std::string);

    /*
     * Get private data related to response time
     */
    int getRes(std::string);

    /*
     * Get private data related to cycling time
     */
    int getCy(std::string);

    /*
     * Get execution queue
     */
    template<typename ValueType>
    ValueType getExeQ();


private:

    //////////////////////////
    /// private data field ///
    //////////////////////////

    // structure of a individual task/process created //

    struct task{                // PCB

        std::string taskName;
        int pid;                // identity of tasks, which is according to the creating order of the task. basically is just for reference
        int timeRemain;         // time needed for the task to finish running
        int arrivaltime;        // determine the time of arrival of the given task, which will affect the remaining time of other tasks
        double priority;        // priority of different tasks

        int waitT;
        int cyclingT;
        int responseT;

        bool IO;                // whether the task used I/O devices
        int CPUT;               // cpu time
        int IOT;                // I/O time


        /*
         * This function initializes a task object.
         * By default <code>pid</code> negavtive number indicates
         * that this is a null task, meaning a blank period.
         */
        task();

        /*
         * Assignment constructor for task
         */
        task(int, int, int);

        /*
         * Copying assignment
         */
        task(task &) = default;

        /*
         * Default since no on heap memory is allocated in constructor
         */
        ~task() = default;

    };


    // simulation info //

    int Tprocess;               // total number of tasks/processes
    int slice;                  // time slice for RR -- i need to tear different algorithms apart
    schedulingAlgos algorithm;  // selected scheduling algorithm
    std::vector<task*> pqueue;  // contain all tasks
    std::vector<task*> exeQ;    // in the order of execution        // maybe not necessary

    // user experience determinants //

    int Twait;                  // total waiting time
    int AverWait;               // averge waiting time
    int MaxWait;
    int MinWait;
    int TResp;                  // total response time
    int AverResp;
    int MaxResp;
    int MinResp;
    int TCy;                    // average cycling time
    int AverCy;
    int MaxCy;
    int MinCy;

    // system efficiency determinants //

    float CPU_rate;             // percentage of time when cpu is occupied
    int throughput;             // tasks finished per unit time



    ///////////////////////
    /// private methods ///
    ///////////////////////

    /*
     * Return whether task a has higher execution priority compared to task b.
     * Static since going to be used by <code>sort</code> func,has to be
     * generalized static func.
     */
    static bool cmpRemain(const task *, const task *);
    static bool cmpArrivalt(const task *, const task *);
    static bool cmpPriority(const task *, const task *);
    static bool cmpwaitT(const task *, const task *);

    /*
     * Select one of the <code>cmp</code> function to use, according to
     * the chosen slgorithm. This is not a static function since it has
     * to make use of <code>algorithm</code> private data.
     */
    bool comparision(const task *, const task *);

    /*
     * Sort the pqueue in to partially ordered tree according to priority.
     * return true any switch happened.
     */
    bool sortQueue(std::vector<task *> &);                                      // could change into form of iterator

    /*
     * Enqueue tasks while keeping the partial ordered tree structure           // revise to self defined array class later
     */
    void enqueue(std::vector<task *> &, task * &);

    /*
     * Calculate response ratio of every remaining tasks.
     * Used in HRRN.
     */
    void calPriority(std::vector<task *>::iterator, std::vector<task *>::iterator);

    /*
     * Calculate efficiency determinants based on execution queue generated
     * by the selected scheduling algorithm
     */
    void efficiency();

    /*
     * Deep copy for the process queue
     */
    std::vector<task *> Qcopy(const std::vector<task *> &);

    /*
     * illegalize copying
     */
    scheduling & operator=(const scheduling &);
};



template<typename ValueType>
ValueType scheduling::getExeQ(){
    return exeQ;
}


#endif // SCHEDULING_ALGO_H
