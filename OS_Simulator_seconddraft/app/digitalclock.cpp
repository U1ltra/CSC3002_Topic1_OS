#include "app/digitalclock.h"
#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
DigitalClock::DigitalClock(QMainWindow *parent) :
    QLCDNumber(parent)
{
    /* Set initial status for Calculator. */
    this->setDigitCount(25);
    this->setDecMode();
    this->setSegmentStyle(QLCDNumber::Flat);
    this->setStyleSheet("color: white; background-color: transparent;");
    this->resize(400,200);

    /* Update usage by detecting different oparetions.*/
    QTimer *clock_timer = new QTimer(this);
    clock_timer->setInterval(1000);
    connect(clock_timer,SIGNAL(timeout()),this,SLOT(ontimeout()));
    clock_timer->start();
}

/* Private Slots */

/* Setters */
void DigitalClock::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"DigitalClock",user);
}


void DigitalClock::setPID(int pid){
    PID=pid;
}


/*
 * Implementation notes: ontimeout
 * ----------------------------------------------------
 * Update Screen when clock_timer counts down.
 */

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
