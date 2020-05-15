
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

    // constructors //
    scheduling();
    scheduling(const scheduling &) = default;   // default for now

    // destructor //
    ~scheduling() = default;                    // release memory on heap -- later when dynamic array become the implementation of BST, for now just simply use vector //


    /*
     * set the tasks and their attributes to be scheduled, according
     * to the algorithm selected.
     */
    void setCondition(int, std::vector<int>, std::vector<int>, std::vector<int>);

    /*
     * draw ganttchart
     */
    void gantt();

    /*
     * this is just a simple test function used to check the correctness of private field
     */
    void test();

    /////////////////////////////
    /// Scheduling Algorithms ///
    /////////////////////////////

    /*
     * Following algorithms functions will generate a execution queue which
     * demonstrates the whole execution duration of processes of the given
     * condition.
     */

    // First-Come First-Served Scheduling //
    int FCFS();

    // Shortest-Job First Scheduling //
    int SJF();

    // Shortest-Remaining Time Scheduling //
    int SRT();

    // Highest-Response Ratio Next Scheduling //
    int HRRN();

    // Round_Robin Scheduling //
    int RR();

    // Multipule-Feedback Queque Scheduling //
    int MFQ();

    // Fair-Sharing Scheduling //
    int FSS();


private:


    // structure of a individual task/process created //

    struct task{
        std::string taskName;
        int pid;                // identity of tasks, which is according to the creating order of the task. basically is just for reference
        int timeRemain;         // time needed for the task to finish running
        int priority;           // priority of different tasks

        int arrivaltime;        // determine the time of arrival of the given task, which will affect the remaining time of other tasks
//        int arrivalq;           // indicates the order of arrival of tasks, not considering the specific time of arrival. used for FCFS

        int waitT;
        int cyclingT;
        int responseT;

        bool IO;                // whether the task used I/O devices
        int CPUT;               // cpu time
        int IOT;                // I/O time


        /*
         * Constructor: task
         * -----------------
         * This function initializes a task object.
         * By default <code>pid</code> negavtive number indicates
         * that this is a null task, meaning a blank period.
         */
        task();
        task(int, int, int);
        task(task &) = default;
        ~task() = default;

    };


    // simulation info //

    int Tprocess;               // total number of tasks/processes
    schedulingAlgos algorithm;  // selected scheduling algorithm
    std::vector<task*> pqueue;  // contain all tasks
    std::vector<task*> exeQ;    // in the order of execution        // maybe not necessary

    // user experience determinants //
    int Twait;                  // total waiting time - not necessary
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


    // use a heap data structure to maintain the order of the task queue
    // call cmp when need to compare task attributesd individually -- readability
    // return whether task a has higher priority compared to task b
    static bool cmpArrivalq(task *, task *);                    // static since going to be used by <code>sort</code> func, has to be generalized static func
    static bool cmpRemain(task *, task *);
    static bool cmpArrivalt(task *, task *);
    static bool cmpPriority(task *, task *);
    static bool cmpwaitT(task *, task *);
    bool comparision(task *, task *);                           // will make use of schedule object attribute <code>algorithm</code>, therefore cannot be static



    /*
     * Determine scheduling algo to be used
     */
    void selectAlgo();

    /*
     * This function is used to get conditions inside terminal interaction.
     * however, for now it is used to obtain the main attributes ### remember to delete ###
     * part of the work of this function should be moved to set conditions.
     */
    void getCondition();

    /*
     * Sort the pqueue in to partially ordered tree according to priority.
     * return true any switch happened.
     */
    bool sortQueue(std::vector<task *> &);

    /*
     * Enqueue tasks while keeping the partial ordered tree structure           // revise to self defined array class later
     */
    void enqueue(std::vector<task *> &, task * &);

    /*
     * Average Waiting Time Calculation
     */
    int avgWaitingT();

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



#endif // SCHEDULING_ALGO_H
