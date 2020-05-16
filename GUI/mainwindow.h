#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include "digitalclock.h"
#include "calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_btn_calc_clicked();

    void on_btn_Calendar_clicked();

    void on_btn_FileSystem_clicked();

    void on_btn_TaskManager_clicked();

    void on_btn_TextEditor_clicked();

    void on_btn_game_clicked();

    void on_actionSleep_triggered();

    void on_actionShutdown_triggered();

private:
    // Instance Variable //
    Ui::MainWindow *ui;
    DigitalClock *clock_display;
    Calculator cal;
};

#endif // MAINWINDOW_H
