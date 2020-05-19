#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QString>
namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();
    void setID(int id);
    QString getID();
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

private:
    Ui::Calculator *ui;
    double number1,number2,result;
    QString S;
    char sign;
    bool last_number;// if last_number == true, last input is integer, otherwise, it is sign.
    bool after_equal; //if next_sign == true, next input would have to be a sign. If a number is clicked, next sign would be '+'.
    bool first_equation;// if first_equation == true, if means that this equation is the first equation.
    int pid;
};

#endif // CALCULATOR_H
