
/*
 * File: Schwidget.h
 * -----------------
 * This file exports a widget game for scheduling algorithms.
 */

#ifndef SCHWIDGET_H
#define SCHWIDGET_H

#include <QWidget>
#include <vector>
#include <QPixmap>
#include <map>
#include <string>
#include <vector>
#include <QThread>
#include <schedule/scheduling.h>
#include "monitor/cpuMon.h"
#include "memoryGame/Memwidget.h"

using namespace std;
namespace Ui {
class SchWidget;
}

class SchWidget : public QWidget
{
    Q_OBJECT

public:

    explicit SchWidget(QWidget *parent = 0);
    ~SchWidget();

    void initcolorvec();

    void inittable();

    void initgraph();

    bool repetitiondetect(int i, vector<int> v);

    bool checkempyt(int,int,int);

    void set_CPU(cpuMon * cpu);

    void setPID(int pid);

    void set_memory(Buddy *Memory);

private slots:


    void on_spinBox_valueChanged(int arg1);

    void on_simulate_clicked();

    void on_clear_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_initialize_clicked();

    void on_timeslice_textEdited(const QString &arg1);

    void on_pause_clicked();

    void on_play_clicked();

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void refresh();


protected:
    bool eventFilter(QObject *watched, QEvent *event);

protected:
    void mousePressEvent(QMouseEvent *e);

    void mouseMoveEvent(QMouseEvent *e);

    void closeEvent(QCloseEvent *event);

private:
    Ui::SchWidget *ui;
    QColor color;
    map<string, QColor*> color_map;

    scheduling * s;
    QTimer * t;

    int flag;
    int algo_sign;
    int number_of_process;
    int timeslice;
    bool rept_flag;
    bool init_flag;
    bool clear_flag;
    bool spin_flag;
    int ptremained;
    bool allow_to_init;
    vector<int> bq;
    vector<int> pq;
    vector<int> aq;
    std::vector<task*> execQ;
    vector<int> graphlenvec;
    vector<QColor*> colorvec;

    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=200;

    friend class scheduling;

    void sleeping();
};
#endif // WIDGET_H
