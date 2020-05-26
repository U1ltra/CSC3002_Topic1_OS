
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
     void setPID(int pid);
     void set_CPU(cpuMon*);
     void set_memory(Buddy* memory);
    ~Calendar() = default;

private:
     QTimer *system_timer;
     int PID;
     cpuMon* CPU;
     Buddy* memory;
     bool created = false;
     int memory_size = 1;

private slots:
    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *event);
};

#endif // CALENDAR_H
