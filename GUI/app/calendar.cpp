#include "app/calendar.h"
#include <QCalendarWidget>
#include <QMessageBox>
Calendar::Calendar():
    QCalendarWidget()
{
    setMouseTracking(true);

    system_timer = new QTimer();  // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
}

Calendar::~Calendar()
{   CPU->terminateP(PID);
}



void Calendar::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Calendar",user);
}


void Calendar::setPID(int pid){
    PID=pid;
}

void Calendar::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
    system_timer->start(100);
}

void Calendar::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
    system_timer->start(100);
}


void Calendar::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void Calendar::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void Calendar::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void Calendar::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void Calendar::closeEvent(QCloseEvent *event){
    CPU->terminateP(PID);
    if (created){
    memory->deallocate(PID,memory_size);
    }
    event->accept();
}

void Calendar::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->allocate(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
    }
}
