#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include "app/digitalclock.h"
#include "app/calculator.h"
#include "app/texteditor.h"
#include "filesys/visualfilemanager.h"
#include <QMouseEvent>
#include "monitor/monitor.h"
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

    void back_to_fluctuation();
private:
    // Instance Variable //

    Ui::MainWindow *ui;
    DigitalClock *clock_display;
    Calculator *cal;
    TextEditor *text_editor;
    VisualFileManager *vfm;
    monitor *taskMonitor;
    QTimer *system_timer;
    int calculator_count = 1,
    digial_clock_count = 1,
    text_editor_count = 1,
    calendar_count = 1,
    file_system_count=1,
    task_monitor_count=1;
    int PID=10;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=1;
    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void set_up_memory();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent*event);
};

#endif // MAINWINDOW_H
