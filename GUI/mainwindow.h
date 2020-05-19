#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include "digitalclock.h"
#include "calculator.h"
#include "texteditor.h"
#include "visualfilemanager.h"
#include <QMouseEvent>
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
    QTimer *system_timer;
    int calculator_count = 1,
    digial_clock_count = 1,
    text_editor_count = 1,
    calendar_count = 1;
    int PID=0;
    cpuMon* CPU;

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
