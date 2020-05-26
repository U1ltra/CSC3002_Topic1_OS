
/*
 * File: monitor.cpp
 * -----------------
 * This file assembles CPU monitor and memory monitor into on
 * QWidget using tab widget.
 */

#include "monitor/monitor.h"
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <unistd.h>
const QFont TITLE_FONT = QFont("Helvatica", 25);
const QString TITLE = QWidget::tr("Activity Monitor");
const QString CPUT = QWidget::tr("CPU");
const QString MEMT = QWidget::tr("MEM");

monitor::monitor(cpuMon * cpu, Buddy * bd, QMainWindow *parent) :
    QWidget(parent)
{
    CPU = cpu;
    BD = bd;

    cpuM = new CPUmonitor(CPU);
    memM = new Memmonitor(BD, CPU);
    tabW = new QTabWidget;
    Title = new QLabel;
    mainLayout = new QVBoxLayout;

    tabW->addTab(cpuM, CPUT);
    tabW->addTab(memM, MEMT);
    Title->setText(TITLE);
    Title->setFont(TITLE_FONT);
    Title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(Title);
    mainLayout->addWidget(tabW);
    mainLayout->setSpacing(25);
    mainLayout->setContentsMargins(10,30,10,20);
    mainLayout->setAlignment(Qt::AlignCenter);      // not really useful
    this->setLayout(mainLayout);
    connect(tabW,SIGNAL(currentChanged()),this,SLOT(to_effect_Click()));

}

monitor::~monitor(){
    delete cpuM;
    delete memM;
    delete tabW;
    delete Title;
    delete mainLayout;
}

void monitor::setPID(int pid){
    PID = pid;
    cpuM->setPID(PID);
    memM->setPID(PID);
}

void monitor::set_CPU(cpuMon * cpu){
    CPU = cpu;
    CPU->createP(PID, "Activity Monitor", user);
}


void monitor::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->allocate(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else {
        created = true;
    }
}

void monitor::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void monitor::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void monitor::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void monitor::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}


void monitor::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void monitor::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void monitor::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}
