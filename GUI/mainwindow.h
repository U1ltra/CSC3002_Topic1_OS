#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include "digitalclock.h"
#include "calculator.h"
#include "calendar.h"
#include <QMap>
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

    void delete_Program(QString pid);

private:
    // Instance Variable //
    Ui::MainWindow *ui;
    DigitalClock *clock_display;
    Calculator *cal;
    Calendar *calendar;
    int Calculator_Count,Calendar_Count,FileSystem_Count,TaskManager_Count,
    TextEditor_Counter,Game_Count,Clock_Count;
    QMap<QString,QObject*>Programs;
};

#endif // MAINWINDOW_H
