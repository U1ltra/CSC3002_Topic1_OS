
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
#include "memory/Buddy.h"
namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QMainWindow *parent = nullptr);
    ~Calculator();

/*
 * Function: setPID, set_CPU, set_memory
 * Usage: setPID(pid); set_CPU(couMon*); set_memory(Buddy* memory);
 * ----------------------------------------------------------------
 * Set pid for the corressponding created program process and assign pointers
 * which are linkd to CPU and memory.
 */
 void setPID(int pid);
 void set_CPU(cpuMon*);
 void set_memory(Buddy* memory);

private slots:
/*
 * Slot Function: on_calc_btn_1_clicked
 * ------------------------------------------
 * Activated when User click button "1", systme will get this signal and screen
 * will change correspondingly.
 */
    void on_calc_btn_1_clicked();

/*
 * Slot Function: on_calc_btn_2_clicked
 * ------------------------------------------
 * Activated when User click button "2", systme will get this signal and screen
 * will change correspondingly.
 */
    void on_calc_btn_2_clicked();

/*
 * Slot Function: on_calc_btn_3_clicked
 * ------------------------------------------
 * Activated when User click button "3", systme will get this signal and screen
 * will change correspondingly.
 */
    void on_calc_btn_3_clicked();

/*
 * Slot Function: on_calc_btn_4_clicked
 * ------------------------------------------
 * Activated when User click button "4", systme will get this signal and screen
 * will change correspondingly.
 */
    void on_calc_btn_4_clicked();

/*
 * Slot Function: on_calc_btn_5_clicked
 * ------------------------------------------
 * Activated when User click button "5", systme will get this signal and screen
 * will change correspondingly.
 */
    void on_calc_btn_5_clicked();

/*
 * Slot Function: on_calc_btn_6_clicked
 * ------------------------------------------
 * Activated when User click button "6", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_6_clicked();

/*
 * Slot Function: on_calc_btn_7_clicked
 * ------------------------------------------
 * Activated when User click button "7", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_7_clicked();

/*
 * Slot Function: on_calc_btn_8_clicked
 * ------------------------------------------
 * Activated when User click button "8", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_8_clicked();

/*
 * Slot Function: on_calc_btn_9_clicked
 * ------------------------------------------
 * Activated when User click button "9", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_9_clicked();

/*
 * Slot Function: on_calc_btn_0_clicked
 * ------------------------------------------
 * Activated when User click button "0", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_0_clicked();

/*
 * Slot Function: on_calc_btn_plus_clicked
 * ------------------------------------------
 * Activated when User click button "+", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_plus_clicked();

/*
 * Slot Function: on_calc_btn_minus_clicked
 * ------------------------------------------
 * Activated when User click button "-", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_minus_clicked();

/*
 * Slot Function: on_calc_btn_mulitpy_clicked
 * ------------------------------------------
 * Activated when User click button "*", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_multipy_clicked();

/*
 * Slot Function: on_calc_btn_division_clicked
 * ------------------------------------------
 * Activated when User click button "/", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_division_clicked();

/*
 * Slot Function: on_calc_btn_equal_clicked
 * ------------------------------------------
 * Activated when User click button "=", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_equal_clicked();

/*
 * Slot Function: on_calc_btn_clean_clicked
 * ------------------------------------------
 * Activated when User click button "C", systme will get this signal and screen
 * will change correspondingly.
 */

    void on_calc_btn_clean_clicked();

/*
 * Slot Function: to_simple_Click, to effect_click,
 *                to_moving_around, back_to_fluctuation, calculating
 * ----------------------------------------------------
 * Update usage when corressponding operations are performed.
 */

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void calculating();

private:
    Ui::Calculator *ui;
    double number1,number2,result;
    QString S;        /* The String will be displayed in the screen.*/
    char sign;        /* The sign which calculator is operating*/
    bool last_number; /* if last_number == true, last input is integer, otherwise, it is sign.*/
    bool after_equal; /*if next_sign == true, next input would have to be a sign. If a number is clicked, next sign would be '+'.*/
    bool first_equation;/* if first_equation == true, if means that this equation is the first equation.*/
    int PID;                         /* The pid for created text editor process.            */
    QTimer *system_timer;            /* A timer to send signals to CPU to return to initial status.*/
    cpuMon* CPU;                     /* Assigned CPU for text editor.                       */
    Buddy* memory;                   /* Assigned memory for text editor.                    */
    bool created = false;            /* Turn true when memory are allocated to text editor. */
    int memory_size=253;             /* The memory size for text editor.                    */

    /* Private Functions */
    void sleeping();           /* When the usage of CPU reachs 75%, the program shuts down.*/

protected:
    void mousePressEvent(QMouseEvent *e);     /* Dectect the oparation of simple(invalid) click.*/
    void mouseMoveEvent(QMouseEvent *e);      /* Dectect the oparation of moving around.        */
    void closeEvent(QCloseEvent *event);      /* Dectect the oparation of window closing.        */
};

#endif // CALCULATOR_H
