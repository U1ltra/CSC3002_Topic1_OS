
/*
 * File: Memwidget.cpp
 * -------------------
 * This file implements the memory game.
 */

#include <unistd.h>
#include <random>
#include <string>
#include <math.h>
#include <QEvent>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include "memoryGame/Memwidget.h"

const QVariant PIDT = QVariant("PID");
const QVariant MEMS  = QVariant("Memory Size");
const QVariant COLOR = QVariant("Color");
const QString TITLE = QWidget::tr("Memory Allocator");
const QString START = QWidget::tr("Start");
const QString CLEAR = QWidget::tr("Clear");
const QString PROCESSN = QWidget::tr("Process Num: ");
const QString TMEM = QWidget::tr("Total Memory: ");
const QString ADDRTOP = QWidget::tr("Address: ");
const QString ADDRBOT = QWidget::tr("Address: ");
const QString TUSED = QWidget::tr("Total Used: ");
const QFont TITLEF = QFont("Helvatica", 25);
const QFont LABELF = QFont("Helvatica", 15);
int topAddr = 0;
int botAddr = 0;
int totUsed = 0;
int ROWN = 0;

Mem_widget::Mem_widget(QWidget *parent) :
    QWidget(parent)
{
    title = new QLabel;
    processN = new QLabel;
    TMem = new QLabel;
    AddrTop = new QLabel;
    AddrBot = new QLabel;
    TUsed = new QLabel;
    processEdit = new QLineEdit;
    MemEdit = new QLineEdit;

    start = new QPushButton;
    clear = new QPushButton;

    constructor = new stdTable;
    visualTable = new QTableView;
    visualMem = new QScrollArea;
    scrollContent = new QWidget;
    ground = new paintGround;

    mainLayout = new QVBoxLayout;
    playground = new QHBoxLayout;
    drawingArea = new QVBoxLayout;
    inputArea = new QVBoxLayout;
    processLayout = new QHBoxLayout;
    memoryLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;

    dirty = false;
    colors = new vector<int>;

    start->installEventFilter(this);
    clear->installEventFilter(this);
    processEdit->installEventFilter(this);
    MemEdit->installEventFilter(this);
    ground->installEventFilter(this);

    initLabels();
    initButtons();
    initTable();
    initScroll();
    initLayout();

    system_timer = new QTimer();                                // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
    connect(this,SIGNAL(closeEvent()),this,SLOT(shutdown()));
}

Mem_widget::~Mem_widget(){
    delete  title;
    delete processN;
    delete TMem;
    delete AddrTop;
    delete AddrBot;
    delete TUsed;

    delete constructor;
    delete visualTable;
    delete visualMem;
    delete scrollContent;
    delete ground;

    delete start;
    delete clear;

    delete mainLayout;
    delete playground;
    delete drawingArea;
    delete inputArea;
    delete processLayout;
    delete memoryLayout;
    delete buttonLayout;
}

void Mem_widget::initLabels(){
    title->setText(TITLE);
    title->setFont(TITLEF);
    title->setAlignment(Qt::AlignCenter);
    processN->setText(PROCESSN);
    TMem->setText(TMEM);
    AddrTop->setText(QString("%1 0x%2").arg(ADDRTOP).arg(QString::number(topAddr)));
    AddrBot->setText(QString("%1 0x%2").arg(ADDRBOT).arg(QString::number(botAddr)));
    TUsed->setText(QString("%1 %2").arg(TUSED).arg(totUsed));

    processN->setMaximumWidth(100);
    TMem->setMaximumWidth(100);
    processEdit->setMaximumWidth(100);
    MemEdit->setMaximumWidth(100);
    processEdit->setPlaceholderText(QString::number(0));
    MemEdit->setPlaceholderText(QString::number(0));

    processN->setBuddy(processEdit);
    TMem->setBuddy(MemEdit);
}

void Mem_widget::initButtons(){
    start->setText(START);
    clear->setText(CLEAR);
    start->setMaximumWidth(300);
    clear->setMaximumWidth(300);

}

void Mem_widget::initTable(){
    attributes = new std::vector<const QVariant>;
    attributes->push_back(PIDT);
    attributes->push_back(MEMS);
    attributes->push_back(COLOR);

    constructor->setTable(ROWN,3);
    constructor->setTitle(*attributes, *attributes);
    tableModel = constructor->getTable();
    visualTable->setModel(tableModel);
    visualTable->setColumnWidth(0,200);
    visualTable->setColumnWidth(1,200);
    visualTable->setColumnWidth(2,200);
}

void Mem_widget::initScroll(){
    visualMem->setWidget(ground);
    visualMem->setMaximumWidth(250);
    ground->resize(visualMem->size());
}

void Mem_widget::initLayout(){
    processLayout->addWidget(processN);
    processLayout->addWidget(processEdit);
    processLayout->setAlignment(Qt::AlignCenter);
    memoryLayout->addWidget(TMem);
    memoryLayout->addWidget(MemEdit);
    memoryLayout->setAlignment((Qt::AlignCenter));
    buttonLayout->addWidget(start);
    buttonLayout->addWidget(clear);
    inputArea->addWidget(visualTable);
    inputArea->addLayout(processLayout);
    inputArea->addLayout(memoryLayout);
    inputArea->addLayout(buttonLayout);

    drawingArea->addWidget(AddrTop);
    drawingArea->addWidget(visualMem);
    drawingArea->addWidget(AddrBot);
    drawingArea->addWidget(TUsed);

    playground->addLayout(drawingArea);
    playground->addLayout(inputArea);

    mainLayout->addWidget(title);
    mainLayout->addLayout(playground);
    mainLayout->setSpacing(20);

    this->setLayout(mainLayout);
}

void Mem_widget::initColor() {
    srand(((int) time(NULL)));
    for (int i=0; i<ROWN; i++) {
        colors->push_back(rand()%255);
        colors->push_back(rand()%255);
        colors->push_back(rand()%255);
    }
    constructor->setColor(2, colors);
    ground->setColors(colors);
    ground->setUsedPrt(TUsed);
    ground->switchStatus(true);

}

void Mem_widget::resizeEvent(QResizeEvent *event){

    ground->setSize(250, visualMem->height());              // pass in the new height whenever the window is resized
}

void Mem_widget::onClearClicked(){
    if (dirty) {
        ground->switchStatus(false);
        delete bd;
        dirty = false;
        AddrTop->setText(QString("%1 0x%2").arg(ADDRTOP).arg(0));
        AddrBot->setText(QString("%1 0x%2").arg(ADDRBOT).arg(0));
        TUsed->setText(QString("%1 %2").arg(TUSED).arg(0));

        processEdit->clear();
        MemEdit->clear();

        tableModel->setRowCount(0);
        visualTable->update();
        this->resize(this->width()-1, this->height()-1);
    }
}

void Mem_widget::onStartClicked(){
    if (processEdit->text() == QString::number(0) || processEdit->text() == QString("")){
        QMessageBox::warning(this, "Missing Input", "Please check your input");
        return;
    }
    if (MemEdit->text() == QString::number(0) || MemEdit->text() == QString("")){
        QMessageBox::warning(this, "Missing Input", "Please check your input");
        return;
    }

    Process = processEdit->text().toInt();
    ROWN = processEdit->text().toInt();
    Memory = MemEdit->text().toInt();
    bd = new Buddy(Memory);
    ground->setBD(bd);

    if (!tableFill()){
        QMessageBox::warning(this, "Missing Input", "Please check your input");
        dirty = true;
        return;
    }

    initColor();
    this->resize(this->width()+1, this->height()+1);
    dirty = true;
}

bool Mem_widget::tableFill(){
    int rowN = tableModel->rowCount();
    int colN = tableModel->columnCount();
    for (int i=0; i<rowN; i++){
        for (int j=0; j<2; j++){
            if (constructor->getData(i,j) == QString("")){
                QMessageBox::warning(this, "Missing Input", "Please check your input");

                return false;
            }
        }
        bool success;
        success = bd->mem_allocation(constructor->getData(i,0).toInt(), constructor->getData(i,1).toInt());
        if (!success) return false;
    }

    return true;
}

bool Mem_widget::eventFilter(QObject *watched, QEvent *event){
    if (watched == ground ) {

    }
    else if (watched == start && event->type() == QEvent::MouseButtonPress){
        onStartClicked();
    }
    else if (watched == clear && event->type() == QEvent::MouseButtonPress){
        onClearClicked();
    }
    else if (watched == processEdit && event->type() == QEvent::KeyRelease) {
        delete constructor;
        constructor = new stdTable();
        ROWN = processEdit->text().toInt();
        initTable();
        tableModel = constructor->getTable();
        visualTable->setModel(tableModel);

    }

}


void Mem_widget::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Mem_Widget",user);
}


void Mem_widget::setPID(int pid){
    PID=pid;
}

void Mem_widget::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void Mem_widget::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}


void Mem_widget::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void Mem_widget::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void Mem_widget::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void Mem_widget::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void Mem_widget::refresh(){
    CPU->operationDet(PID,refreshing);
    system_timer->start(100);
}

void Mem_widget::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void Mem_widget::closeEvent(QCloseEvent *event){
    if (created){
        memory->deallocate(PID,memory_size);
        while(!CPU->isFreeToClose(PID)){
            sleep(1);
        }
    }
    else {
        CPU->terminateP(PID);
    }
    event->accept();
}


void Mem_widget::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
        showNormal();
    }
}






