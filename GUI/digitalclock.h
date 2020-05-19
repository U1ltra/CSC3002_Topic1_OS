
#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QAbstractItemModel>
#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#include "cpuMon.h"
class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
     DigitalClock();
     void setPID(int pid);
     void set_CPU(cpuMon*);


private:
     QTimer clock_timer;
     QTimer *system_timer;
     int PID;
     cpuMon* CPU;
private slots:
     void ontimeout();

    void back_to_fluctuation();
};

#endif // DIGITALCLOCK_H
