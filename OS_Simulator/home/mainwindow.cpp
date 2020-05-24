#include "home/mainwindow.h"
#include "ui_mainwindow.h"
#include "app/calculator.h"
#include "app/calendar.h"
#include <QStatusBar>
#include "app/digitalclock.h"
#include "cpuMon.h"
#include <QDebug>
#include <QToolButton>
#include "monitor/monitor.h"
#include <QMessageBox>

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
    clock_display = new DigitalClock();
    clock_display->setPID(11);//Default PID for clock is 11.
    clock_display->set_CPU(CPU);
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
{   CPU->terminateP(0);
    delete ui;
}



void MainWindow::on_btn_calc_clicked()
{   to_effect_Click();
    cal = new Calculator();
    cal->setPID(calculator_count*100000+100);
    cal->set_CPU(CPU);
    calculator_count++;
    cal->show();
}

void MainWindow::on_btn_Calendar_clicked()
{   to_effect_Click();
    Calendar *calendar = new Calendar();
    calendar->setPID(calendar_count*100000+200);
    calendar->set_CPU(CPU);
    calendar_count++;
    calendar->show();
}

void MainWindow::on_btn_FileSystem_clicked()
{   to_effect_Click();
    vfm = new VisualFileManager();
    vfm->setPID(file_system_count*100000+300);
    vfm->set_CPU(CPU);
    vfm->show();

}

void MainWindow::on_btn_TaskManager_clicked()
{
    to_effect_Click();
    taskMonitor = new monitor(CPU);
    taskMonitor->setPID(task_monitor_count*100000+400);
    taskMonitor->set_CPU(CPU);
    task_monitor_count++;
    taskMonitor->show();
}

void MainWindow::on_btn_TextEditor_clicked()
{   to_effect_Click();
    text_editor = new TextEditor();
    text_editor->setPID(text_editor_count*100000+500);
    text_editor->set_CPU(CPU);
    text_editor_count++;
    text_editor->show();

}

void MainWindow::on_btn_game_clicked()
{   to_effect_Click();

}

void MainWindow::on_actionSleep_triggered()
{   to_effect_Click();
    // FIXME::::
}

void MainWindow::on_actionShutdown_triggered()
{   to_effect_Click();
    close();
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
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

