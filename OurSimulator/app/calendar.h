
/*
 * File: calender.h
 * ----------------
 * This file exports a visualized calender module.
 */

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QTimer>
#include <QCloseEvent>
#include <QMainWindow>
#include <QCalendarWidget>
#include <QAbstractItemModel>
#include "monitor/cpuMon.h"
#include "memoryGame/Buddy.h"

class Calendar : public QCalendarWidget
{
    Q_OBJECT

public:
    Calendar(QMainWindow *parent = nullptr);
    ~Calendar() = default;

    void setPID(int pid);

    void set_CPU(cpuMon*);

    void set_memory(Buddy* memory);


private:
    QTimer *system_timer;
    int PID;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size = 100;

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
