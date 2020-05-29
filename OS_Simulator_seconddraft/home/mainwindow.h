/*
 * File: mainwindow.h
 * ------------------
 * This file defines the main window of GUI.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QMouseEvent>
#include "app/digitalclock.h"
#include "app/calculator.h"
#include "app/texteditor.h"
#include "app/calendar.h"
#include "filesys/visualfilemanager.h"
#include "memory/Memwidget.h"
#include "schedule/Schwidget.h"
#include "monitor/memMonitor.h"
#include "monitor/monitor.h"
#include "monitor/CPUmonitor.h"

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

/*
 * Slot Functions: on_btn_calc_clicked, on_btn_Calendar_clicked,
 *                 on_btn_FileSystem_clicked, on_btn_TaskManager_clicked,
 *                 on_btn_TextEditor_clicked, on_Memory_Simulator_triggered,
 *                 on_btn_Memory_Simulator_clicked
 * -----------------------------------------------------------------------
 * Show corresponding application. Start the process and set pid, cpu and memory.
 * Add the count of process by 1.
 */
    void on_btn_calc_clicked();

    void on_btn_Calendar_clicked();

    void on_btn_FileSystem_clicked();

    void on_btn_TaskManager_clicked();

    void on_btn_TextEditor_clicked();

    void on_btn_Memory_Simulator_clicked();

    void on_btn_Schedule_Simulator_clicked();

/*
 * Slot Function: on_actionShutdown_triggered
 * ------------------------------------------
 * Terminate all process along with main window.
 */
    void on_actionShutdown_triggered();

    void back_to_fluctuation();

private:

    /* Instance Variable */

    Ui::MainWindow *ui;
    DigitalClock *clock_display;
    Calculator *cal;
    TextEditor *text_editor;
    VisualFileManager *vfm;
    Calendar *calendar;
    CPUmonitor *taskMonitor;
    Mem_Widget *MemGame;
    SchWidget *SchGame;
    Memmonitor *MemMonitor;
    monitor *Monitor;
    QTimer *system_timer;

    //Set all initial process of applications to 1.
    int calculator_count = 1,
    digial_clock_count = 1,
    text_editor_count = 1,
    calendar_count = 1,
    file_system_count=1,
    task_monitor_count=1,
    memory_game_count = 1,
    memory_monitor_count = 1,
    monitor_count = 1,
    Schedule_game_count=1;

    int PID=10;                      /* The pid for main window.                            */
    cpuMon* CPU;                     /* Assigned CPU for main window.                       */
    Buddy* memory;                   /* Assigned memory for main window.                    */
    bool created = false;            /* Turn true when memory are allocated to main window. */
    int memory_size=250;             /* The memory size for main window.                    */

    /* Private Functions: Updage usage of CPU for different oparetions.*/

    void to_simple_Click();
    void to_effect_Click();
    void to_moving_around();
    void set_up_memory();
    void sleeping();

    void mainwindow_layout();

protected:
    void mousePressEvent(QMouseEvent *e);      /* Dectect the oparation of simple(invalid) click.*/
    void mouseMoveEvent(QMouseEvent *e);       /* Dectect the oparation of moving around.        */
    void closeEvent(QCloseEvent*event);

signals:
    void closing();
};

#endif // MAINWINDOW_H
