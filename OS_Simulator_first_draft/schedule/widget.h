#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <iostream>
#include <QPixmap>
#include <map>
#include <string>
#include <QDebug>
#include "schedule/scheduling.h"
#include "monitor/cpuMon.h"
#include "memory/Buddy.h"
using namespace std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void setPID(int pid);
    void set_CPU(cpuMon*);
    void set_memory(Buddy* memory);
    ~Widget();

private slots:


    void on_spinBox_valueChanged(int arg1);

    void on_simulate_clicked();

    void on_clear_clicked();
    void on_comboBox_activated(const QString &arg1);
    void initcolorvec();
    void inittable();

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void refresh();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *event);
private:
    Ui::Widget *ui;
    //颜色选择
    QColor color;
    map<string, QColor*> color_map;
    friend class scheduling;

    int number_of_process;
    int returnprocessnum();
    void printcolor_map();
    scheduling s;


    int flag;
    int algo_sign;

    vector<int> bq;
    vector<int> pq;
    vector<int> aq;
    std::vector<task*> execQ;

    vector<QColor*> colorvec;

    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=1;
    void sleeping();
};

#endif // WIDGET_H
