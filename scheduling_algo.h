
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
enum schedulingAlgos {_FCFS, _SJF, _SPN, _SRT, _HRRN, _RR, _MFQ, _FSS};

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
    ~scheduling() = default;                // release memory on heap -- later when dynamic array become the implementation of BST, for now just simply use vector //

    /*
     * determine scheduling algo to be used
     */
    void selectAlgo();

    /*
     * set the tasks and their attributes to be scheduled, according
     * to the algorithm selected.
     */
    void setFCFS();                         // maybe i should condition them inside one <code>set</code> instead //
    void setSJF();                          // leave it for now //
    void setSPN();
    void setSRT();
    void setHRRN();
    void setRR();
    void setMFQ();
    void setFSS();


    /*
     * draw ganttchart
     */
    void gantt();


    /////////////////////////////
    /// Scheduling Algorithms ///
    /////////////////////////////

    // First-Come First-Served Scheduling //
    int FCFS();

    // Shortest-Job First Scheduling //
    int SJF();

    // Shortest-Process Next Scheduling //
    int SPN();

    // Shortest- Remaining Time Scheduling //
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
        int arrivalq;           // indicates the order of arrival of tasks, not considering the specific time of arrival. used for FCFS

        int waitT;
        int cyclingT;
        int responseT;

        bool IO;                // whether the task used I/O devices
        int CPUT;               // cpu time
        int IOT;                // I/O time
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
    bool cmpArrivalq(task *, task *);
    bool cmpRemain(task *, task *);
    bool cmpArrivalt(task *, task *);
    bool cmpPriority(task *, task *);
    bool cmpwaitT(task *, task *);

    bool comparision(task *, task *);


    /*
     * sort the pqueue in to partially ordered tree according to priority
     */
    void sortQueue();

    /*
     * enqueue tasks while keep the partial ordered tree structure
     */
    void enqueue(task*);

    /*
     * Average Waiting Time Calculation
     */
    int avgWaitingT();

    /*
     * calculate efficiency determinants based on execution queue generated
     * by the selected scheduling algorithm
     */
    void efficiency();

    /*
     * illegalize copying
     */
    scheduling & operator=(const scheduling &);
};



#endif // SCHEDULING_ALGO_H
