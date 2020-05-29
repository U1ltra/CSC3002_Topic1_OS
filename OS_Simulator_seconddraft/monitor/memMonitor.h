
/*
 * File: memMonitor.h
 * ------------------
 * This file exports a visualized memory allocation monitor.
 */

#ifndef MEMMONITOR_H
#define MEMMONITOR_H

#include <vector>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QTableView>
#include <QStandardItemModel>
#include "monitor/cpuMon.h"
#include "monitor/table_constr.h"
#include "memory/Buddy.h"


class Memmonitor : public QWidget
{
    Q_OBJECT

public:
    /*
     * Constructor: Memmonitor
     * Usage: Memmonitor(Buddy * bd, cpuMon *, QWidget *parent = nullptr)
     * ------------------------
     * Creates a Memmonitor object. Initializes the memory
     * monitor table and assign values into table.
     */
    explicit Memmonitor(Buddy * bd, cpuMon *, QWidget *parent = nullptr);
    ~Memmonitor();


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
    void set_CPU(cpuMon *);

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
    friend void refresh(Memmonitor *);

    /*
     * Pass in the memeory class in the System.
     */
    void set_memory(Buddy* memory);


private:

    int PID;                            // program identity of the object
    double memConsumePer;
    cpuMon * CPU;                       // <code>cpuMon</code> object used to simulate the resources usage
    QTableView * visualTable;           // view object used to visualize the data
    QStandardItemModel * tableModel;    // store the pointer to the constructed table
    stdTable * tableConstructor;        // object of class used to generate a pointer to a constructed table
    std::vector<const QVariant> attrNames;
    std::vector<const QVariant> Pnames;
    std::vector<const QVariant> PIDS;
    std::vector<const QVariant> real;
    std::vector<const QVariant> total;

    QLabel * memConsumption;
    QLabel * totalMem;

    QHBoxLayout * bottomLayout;
    QVBoxLayout * bottomLayoutV1;
    QVBoxLayout * bottomLayoutV2;
    QVBoxLayout * mainLayout;

    QTimer * system_timer;
    Buddy * memory;
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
    void closeEvent(QCloseEvent *event);

};

#endif // MEMMONITOR_H
