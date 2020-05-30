
/*
 * File: calender.h
 * ----------------
 * This file exports a visualized calender module.
 */

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QAbstractItemModel>
#include <QCalendarWidget>
#include <QTimer>
#include "monitor/cpuMon.h"
#include <QCloseEvent>
#include <QMainWindow>
#include "memory/Buddy.h"
class Calendar : public QCalendarWidget
{
    Q_OBJECT

public:
     Calendar(QMainWindow *parent = nullptr);

    ~Calendar() = default;

    /*
     * Function: setPID, set_CPU, set_memory
     * Usage: setPID(pid); set_CPU(couMon*); set_memory(Buddy* memory);
     * ----------------------------------------------------------------
     * Set pid for the corressponding created program process and assign pointers
     * which are linkd to CPU and memory.
     */
        void setPID(int pid);
        void set_CPU(cpuMon*);
        void set_memory(Buddy* memory);

private:
    int PID;                         /* The pid for created text editor process.            */
    QTimer *system_timer;            /* A timer to send signals to CPU to return to initial status.*/
    cpuMon* CPU;                     /* Assigned CPU for text editor.                       */
    Buddy* memory;                   /* Assigned memory for text editor.                    */
    bool created = false;            /* Turn true when memory are allocated to text editor. */
    int memory_size=100;             /* The memory size for text editor.                    */

private slots:

/* Private Functions */

/*
 * Slot Function: to_simple_Click, to effect_click,
 *                to_moving_around, back_to_fluctuation
 * ----------------------------------------------------
 * Update usage when corressponding operations are performed.
 */

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

protected:
    void mousePressEvent(QMouseEvent *e);     /* Dectect the oparation of simple(invalid) click.*/
    void mouseMoveEvent(QMouseEvent *e);      /* Dectect the oparation of moving around.        */
    void closeEvent(QCloseEvent *event);      /* Dectect the oparation of window closing.        */
};

#endif // CALENDAR_H
