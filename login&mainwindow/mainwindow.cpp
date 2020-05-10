#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login_interface.h"
#include <QCalendarWidget>
#include <QStatusBar>
#include "digitalclock.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);
    clock_display = new DigitalClock();
    stBar->addPermanentWidget(clock_display);
    this->setWindowTitle("Main Window");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_calc_clicked()
{

}

void MainWindow::on_btn_Calendar_clicked()
{
    QCalendarWidget *calendar = new QCalendarWidget();
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
