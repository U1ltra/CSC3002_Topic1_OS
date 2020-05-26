#ifndef MEMWIDGET_H
#define MEMWIDGET_H

#include <QMouseEvent>
#include <QWidget>
#include <vector>
#include "memory/m_task.h"
#include "memory/Buddy.h"
#include <QPainter>
#include <QMainWindow>
#include "monitor/cpuMon.h"
#include <QTableWidgetItem>

namespace Ui {
class Mem_Widget;
}

class Mem_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Mem_Widget(QMainWindow *parent = nullptr);
    ~Mem_Widget();

    void setPID(int pid);
    void set_CPU(cpuMon *);
    void set_memory(Buddy * memory);

    bool eventFilter(QObject *watched, QEvent *event);

private slots:

    void on_clear_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_simulate_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void refresh();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_spinBox_valueChanged(const QString &arg1);

private:
    Ui::Mem_Widget *ui;
    std::vector<m_task*> task_vector;
    int tasknumber;
    Buddy * bd;
    int flag;

    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=1;
    void sleeping();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *event);
};

#endif // MEMWIDGET_H
