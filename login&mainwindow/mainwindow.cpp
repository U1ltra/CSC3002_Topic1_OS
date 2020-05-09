#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_clock_clicked()
{

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
