
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
     QTimer clock_timer;
     QTimer *system_timer;
     int PID=11;
     cpuMon* CPU;
     Buddy* memory;
     bool created = false;
     int memory_size=100;
private slots:
     void ontimeout();

     void back_to_fluctuation();
};

#endif // DIGITALCLOCK_H
