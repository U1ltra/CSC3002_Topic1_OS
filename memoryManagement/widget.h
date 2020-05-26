#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include"m_task.h"
#include"Buddy.h"
#include<QPainter>
namespace Ui {
class Widget;
}

class Mem_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Mem_Widget(QWidget *parent = 0);
    ~Mem_Widget();
    bool eventFilter(QObject *watched, QEvent *event);
    void inittable();

private slots:

    void on_clear_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_simulate_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::Widget *ui;
    std::vector<m_task*> task_vector;
    std::vector<m_task*> pid_vector;
    int tasknumber;
    Buddy * bd;
    int flag;
    bool init_flag;
    bool success_flag;
    int tused;//total used
};

#endif // WIDGET_H
