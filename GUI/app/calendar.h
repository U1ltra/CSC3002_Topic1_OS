#ifndef CALENDAR_H
#define CALENDAR_H


#include <QAbstractItemModel>
#include <QCalendarWidget>
#include <QTimer>
#include "monitor/cpuMon.h"
class Calendar : public QCalendarWidget
{
    Q_OBJECT

public:
     Calendar();
     void setPID(int pid);
     void set_CPU(cpuMon*);
    ~Calendar();

private:
     QTimer *system_timer;
     int PID;
     cpuMon* CPU;

private slots:
    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // CALENDAR_H
