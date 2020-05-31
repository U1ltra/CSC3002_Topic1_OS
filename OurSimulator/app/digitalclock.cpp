
/*
 * File: digitalclock.cpp
 * ----------------------
 * This file creates a passing clock on the mainwindow.
 */

#include <QMessageBox>
#include "app/digitalclock.h"

DigitalClock::DigitalClock(QMainWindow *parent) :
    QLCDNumber(parent)
{
    this->setDigitCount(25);
    this->setDecMode();
    this->setSegmentStyle(QLCDNumber::Flat);
    this->setStyleSheet("color: white; background-color: transparent;");
    this->resize(400,200);
    QTimer *clock_timer = new QTimer(this);
    clock_timer->setInterval(1000);
    connect(clock_timer,SIGNAL(timeout()),this,SLOT(ontimeout()));
    clock_timer->start();
}


void DigitalClock::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"DigitalClock",user);
}


void DigitalClock::setPID(int pid){
    PID=pid;
}

void DigitalClock::ontimeout(){
    QDateTime datetime = QDateTime::currentDateTime();
    this->display(datetime.toString("yyyy-MM-dd HH:mm:ss"));
}

void DigitalClock::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}

void DigitalClock::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
    }
}
