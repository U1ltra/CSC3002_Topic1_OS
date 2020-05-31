
/*
 * File:calculator.h
 * -----------------
 * This file exports a visualized calculator class.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QMouseEvent>
#include "monitor/cpuMon.h"
#include <QCloseEvent>
#include <QMainWindow>
#include "memoryGame/Buddy.h"

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QMainWindow *parent = nullptr);
    void setPID(int pid);
    void set_CPU(cpuMon*);
    void set_memory(Buddy* memory);
    ~Calculator();

private slots:
    void on_calc_btn_1_clicked();

    void on_calc_btn_2_clicked();

    void on_calc_btn_3_clicked();

    void on_calc_btn_4_clicked();

    void on_calc_btn_5_clicked();

    void on_calc_btn_6_clicked();

    void on_calc_btn_7_clicked();

    void on_calc_btn_8_clicked();

    void on_calc_btn_9_clicked();

    void on_calc_btn_0_clicked();

    void on_calc_btn_plus_clicked();

    void on_calc_btn_minus_clicked();

    void on_calc_btn_multipy_clicked();

    void on_calc_btn_division_clicked();

    void on_calc_btn_equal_clicked(); 

    void on_calc_btn_clean_clicked();  

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void calculating();

private:
    Ui::Calculator *ui;
    double number1,number2,result;
    QString S;
    char sign;
    bool last_number;// if last_number == true, last input is integer, otherwise, it is sign.
    bool after_equal; //if next_sign == true, next input would have to be a sign. If a number is clicked, next sign would be '+'.
    bool first_equation;// if first_equation == true, if means that this equation is the first equation.
    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=253;
    void sleeping();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *event);
};

#endif // CALCULATOR_H
