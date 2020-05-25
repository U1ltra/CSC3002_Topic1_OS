
/*
 * File: monitor.cpp
 * -----------------
 * This file uses Qt libraries to implement the monitor widget.
 */

#include <iostream>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>                // maybe used to find a specific process
#include <QPushButton>
#include <QAbstractButton>
#include <chrono>
#include <thread>
#include "monitor/monitor.h"
#include "monitor/table_constr.h"
#include <unistd.h>
#include <QCloseEvent>
#include <QMessageBox>

const QFont NOM_FONT = QFont("Times New Roman", 16);
const QFont TITLE_FONT = QFont("Helvatica", 25);
const QVariant ATTRIBUTES = "ATTR";
const QString SYSTEMT = QWidget::tr("System: ");
const QString USERT = QWidget::tr("User: ");
const QString IDLET = QWidget::tr("Idle: ");
const QString THREADT = QWidget::tr("Thread: ");
const QString PROCESST = QWidget::tr("Process: ");
const QString CPUTEMPERATURE = QWidget::tr("CPU Temperature: ");
const QString TITLE = QWidget::tr("Activity Monitor");


monitor::monitor(cpuMon * cpu, QMainWindow *parent) :
    QWidget(parent)
{
    Title = new QLabel;
    Title->setText(TITLE);
    Title->setFont(TITLE_FONT);

    tableConstructor = new stdTable;
    tableModel = new QStandardItemModel;
    visualTable = new QTableView;

    CPU = cpu;
    initTable();

//    for (int i=0; i<tableConstructor->getColN(); i++){
//        for (int j; j<tableConstructor->getRowN(); j++){
//            tableModel->item(j,i)->setTextAlignment(Qt::AlignCenter);
//        }
//    }

    initBottom();


    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(Title);
    mainLayout->addWidget(visualTable);
    mainLayout->addLayout(bottomStack);
    mainLayout->setSpacing(20);
    mainLayout->setAlignment(Qt::AlignCenter);          // this line does not work, why?
    mainLayout->setContentsMargins(50,50,50,35);
//    mainLayout->addStretch();
    this->setWindowTitle(TITLE);
    this->setLayout(mainLayout);
    refresh(this);
    std::cout << "arrived ??? 7" << std::endl;
//    QTimer * monitorRefreshT = new QTimer(this);
//    connect(monitorRefreshT, SIGNAL(timeout()), this, SLOT(refreshing()));
//    monitorRefreshT->setInterval(1000);
//    monitorRefreshT->start();

    setMouseTracking(true);

    system_timer = new QTimer();  // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
    connect(this,SIGNAL(closeEvent()),this,SLOT(shutdown()));
    connect(visualTable,SIGNAL(clicked()),this,SLOT(to_effect_Click()));
}

monitor::~monitor()
{

    delete SystemT;
    delete UserT;
    delete IdleT;
    delete ThreadT;
    delete ProcessT;
    delete CPUTem;
    delete tableConstructor;
    delete tableModel;
    delete visualTable;
    delete bottomLeft;
    delete bottomRight;
    delete bottomStack;
    delete mainLayout;
}

void monitor::initTable(){
    tableConstructor->setTable(CPU->Tprocess(), CPU->TAttr());
    tableConstructor->setTitle(CPU->getAttributesQ(ATTRIBUTES), CPU->getAttributesQ(ATTRIBUTES));
    tableConstructor->cpuMon2table(CPU);
    tableModel = tableConstructor->getTable();
    visualTable->setModel(tableModel);                                  // this is the table view to be display
    visualTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    // no editing allowed
    visualTable->setFont(NOM_FONT);
    visualTable->setColumnWidth(0, 360);
    visualTable->setColumnWidth(1, 160);
    visualTable->setColumnWidth(2, 160);
    visualTable->setColumnWidth(3, 160);
    visualTable->setColumnWidth(4, 160);
    visualTable->setColumnWidth(5, 160);
    visualTable->setColumnWidth(6, 160);
}

void monitor::initBottom(){
//    QString sys = QString("%1   %2   %").arg(SYSTEMT).arg(QString::number(CPU->TsysPer()*100,'f', 2));
//    QString
    SystemT = new QLabel(this);
    UserT = new QLabel(this);
    IdleT = new QLabel(this);
    ThreadT = new QLabel(this);
    ProcessT = new QLabel(this);
    CPUTem = new QLabel(this);
    SystemT->setFont(NOM_FONT);
    UserT->setFont(NOM_FONT);
    IdleT->setFont(NOM_FONT);
    ThreadT->setFont(NOM_FONT);
    ProcessT->setFont(NOM_FONT);
    CPUTem->setFont(NOM_FONT);
    fillBotStatistics();


    bottomLeft = new QVBoxLayout();
    bottomRight = new QVBoxLayout;
    bottomLeft->addWidget(SystemT);
    bottomLeft->addWidget(UserT);
    bottomLeft->addWidget(IdleT);
    bottomRight->addWidget(ThreadT);
    bottomRight->addWidget(ProcessT);
    bottomRight->addWidget(CPUTem);
    bottomLeft->setSpacing(25);
    bottomRight->setSpacing(25);

    bottomStack = new QHBoxLayout;
    bottomStack->addLayout(bottomLeft);
    bottomStack->addLayout(bottomRight);
    bottomStack->setContentsMargins(30,30,30,30);
}

void monitor::fillBotStatistics(){
    const QString sys = QString("%1    %2   %").arg(SYSTEMT).arg(QString::number(CPU->TsysPer()*100,'f', 2));
    const QString use = QString("%1         %2   %").arg(USERT).arg(QString::number(CPU->TuserPer()*100,'f',2),2);
    const QString idl = QString("%1         %2   %").arg(IDLET).arg(QString::number(100*(1-CPU->TsysPer()-CPU->TuserPer()),'f',2),2);
    const QString thr = QString("%1   %2").arg(THREADT).arg(CPU->Tthread());
    const QString pro = QString("%1   %2").arg(PROCESST).arg(CPU->Tprocess());
    const QString CPT = QString("%1   %2").arg(CPUTEMPERATURE).arg(QString::number(CPU->currentTem(),'f',2));
    SystemT->setText(sys);
    UserT->setText(use);
    IdleT->setText(idl);
    ThreadT->setText(thr);
    ProcessT->setText(pro);
    CPUTem->setText(CPT);
}

void refresh(monitor * mon){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    mon->tableConstructor->cpuMon2table(mon->CPU);

//    mon->visualTable->setModel(mon->tableModel);
    mon->visualTable->reset();
    mon->visualTable->update();

    mon->fillBotStatistics();
    mon->SystemT->update();
    mon->UserT->update();
    mon->IdleT->update();
    mon->ThreadT->update();
    mon->ProcessT->update();
    mon->CPUTem->update();
    std::thread next(refresh, mon);
    next.detach();
}


void monitor::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"monitor",user);
}


void monitor::setPID(int pid){
    PID=pid;
}

void monitor::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void monitor::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
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

void monitor::_refreshing(){
    CPU->operationDet(PID,refreshing);
    system_timer->start(100);
}

void monitor::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void monitor::closeEvent(QCloseEvent *event){
    CPU->terminateP(PID);
    if (created){
    memory->deallocate(PID,memory_size);
    }
    event->accept();
}


void monitor::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->allocate(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
    }
}
