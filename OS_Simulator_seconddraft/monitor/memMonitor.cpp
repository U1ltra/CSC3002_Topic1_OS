
/*
 * File: memMonitor.cpp
 * --------------------
 * This file
 */

#include <iostream>
#include <thread>
#include <vector>
#include <QTimer>
#include <QString>
#include <unistd.h>
#include "monitor/memMonitor.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <unistd.h>

const QFont NOM_FONT = QFont("Times New Roman", 16);
const QSize SIZE = QSize(500, 100);
const int COLUMNS = 4;
const QString MEMCONPERT = QWidget::tr("Memory Consumption Percentage: ");
const QString TOTALMEM = QWidget::tr("Total Memory: ");
const QVariant PNAME = "Process Name";
const QVariant PIDT = "PID";

Memmonitor::Memmonitor(Buddy * bd, cpuMon * cpu, QWidget *parent) :
    QWidget(parent)
{
    CPU = cpu;
    memory = bd;
    memConsumePer = 0;

    visualTable = new QTableView;
    tableModel = new QStandardItemModel;
    tableConstructor = new stdTable;

//    setPID(pid);
//    set_memory(bd);                                 // need pid at once since mem page does not refresh
    initTable();
//    setMouseTracking(true);
    bottomLayout = new QHBoxLayout;
    memConsumption = new QLabel;
    totalMem = new QLabel;
//    bottomLayoutV1 = new QVBoxLayout;
//    bottomLayoutV2 = new QVBoxLayout;
    initBottom();

//    bottomLayoutV->addLayout(bottomLayout);

    mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(memConsumption);
    mainLayout->addWidget(visualTable);
    mainLayout->addLayout(bottomLayout);
    mainLayout->setSpacing(30);
    mainLayout->setAlignment(Qt::AlignCenter);
//    mainLayout->setContentsMargins(0,0,0,20);
//    mainLayout->setSpacing(20);
//    mainLayout->setContentsMargins(50,50,50,35);
    this->setWindowTitle("Memory Monitor");
    this->setLayout(mainLayout);
    refresh(this);


    system_timer = new QTimer;
    system_timer->setSingleShot(true);
//    visualTable->viewport()->setMouseTracking(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
//    connect(this,SIGNAL(closeEvent()),this,SLOT(shutdown()));
}

Memmonitor::~Memmonitor()
{
    delete visualTable;
    delete tableModel;
    delete tableConstructor;

    delete memConsumption;
    delete totalMem;

    delete bottomLayout;

    delete mainLayout;

    delete system_timer;
}

void Memmonitor::initTable(){
    attrNames.push_back("Process Name");
    attrNames.push_back("PID");
    attrNames.push_back("Real Size");
    attrNames.push_back("Memory Size");
    tableConstructor->setTable(memory->Bu_map.size(), COLUMNS);
    cout << "table construction with row number >>> " << memory->Bu_map.size() << endl;
    tableConstructor->setTitle(attrNames, attrNames);


    vector<const QVariant> check = CPU->getAttributesQ(PNAME);
    vector<const QVariant> check2 = CPU->getAttributesQ(PIDT);

//    Pnames = CPU->getAttributesQ(PNAME);
//    cout << "heeeeeeeeeeeeeeeeeeeer" << endl;
    PIDS.clear();
    real.clear();
    total.clear();
    Pnames.clear();
    for (size_t i=0; i<check.size(); i++) {
        if (i>=3) {
            Pnames.push_back(check[i]);
//            PIDS.push_back(check2[1]);
        }
    }

    map<m_task,int> :: iterator it;
    it = memory->Bu_map.begin();
    while (it != memory->Bu_map.end()) {
        PIDS.push_back(it->first.PID);
        real.push_back(it->first.memory);
        total.push_back(it->second);
        memConsumePer = memConsumePer + it->second;
        it++;
    }


    tableConstructor->tableChange(0, Pnames);
    tableConstructor->tableChange(1, PIDS);
    tableConstructor->tableChange(2, real);
    tableConstructor->tableChange(3, total);

    tableModel = tableConstructor->getTable();

    visualTable->setModel(tableModel);
    visualTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    // no editing allowed
    visualTable->setColumnWidth(0, 400);
    visualTable->setColumnWidth(1, 200);
    visualTable->setColumnWidth(2, 200);
    visualTable->setColumnWidth(3, 200);

//    visualTable->resize(500, 500);
}

void Memmonitor::initBottom() {
    memConsumePer = memConsumePer / memory->getsize();

    const QString memCP = QString("%1   %2").arg(MEMCONPERT).arg(QString::number(memConsumePer, 'f', 2));
    const QString tot = QString("%1   %2").arg(TOTALMEM).arg(QString::number(memory->getsize()));
    memConsumption->setText(memCP);
    memConsumption->setFont(NOM_FONT);
    totalMem->setText(tot);
    totalMem->setFont(NOM_FONT);

    bottomLayout->addWidget(memConsumption);
    bottomLayout->addWidget(totalMem);
    bottomLayout->setContentsMargins(20,10,10,25);

}

void refresh(Memmonitor * memM) {
    std::this_thread::sleep_for(std::chrono::seconds(2));

    delete memM->tableConstructor;
    memM->tableConstructor = new stdTable;
    memM->initTable();
    memM->initBottom();
    memM->memConsumption->update();
    memM->totalMem->update();
    memM->visualTable->update();
    memM->visualTable->reset();
    cout << "MemMonitor refreshed !!!" << endl;
    std::thread next = std::thread(refresh, memM);
    next.detach();
}

void Memmonitor::setPID(int pid){
    PID = pid;
}

void  Memmonitor::set_CPU(cpuMon * cpu){
    CPU = cpu;
}

void Memmonitor::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void Memmonitor::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}


void Memmonitor::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void Memmonitor::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void Memmonitor::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void Memmonitor::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void Memmonitor::_refreshing(){
    CPU->operationDet(PID,refreshing);
    system_timer->start(100);
}

void Memmonitor::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}


void Memmonitor::set_memory(Buddy *Memory){
    memory = Memory;
}



