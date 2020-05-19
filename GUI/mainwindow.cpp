#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "login_interface.h"
#include "calculator.h"
#include <QCalendarWidget>
#include <QStatusBar>
#include "digitalclock.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);

    clock_display = new DigitalClock();
    clock_display->setID(Clock_Count);
    Clock_Count++;

    stBar->addPermanentWidget(clock_display);

    this->setWindowTitle("Main Window");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_calc_clicked()
{   Calculator *calculator = new Calculator();
    calculator->setID(Calculator_Count);
    Calculator_Count++;
    Programs.insert(calculator->getID(),calculator);
    connect(calculator,SIGNAL(closeEvent()),this,SLOT(delete_Program(calculator->getID())));
    calculator->show();
}

void MainWindow::on_btn_Calendar_clicked()
{   calendar = new Calendar();
    calendar->setID(Calendar_Count);
    Calendar_Count ++;
    Programs.insert(calendar->getID(),calendar);
    connect(calendar,SIGNAL(closeEvent()),this,SLOT(delete_Program(calendar->getID())));
    calendar->show();

}

void MainWindow::on_btn_FileSystem_clicked()
{

}

void MainWindow::on_btn_TaskManager_clicked()
{

}

void MainWindow::on_btn_TextEditor_clicked()
{

}

void MainWindow::on_btn_game_clicked()
{

}

void MainWindow::on_actionSleep_triggered()
{

}

void MainWindow::on_actionShutdown_triggered()
{
    this->close();
}

void MainWindow::delete_Program(QString pid){
    if (Programs.contains(pid)){
        Programs.remove(pid);
    }else{
        qDebug()<<"There does not exist such program.";
    }
}
