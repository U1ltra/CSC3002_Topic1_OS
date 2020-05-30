#include "app/calculator.h"
#include "ui_calculator.h"
#include <QTimer>
//#include <windows.h>
#include <unistd.h>
#include <QMessageBox>

Calculator::Calculator(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    /* Set initial status for Calculator. */
    ui->setupUi(this);
    number1 = 0.0;
    number2 = 0.0;
    result = 0.0;
    S="";
    last_number=true;
    after_equal = false;
    ui->screen->setReadOnly(true);
    this->setWindowTitle("Calculator");
    connect(ui->calc_btn_clean,SIGNAL(clicked()),this,SLOT(on_calc_btn_clean_clicked()));

    /* Update usage by detecting different oparetions.*/
    setMouseTracking(true);
    system_timer = new QTimer();  // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
    connect(this,SIGNAL(closeEvent()),this,SLOT(shutdown()));
}

Calculator::~Calculator()
{
    delete ui;
}

/* Private Slots */

/*
 * Implementation notes: on_calc_btn_1_clicked
 * -------------------------------------------------
 * Activated when User click button "1", systme will get this signal and screen
 * will change correspondingly.
 */

void Calculator::on_calc_btn_1_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="1";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+1;
    }else
        {
       number2 = number2*10+1;
    }
}

/*
 * Implementation notes: on_calc_btn_2_clicked
 * -------------------------------------------------
 * Activated when User click button "2", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_2_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="2";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+2;
    }else
        {
       number2 = number2*10+2;
    }
}

/*
 * Implementation notes: on_calc_btn_3_clicked
 * -------------------------------------------------
 * Activated when User click button "3", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_3_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="3";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+3;
    }else
        {
       number2 = number2*10+3;
    }
}

/*
 * Implementation notes: on_calc_btn_4_clicked
 * -------------------------------------------------
 * Activated when User click button "4", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_4_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="4";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+4;
    }else
        {
       number2 = number2*10+4;
    }
}

/*
 * Implementation notes: on_calc_btn_5_clicked
 * -------------------------------------------------
 * Activated when User click button "5", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_5_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="5";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+5;
    }else
        {
       number2 = number2*10+5;
    }
}

/*
 * Implementation notes: on_calc_btn_6_clicked
 * -------------------------------------------------
 * Activated when User click button "6", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_6_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="6";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+6;
    }else
        {
       number2 = number2*10+6;
    }
}

/*
 * Implementation notes: on_calc_btn_7_clicked
 * -------------------------------------------------
 * Activated when User click button "7", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_7_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="7";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+7;
    }else
        {
       number2 = number2*10+7;
    }
}

/*
 * Implementation notes: on_calc_btn_8_clicked
 * -------------------------------------------------
 * Activated when User click button "8", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_8_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="8";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+8;
    }else
        {
       number2 = number2*10+8;
    }
}

/*
 * Implementation notes: on_calc_btn_9_clicked
 * -------------------------------------------------
 * Activated when User click button "9", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_9_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="9";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10+9;
    }else
        {
       number2 = number2*10+9;
    }
}

/*
 * Implementation notes: on_calc_btn_0_clicked
 * -------------------------------------------------
 * Activated when User click button "0", systme will get this signal and screen
 * will change correspondingly.
 */


void Calculator::on_calc_btn_0_clicked()
{   to_effect_Click();
    sleeping();
    if (after_equal){
        on_calc_btn_plus_clicked();
        after_equal = false;
    }
    S+="0";
    ui->screen->setPlainText(S);
    calculating();
    if(last_number){
     number1=number1*10;
    }else
        {
       number2 = number2*10;
    }
}

/*
 * Implementation notes: on_calc_btn_plus_clicked
 * -------------------------------------------------
 * Activated when User click button "+", systme will get this signal and screen
 * will change correspondingly.
 */


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
    ui->screen->setPlainText(S);
}

/*
 * Implementation notes: on_calc_btn_minus_clicked
 * -------------------------------------------------
 * Activated when User click button "-", systme will get this signal and screen
 * will change correspondingly.
 */

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
    ui->screen->setPlainText(S);
}
/*
 * Implementation notes: on_calc_btn_multipy_clicked
 * -------------------------------------------------
 * Activated when User click button "*", systme will get this signal and screen
 * will change correspondingly.
 */

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
    ui->screen->setPlainText(S);
}
/*
 * Implementation notes: on_calc_btn_division_clicked
 * -------------------------------------------------
 * Activated when User click button "/", systme will get this signal and screen
 * will change correspondingly.
 */

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
    ui->screen->setPlainText(S);
}
/*
 * Implementation notes: on_calc_btn_equal_clicked
 * -------------------------------------------------
 * Activated when User click button "=", systme will get this signal and screen
 * will change correspondingly.
 */

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
    ui->screen->setPlainText(S);

}
/*
 * Implementation notes: on_calc_btn_clean_clicked
 * -------------------------------------------------
 * Activated when User click button "C", systme will get this signal and screen
 * will change correspondingly.
 */

void Calculator::on_calc_btn_clean_clicked()
{   to_effect_Click();
    sleeping();
    S="";
    ui->screen->setPlainText(S);
    last_number=true;
    number1 = 0.0;
    number2 = 0.0;
    result = 0.0;
    sign=' ';
    after_equal = false;
}

/* Protected */

void Calculator::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void Calculator::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}

/*
 * Implementation notes: to_simple_Click, to_effect_Click, texting,
 *                       to_moving_around, back_to_fluctuation,calculating
 * ----------------------------------------------------------------
 * Update usage of CPU by calling function: operationDet. And start the timer,
 * after 100 milliseconds, notify the CPU to switch to initial status.
 */
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
        sleep(1);
    }
}

/*
 * Implementation notes: closeEvent
 * -------------------------------------------------
 * Quit the program. At the same time,terminate the process
 * in CPU and deallocate free heap.
 */
void Calculator::closeEvent(QCloseEvent *event){
    CPU->terminateP(PID);
    if (created){
        memory->deallocate(PID,memory_size);
        while(!CPU->isFreeToClose(PID)){
            sleep(1);
        }
    }
    event->accept();
}

/* Setters */

void Calculator::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
        showNormal();
    }
}

void Calculator::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Calculator",user);
}


void Calculator::setPID(int pid){
    PID=pid;
}
