
#include "home/mainwindow.h"
#include "ui_mainwindow.h"
#include "app/calculator.h"
#include "app/calendar.h"
#include <QStatusBar>
#include "app/digitalclock.h"
#include "monitor/cpuMon.h"
#include <QDebug>
#include <QToolButton>
#include "monitor/CPUmonitor.h"
#include "monitor/memMonitor.h"
#include "monitor/monitor.h"
#include <QMessageBox>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CPU = new cpuMon();
    fluctuate(*CPU);
    CPU->createP(PID,"MainWindow",root);//Default PID for mainwindow is 10.
    memory = new Buddy(10000);
    set_up_memory();

    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);
    clock_display = new DigitalClock(this);
    clock_display->setPID(11);//Default PID for clock is 11.
    clock_display->set_CPU(CPU);
    clock_display->set_memory(memory);
    stBar->addPermanentWidget(clock_display);

    this->setWindowTitle("Main Window");
    setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);

    system_timer = new QTimer();
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setStyleSheet("border-image:url(:/images/back.jpg);");
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/images/back.jpg")));
    this->setPalette(pal);
    //ui->btn_FileSystem->setIcon(QIcon(QPixmap(":/images/File.jpg")));
    ui->btn_FileSystem->setIconSize(QSize(32,32));
    //ui->btn_FileSystem->setFixedSize(256,256);
    ui->btn_FileSystem->setIcon(QIcon(":/image/File.jpg"));
    ui->btn_FileSystem->setText(QString::fromLocal8Bit("File System"));
    ui->btn_FileSystem->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btn_FileSystem->setStyleSheet("background-color:transparent");
    //ui->btn_calc->setStyleSheet("color:white");
    QPalette patlette;
    patlette.setColor(QPalette::ButtonText, Qt::white);  // 设置button 文本颜色红色
    ui->btn_FileSystem->setPalette(patlette);
    ui->btn_calc->setStyleSheet("color:white");
    ui->btn_Calendar->setStyleSheet("color:white");
    ui->btn_game->setStyleSheet("color:white");
    ui->btn_TextEditor->setStyleSheet("color:white");
    ui->btn_TaskManager->setStyleSheet("color:white");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_calc_clicked()
{
    to_effect_Click();
    sleeping();
    cal = new Calculator();
    cal->setPID(calculator_count*100000+100);
    cal->set_CPU(CPU);
    cal->set_memory(memory);
    calculator_count++;
    connect(this,SIGNAL(close()),cal,SLOT(close()));
    cal->show();
}

void MainWindow::on_btn_Calendar_clicked()
{
    to_effect_Click();
    sleeping();
    Calendar *calendar = new Calendar();
    calendar->setPID(calendar_count*100000+200);
    calendar->set_CPU(CPU);
    calendar->set_memory(memory);
    calendar_count++;
    connect(this,SIGNAL(close()),calendar,SLOT(close()));
    calendar->show();
}

void MainWindow::on_btn_FileSystem_clicked()
{
    to_effect_Click();
    sleeping();
    vfm = new VisualFileManager();
    vfm->setPID(file_system_count*100000+300);
    vfm->set_CPU(CPU);
    vfm->set_memory(memory);
    file_system_count++;
    connect(this,SIGNAL(close()),vfm,SLOT(close()));
    vfm->show();
//        taskMonitor = new CPUmonitor(CPU);
//        taskMonitor->setPID(task_monitor_count*100000+400);
//        taskMonitor->set_memory(memory);
//        task_monitor_count++;
//        taskMonitor->show();
}

void MainWindow::on_btn_TaskManager_clicked()
{
    to_effect_Click();
    sleeping();
//    taskMonitor = new CPUmonitor(CPU);
//    taskMonitor->setPID(task_monitor_count*100000+400);
//    taskMonitor->set_memory(memory);
//    task_monitor_count++;
//    taskMonitor->show();
//    MemMonitor = new Memmonitor(memory, CPU);
//    MemMonitor->setPID(task_monitor_count*100000+400);
//    MemMonitor->set_CPU(CPU);
//    MemMonitor->set_memory(memory);
//    memory_monitor_count++;
//    MemMonitor->show();
    Monitor = new monitor(CPU, memory);
    Monitor->setPID(text_editor_count*100000+500);
    Monitor->set_CPU(CPU);
    Monitor->set_memory(memory);
    monitor_count++;
    connect(this,SIGNAL(close()),Monitor,SLOT(close()));
    Monitor->show();
}

void MainWindow::on_btn_TextEditor_clicked()
{
    to_effect_Click();
    sleeping();
    text_editor = new TextEditor();
    text_editor->setPID(text_editor_count*100000+500);
    text_editor->set_CPU(CPU);
    text_editor->set_memory(memory);
    text_editor_count++;
    connect(this,SIGNAL(close()),text_editor,SLOT(close()));
    text_editor->show();

}

void MainWindow::on_btn_game_clicked()
{
    to_effect_Click();
    sleeping();
    MemGame = new Mem_Widget();
    MemGame->setPID(memory_game_count*100000+600);
    MemGame->set_CPU(CPU);
    MemGame->set_memory(memory);
    memory_game_count++;
    connect(this,SIGNAL(close()),MemGame,SLOT(close()));
    MemGame->show();
}


void MainWindow::on_actionShutdown_triggered()
{
    to_effect_Click();
    sleeping();
    close();
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
    sleeping();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}


void MainWindow::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void MainWindow::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(200);
}

void MainWindow::to_simple_Click(){ 
    CPU->operationDet(PID,simpleClick);
//    qDebug() << "simple_click";
    system_timer->start(200);
}

void MainWindow::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(200);
}

void MainWindow::closeEvent(QCloseEvent *event){
    CPU->terminateP(PID);
    if (created){
        memory->deallocate(PID,memory_size);
    }
    event->accept();
}

void MainWindow::set_up_memory(){
    if (!memory->allocate(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
    }
}

void MainWindow::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}


