
#ifndef MONITOR_H
#define MONITOR_H

#include <QWidget>
#include <QTimer>
#include <QMainWindow>
#include <QTabWidget>
#include "memoryGame/Buddy.h"
#include "monitor/cpuMon.h"
#include "monitor/CPUmonitor.h"
#include "monitor/memMonitor.h"

class monitor : public QWidget
{
    Q_OBJECT

public:
    explicit monitor(cpuMon * cpu, Buddy * bd, QMainWindow *parent = nullptr);
    ~monitor();

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
     * Pass in the memeory class in the System.
     */
    void set_memory(Buddy* memory);


private:

    cpuMon * CPU;
    Buddy * BD;
    CPUmonitor * cpuM;
    Memmonitor * memM;
    QTabWidget * tabW;
    QLabel * Title;

    QVBoxLayout * mainLayout;

    int PID;
    QTimer * system_timer;
    Buddy * memory;
    bool created = false;
    int memory_size=175;
    void sleeping();
private slots:
    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void refresh();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *event);

    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MONITOR_H
