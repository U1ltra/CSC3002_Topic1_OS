#ifndef SCHWIDGET_H
#define SCHWIDGET_H



#include <QWidget>
#include <vector>
#include <iostream>
#include <QPixmap>
#include <map>
#include <string>
#include <QDebug>
#include <string>
#include <vector>
#include <QThread>
#include "monitor/cpuMon.h"
#include "memory/Memwidget.h"
using namespace std;
namespace Ui {
    class SchWidget;
}





extern const int PID_BLANK;                    // pid for blank period
/*
 * Type: task
 * ----------
 * Structure of a individual task/process created
 */
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
     * Default since no on heap memory is allocated in constructor
     */
    ~task() = default;
};
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

    /*
     * Default copying constructor, since no on heap memory is used
     */
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
    std::vector<task*> getExeQ();

    /*
     * Get pqueue
     */
    std::vector<task*> getPqueue();


private:

    //////////////////////////
    /// private data field ///
    //////////////////////////


    // simulation info //
    friend class SchWidget;
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
    static bool cmpPID(const task *, const task *);

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
     * Shallow copy for the process queue
     */
    void SQcopy();

    /*
     * illegalize copying
     */
    scheduling & operator=(const scheduling &);
    /*
     *
     */
    friend class Widget;
};

class SchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SchWidget(QWidget *parent = 0);
    ~SchWidget();
    void initcolorvec();
    void inittable();
    void initgraph();
    int returnprocessnum();//临时
    void printcolor_map();//临时
    bool repetitiondetect(int i, vector<int> v);
    bool checkempyt(int,int,int);

    void set_CPU(cpuMon * cpu);
    void setPID(int pid);
    void set_memory(Buddy *Memory);

    //mythread *mythrd;
    //QThread *qthrd;
private slots:


    void on_spinBox_valueChanged(int arg1);

    void on_simulate_clicked();

    void on_clear_clicked();

    void on_comboBox_activated(const QString &arg1);

//    void getImage(QImage&);

//    void kill_thread(QObject*);

    void on_initialize_clicked();

    void on_timeslice_textEdited(const QString &arg1);


    void on_pause_clicked();

    void on_play_clicked();

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void refresh();


protected:
    bool eventFilter(QObject *watched, QEvent *event);
//    void timerEvent(QTimerEvent *event);
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *event);

private:
    Ui::SchWidget *ui;
    //颜色选择
    QColor color;
    map<string, QColor*> color_map;
    friend class scheduling;


    scheduling * s;
    QTimer * t;

    int flag;
    int algo_sign;
    int number_of_process;
    int timeslice;
    bool rept_flag;
    bool init_flag;
    bool clear_flag;
    int ptremained;
    bool allow_to_init;
    vector<int> bq;
    vector<int> pq;
    vector<int> aq;
    std::vector<task*> execQ;
    vector<int> graphlenvec;
    vector<QColor*> colorvec;

    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=200;
    void sleeping();
};
#endif // WIDGET_H
