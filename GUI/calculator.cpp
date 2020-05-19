#include "calculator.h"
#include "ui_calculator.h"
#include <QTimer>
Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    number1 = 0.0;
    number2 = 0.0;
    result = 0.0;
    S="";
    last_number=true;
    after_equal = false;
    this->setWindowTitle("Calculator");
    connect(ui->calc_btn_clean,SIGNAL(clicked()),this,SLOT(on_calc_btn_clean_clicked()));

    setMouseTracking(true);

    system_timer = new QTimer();  // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
}

Calculator::~Calculator()
{   CPU->terminateP(PID);
    delete ui;
}

void Calculator::on_calc_btn_1_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="1";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+1;
    }else
        {
       number2 = number2*10+1;
    }
}

void Calculator::on_calc_btn_2_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="2";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+2;
    }else
        {
       number2 = number2*10+2;
    }
}

void Calculator::on_calc_btn_3_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="3";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+3;
    }else
        {
       number2 = number2*10+3;
    }
}

void Calculator::on_calc_btn_4_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="4";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+4;
    }else
        {
       number2 = number2*10+4;
    }
}

void Calculator::on_calc_btn_5_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="5";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+5;
    }else
        {
       number2 = number2*10+5;
    }
}

void Calculator::on_calc_btn_6_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="6";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+6;
    }else
        {
       number2 = number2*10+6;
    }
}

void Calculator::on_calc_btn_7_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="7";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+7;
    }else
        {
       number2 = number2*10+7;
    }
}

void Calculator::on_calc_btn_8_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="8";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+8;
    }else
        {
       number2 = number2*10+8;
    }
}

void Calculator::on_calc_btn_9_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="9";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10+9;
    }else
        {
       number2 = number2*10+9;
    }
}

void Calculator::on_calc_btn_0_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="0";
    ui->screen->setText(S);
    calculating();
    if(last_number){
     number1=number1*10;
    }else
        {
       number2 = number2*10;
    }
}

void Calculator::on_calc_btn_plus_clicked()
{   to_effect_Click();
    sleeping();
    if (number2 != 0.0){
        on_calc_btn_equal_clicked();
    }
    S+="+";
    sign='+';
    last_number=false;
    after_equal = false;
    ui->screen->setText(S);
}

void Calculator::on_calc_btn_minus_clicked()
{   to_effect_Click();
    sleeping();
    if (number2 != 0.0){
    on_calc_btn_equal_clicked();
    }
    S+="-";
    sign='-';
    last_number=false;
    after_equal = false;
    ui->screen->setText(S);
}

void Calculator::on_calc_btn_multipy_clicked()
{   to_effect_Click();
    sleeping();
    if (number2 != 0.0){
        on_calc_btn_equal_clicked();
    }
    S+="*";
    sign='*';
    last_number=false;
    after_equal = false;
    ui->screen->setText(S);
}

void Calculator::on_calc_btn_division_clicked()
{   to_effect_Click();
    sleeping();
    if (number2 != 0.0){
        on_calc_btn_equal_clicked();
    }
    S+="/";
    sign='/';
    last_number=false;
    after_equal = false;
    ui->screen->setText(S);
}

void Calculator::on_calc_btn_equal_clicked()
{   to_effect_Click();
    sleeping();
    S+="=";
    calculating();
    switch (sign) {
    case '+':
       result = number1 + number2;
        break;
    case '-':
       result = number1 - number2;
        break;
    case '*':
       result = number1 * number2;
        break;
    case '/':
       result = number1 / number2;
        break;
    default:
        result = number1;
        break;
    }
    number1 = result;
    number2 = 0;
    after_equal = true;
    S+=QString::number(result, 10, 2);
    ui->screen->setText(S);

}

void Calculator::on_calc_btn_clean_clicked()
{   to_effect_Click();
    sleeping();
    S="";
    ui->screen->setText(S);
    last_number=true;
    number1 = 0.0;
    number2 = 0.0;
    result = 0.0;
    sign=' ';
    after_equal = false;
}

void Calculator::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Calculator",user);
}


void Calculator::setPID(int pid){
    PID=pid;
}

void Calculator::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
    system_timer->start(100);
}

void Calculator::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
    system_timer->start(100);
}


void Calculator::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void Calculator::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void Calculator::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void Calculator::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void Calculator::calculating(){
    CPU->operationDet(PID,calculation);
    system_timer->start(100);
}

void Calculator::sleeping(){
    if (CPU->isBusy()){
    sleeper = new QTimer();
    sleeper->setSingleShot(true);
    sleeper->start(500);
    }
}
