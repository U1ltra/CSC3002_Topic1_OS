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

class SchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SchWidget(QWidget *parent = 0);
    ~SchWidget();
    void initcolorvec();
    void inittable();
    int returnprocessnum();//临时
    void printcolor_map();//临时
    void mydraw_1(int i, QPainter &painter);
    void mydraw_2(int i, QPainter &painter);
private slots:


    void on_spinBox_valueChanged(int arg1);

    void on_simulate_clicked();

    void on_clear_clicked();

    void on_comboBox_activated(const QString &arg1);


protected:
    bool eventFilter(QObject *watched, QEvent *event);
    //void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
    //颜色选择
    QColor color;
    map<string, QColor*> color_map;
    friend class scheduling;


    scheduling s;
    QTimer * t;

    int flag;
    int algo_sign;
    int number_of_process;
    int it;//遍历器

    vector<int> bq;
    vector<int> pq;
    vector<int> aq;
    std::vector<task*> execQ;

    vector<QColor*> colorvec;
};

#endif // WIDGET_H
