#include "app/digitalclock.h"
#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
DigitalClock::DigitalClock():
    QLCDNumber()
{
    this->setDigitCount(25);
    this->setDecMode();
    this->setSegmentStyle(QLCDNumber::Flat);
    this->setStyleSheet("border: 1px solid green; color: green; background: silver;");
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

