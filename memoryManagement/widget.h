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

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool eventFilter(QObject *watched, QEvent *event);

private slots:

    void on_clear_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_simulate_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Widget *ui;
    std::vector<m_task*> task_vector;
    int tasknumber;
    Buddy * bd;
    int flag;
};

#endif // WIDGET_H
