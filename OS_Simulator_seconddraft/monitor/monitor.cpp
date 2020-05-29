
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
#include <iostream>

const QFont TITLE_FONT = QFont("Helvatica", 25);
const QString TITLE = QWidget::tr("Activity Monitor");
const QString CPUT = QWidget::tr("CPU");
const QString MEMT = QWidget::tr("MEM");

monitor::monitor(cpuMon * cpu, Buddy * bd, QMainWindow *parent) :
    QWidget(parent)
{
    CPU = cpu;
    BD = bd;
    std::cout << "memory process list in the first layer >>> " << BD->Bu_map.size() << endl;

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
    cpuM->set_CPU(cpu);
    memM->set_CPU(cpu);
}


void monitor::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else {
        created = true;
    }
    cpuM->set_memory(memory);
    memM->set_memory(memory);
}

