
#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QAbstractItemModel>
#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#include <QMainWindow>
#include "monitor/cpuMon.h"
#include "memory/Buddy.h"
class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
     DigitalClock(QMainWindow *parent = nullptr);
     void setPID(int pid);
     void set_CPU(cpuMon*);
     void set_memory(Buddy* memory);

private:
     int PID=11;                         /* The pid for created text editor process.            */
     QTimer clock_timer;
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

     void back_to_fluctuation();
     /*
      * Slot Function: ontimeout
      * ----------------------------------------------------
      * Update Screen when clock_timer counts down.
      */
     void ontimeout();
};

#endif // DIGITALCLOCK_H
