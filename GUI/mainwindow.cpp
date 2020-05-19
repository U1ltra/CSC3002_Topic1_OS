#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include "calendar.h"
#include <QStatusBar>
#include "digitalclock.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CPU = new cpuMon();
    CPU->createP(0,"MainWindow",root);//Default PID for mainwindow is 0.

    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);
    clock_display = new DigitalClock();
    clock_display->setPID(1);//Default PID for clock is 1.
    clock_display->set_CPU(CPU);
    stBar->addPermanentWidget(clock_display);

    this->setWindowTitle("Main Window");
    setMouseTracking(true);

    system_timer = new QTimer();
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
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
    vfm->setPID(2); //Default PID for VFM is 2.
    vfm->set_CPU(CPU);
    vfm->show();

}

void MainWindow::on_btn_TaskManager_clicked()
{   to_effect_Click();

}

void MainWindow::on_btn_TextEditor_clicked()
{   to_effect_Click();
    text_editor = new TextEditor();
    text_editor->setPID(text_editor_count*100000+300);
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
    this->close();
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
    system_timer->start(100);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
    system_timer->start(100);
}


void MainWindow::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void MainWindow::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void MainWindow::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void MainWindow::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}
