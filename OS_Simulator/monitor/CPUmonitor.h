
/*
 * File: monitor.h
 * ---------------
 * This file exports the graphical interface of activity
 * monitor.
 */


#ifndef CPUMONITOR_H
#define CPUMONITOR_H


#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QTableView>
#include <QStandardItemModel>
#include "monitor/cpuMon.h"
#include "monitor/table_constr.h"
#include "memory/Buddy.h"

////namespace Ui {
////class monitor;
////}

class CPUmonitor : public QWidget
{
    Q_OBJECT

public:

    explicit CPUmonitor(cpuMon * cpu, QWidget *parent = nullptr);


    ~CPUmonitor();

    /*
     * Set the progem identity of this object, according to the code
     * given by the operating system (assuming our mainwindow module
     * plays the role of generating the PID for each created application
     * process)
     */
    void setPID(int pid);

    /*
     * Pass in the <code>cpuMon</code> created when initializing the
     * mainwindow, which exports functions to monitor the execution
     * of the process (monitor itself is also a process).
     */
    void set_CPU(cpuMon*);

    /*
     * Fill the table displaying the process attributes
     */
    void initTable();

    /*
     * Fill in the statistics displayed at the bottom of the monitor
     */
    void initBottom();

    /*
     * Fetch the statistics
     */
    void fillBotStatistics();

    /*
     * Update the statistics displayed on task monitor
     */
    friend void refresh(CPUmonitor *);

    /*
     * Pass in the memeory class in the System.
     */
    void set_memory(Buddy* memory);

private:
////    Ui::monitor *ui;

    int PID;                            // program identity of the object
    cpuMon * CPU;                       // <code>cpuMon</code> object used to simulate the resources usage
    QTableView * visualTable;           // view object used to visualize the data
    QStandardItemModel * tableModel;    // store the pointer to the constructed table
    stdTable * tableConstructor;        // object of class used to generate a pointer to a constructed table
//    bool newProcess;

    QLabel * SystemT;                   // text labels for indication of meanings of data in the monitor
    QLabel * UserT;
    QLabel * IdleT;
    QLabel * ThreadT;
    QLabel * ProcessT;
    QLabel * CPUTem;
//    QLabel * Title;
//    std::vector<QLabel> bottomLabels;

    QVBoxLayout * bottomLeft;
    QVBoxLayout * bottomRight;
    QHBoxLayout * bottomStack;
    QVBoxLayout * mainLayout;

    QTimer *system_timer;
    Buddy* memory;
    bool created = false;
    int memory_size=1;
    void sleeping();

private slots:
    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void _refreshing();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // CPUMONITOR_H
