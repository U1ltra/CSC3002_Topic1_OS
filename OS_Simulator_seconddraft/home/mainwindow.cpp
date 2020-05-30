
/*
 * File: mainwindow.cpp
 * --------------------
 * This file implements the mainwindow.h interface.
 */

#include <QStatusBar>
#include <QDebug>
#include <QToolButton>
#include <QMessageBox>
#include <unistd.h>
#include "home/mainwindow.h"
#include "ui_mainwindow.h"
#include "app/calculator.h"
#include "app/calendar.h"
#include "app/digitalclock.h"
#include "monitor/cpuMon.h"
#include "monitor/CPUmonitor.h"
#include "monitor/memMonitor.h"
#include "monitor/monitor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Window");
    mainwindow_layout();


    /* Create main mainwindow process */
    CPU = new cpuMon();
    fluctuate(*CPU);
    CPU->createP(PID,"MainWindow",root); //Default PID for mainwindow is 10.
    memory = new Buddy(1024);
    set_up_memory();
    setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);
    system_timer = new QTimer();
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation())); //Return to the fluctuation mode.


    /* Display the digital clock */
    clock_display = new DigitalClock();
    clock_display->setPID(11);           //Default PID for clock is 11.
    clock_display->set_CPU(CPU);
    clock_display->set_memory(memory);
    ui->clock_layout->addWidget(clock_display, Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Private Slots*/

/* Calulator, Calendar, FileSystem, TaskMonitor, TextEditor, Simulators */

void MainWindow::on_btn_calc_clicked()
{
    to_effect_Click();
    sleeping();
    cal = new Calculator();
    connect(this,SIGNAL(closing()),cal,SLOT(close()));
    cal->setPID(calculator_count*100000+100);
    cal->set_CPU(CPU);
    cal->set_memory(memory);
    calculator_count++;
}

void MainWindow::on_btn_Calendar_clicked()
{
    to_effect_Click();
    sleeping();
    calendar = new Calendar();
    connect(this,SIGNAL(closing()),calendar,SLOT(close()));
    calendar->setPID(calendar_count*100000+200);
    calendar->set_CPU(CPU);
    calendar->set_memory(memory);
    calendar_count++;
}

void MainWindow::on_btn_FileSystem_clicked()
{
    to_effect_Click();
    sleeping();
    vfm = new VisualFileManager(this);
    connect(this,SIGNAL(closing()),vfm,SLOT(close()));
    vfm->setPID(file_system_count*100000+300);
    vfm->set_CPU(CPU);
    vfm->set_memory(memory);
    file_system_count++;
}

void MainWindow::on_btn_TaskManager_clicked()
{
    to_effect_Click();
    sleeping();
    Monitor = new monitor(CPU, memory);
    connect(this,SIGNAL(closing()),Monitor,SLOT(close()));
    Monitor->setPID(monitor_count*100000+400);
    Monitor->set_CPU(CPU);
    Monitor->set_memory(memory);
    monitor_count++;
}

void MainWindow::on_btn_TextEditor_clicked()
{
    to_effect_Click();
    sleeping();
    text_editor = new TextEditor(this);
    connect(this,SIGNAL(closing()),text_editor,SLOT(close()));
    text_editor->setPID(text_editor_count*100000+500);
    text_editor->set_CPU(CPU);
    text_editor->set_memory(memory);
    text_editor_count++;
}

void MainWindow::on_btn_Memory_Simulator_clicked()
{
    to_effect_Click();
    sleeping();
    MemGame = new Mem_Widget();
    MemGame->setPID(memory_game_count*100000+600);
    MemGame->set_CPU(CPU);
    MemGame->showNormal();
    MemGame->set_memory(memory);
    memory_game_count++;
}

void MainWindow::on_btn_Schedule_Simulator_clicked()
{
    to_effect_Click();
    sleeping();
    SchGame = new SchWidget();
    SchGame->setPID(Schedule_game_count*100000+700);
    SchGame->set_CPU(CPU);
    SchGame->showNormal();
    SchGame->set_memory(memory);
    Schedule_game_count++;
}

/*
 * Implementation notes: on_actionShutdown_triggered
 * -------------------------------------------------
 * Terminate all the process and close all the windows.
 */

void MainWindow::on_actionShutdown_triggered()
{
    to_effect_Click();
    sleeping();
    close();
    //    if (cal->isVisible()) cal->close();
    //    if (calendar->isVisible()) calendar->close();
    //    if (vfm->isVisible()) vfm->close();
    //    if (text_editor->isVisible()) text_editor->close();
    //    if (Monitor->isVisible()) Monitor->close();
    //    if (MemGame->isVisible()) MemGame->close();
    //    if (SchGame->isVisible()) SchGame->close();
}

void MainWindow::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);  // Update usage when turning back to initial status.
}

/* Private Functions */

void MainWindow::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(200);
}

void MainWindow::to_simple_Click(){ 
    CPU->operationDet(PID,simpleClick);
    system_timer->start(200);
}

void MainWindow::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(200);
}

void MainWindow::set_up_memory(){
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
        showNormal();
    }
}

/*
 * Implementation notes: sleeping
 * ------------------------------
 * Check if the usage of CPU reaches 75%. If so, terminate the process.
 */

void MainWindow::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void MainWindow::mainwindow_layout() {
    // Set background
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/images/background.jpg")));
    this->setPalette(pal);

    //Set icon for applications
    ui->btn_FileSystem->setIconSize(QSize(64,64));
    ui->btn_FileSystem->setIcon(QIcon(":/images/FileSystem.png"));
    ui->btn_FileSystem->setText(QString::fromLocal8Bit("File System"));
    ui->btn_FileSystem->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_FileSystem->setStyleSheet("background-color:transparent");

    ui->btn_calc->setIconSize(QSize(64,64));
    ui->btn_calc->setIcon(QIcon(":/images/Calculator.png"));
    ui->btn_calc->setText(QString::fromLocal8Bit("Calculator"));
    ui->btn_calc->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_calc->setStyleSheet("background-color:transparent");

    ui->btn_Calendar->setIconSize(QSize(64,64));
    ui->btn_Calendar->setIcon(QIcon(":/images/Calendar.png"));
    ui->btn_Calendar->setText(QString::fromLocal8Bit("Calculator"));
    ui->btn_Calendar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_Calendar->setStyleSheet("background-color:transparent");

    ui->btn_TaskManager->setIconSize(QSize(64,64));
    ui->btn_TaskManager->setIcon(QIcon(":/images/TaskManager.png"));
    ui->btn_TaskManager->setText(QString::fromLocal8Bit("Task Manager"));
    ui->btn_TaskManager->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_TaskManager->setStyleSheet("background-color:transparent");

    ui->btn_TextEditor->setIconSize(QSize(64,64));
    ui->btn_TextEditor->setIcon(QIcon(":/images/TextEditor.png"));
    ui->btn_TextEditor->setText(QString::fromLocal8Bit("Text Editor"));
    ui->btn_TextEditor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_TextEditor->setStyleSheet("background-color:transparent");

    ui->btn_Memory_Simulator->setIconSize(QSize(64,64));
    ui->btn_Memory_Simulator->setIcon(QIcon(":/images/memory.png"));
    ui->btn_Memory_Simulator->setText(QString::fromLocal8Bit("Memory Simulator"));
    ui->btn_Memory_Simulator->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_Memory_Simulator->setStyleSheet("background-color:transparent");

    ui->btn_Schedule_Simulator->setIconSize(QSize(64,64));
    ui->btn_Schedule_Simulator->setIcon(QIcon(":/images/schedule.png"));
    ui->btn_Schedule_Simulator->setText(QString::fromLocal8Bit("Schedule Simulator"));
    ui->btn_Schedule_Simulator->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_Schedule_Simulator->setStyleSheet("background-color:transparent");

    //Set text color
    QPalette patlette;
    patlette.setColor(QPalette::ButtonText, Qt::white);
    ui->btn_FileSystem->setPalette(patlette);
    ui->btn_calc->setPalette(patlette);
    ui->btn_Calendar->setPalette(patlette);
    ui->btn_Memory_Simulator->setPalette(patlette);
    ui->btn_Schedule_Simulator->setPalette(patlette);
    ui->btn_TextEditor->setPalette(patlette);
    ui->btn_TaskManager->setPalette(patlette);
}

/* Protected */

void MainWindow::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
    sleeping();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (created){
        to_shutdown = QMessageBox::question(this,"System","Do you really want to shut down the system?",
                                            QMessageBox::Yes |QMessageBox::No,QMessageBox::No);
        if (to_shutdown==QMessageBox::Yes){
            CPU->shutDown();
            memory->deallocate(PID,memory_size);
            emit closing();
            while(!CPU->isFreeToClose(PID)){
                sleep(1);
            }
            event->accept();
        }else{
            event->ignore();
        }
    }else{
        CPU->terminateP(PID);
        memory->deallocate(PID, memory_size);
        event->accept();
    }
}

