
/*
 * File: Schwidget.cpp
 * -------------------
 * This file implements the scheduling game.
 */

#include <QPen>
#include <QList>
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QString>
#include <QPainter>
#include <QTextEdit>
#include <QScrollBar>
#include <QMessageBox>
#include <QStringList>
#include <unistd.h>
#include "ui_Schwidget.h"
#include "schedule/Schwidget.h"

SchWidget::SchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SchWidget)
{
    //create the ui
    ui->setupUi(this);
    ui->mygraph->installEventFilter(this);

    t = new QTimer(this);
    //initialize timeslice
    timeslice = -1;
    ptremained = -1;
    //flags
    init_flag = false;
    rept_flag = false;
    algo_sign = 0;
    spin_flag = false;
    allow_to_init = true;           //prevent double click simulate

    graphlenvec.push_back(0);

    system_timer = new QTimer(this);
    t = new QTimer(this);
    t->setInterval(1000);
    connect(t, &QTimer::timeout,[=](){ui->mygraph->update();ui->table_of_process->viewport()->update();
                                        ptremained++;});
    setMouseTracking(true);

}

SchWidget::~SchWidget()
{
    delete ui;
    delete s;
    s = nullptr;
}

void SchWidget::on_spinBox_valueChanged(int arg1)
{
    if(spin_flag){
        number_of_process = arg1;
        ui->table_of_process->setRowCount(number_of_process);
        s->Tprocess = number_of_process;
        //set col and its name
        inittable();                                //init table
        //PID
        for(int i = 0; i<number_of_process;i++){
            QString s = QString::number(i+1);
            ui->table_of_process->setItem(i,0,new QTableWidgetItem(s));
        }
    }
    else{
        QMessageBox::warning(this,"Warning","Please click initialize at first",QMessageBox::Yes);
    }
}

void SchWidget::on_simulate_clicked(){
    if(algo_sign == 4 && timeslice == -1){
        QMessageBox::warning(this, "Warning", "Please input timeslice",QMessageBox::Yes);
    }
    else{
        if(s != nullptr && init_flag == true&&number_of_process != 0){      //able to simulate
            flag = 1;

            for(int i=0; i<number_of_process; i++){
                if(ui->table_of_process->item(i,1) != NULL&&ui->table_of_process->item(i,2) != NULL&&
                        ui->table_of_process->item(i,3) != NULL
                        && repetitiondetect(ui->table_of_process->item(i,2)->text().toInt(),aq)&&checkempyt(i,1,3)
                        &&repetitiondetect(ui->table_of_process->item(i,3)->text().toInt(),aq))
                {
                    bq.push_back(ui->table_of_process->item(i,1)->text().toInt());
                    aq.push_back(ui->table_of_process->item(i,2)->text().toInt());
                    pq.push_back(ui->table_of_process->item(i,3)->text().toInt());
                    rept_flag = false;
                }
                else{
                    rept_flag = true;
                }
            }

            if(rept_flag == false){
                //color
                initcolorvec();
                for(int i = 0; i< number_of_process;++i){
                    ui->table_of_process->setItem(i,7,new QTableWidgetItem());
                    ui->table_of_process->item(i,7)->setBackground(QBrush(*colorvec[i]));
                }
                s->setCondition(algo_sign,bq,aq,pq,timeslice);
                s->simulation();
                s->efficiency();
                s->check();
                execQ = s->exeQ;
                //print table
                for(int i=0; i<number_of_process; i++){     //output the data
                    if(ui->table_of_process->item(i,4) != NULL&&ui->table_of_process->item(i,5) != NULL&&
                            ui->table_of_process->item(i,6) != NULL)
                    {
                        ui->table_of_process->setItem(i,4,new QTableWidgetItem(QString::number(s->pqueue[i]->waitT)));
                        ui->table_of_process->setItem(i,5,new QTableWidgetItem(QString::number(s->pqueue[i]->responseT)));
                        ui->table_of_process->setItem(i,6,new QTableWidgetItem(QString::number(s->pqueue[i]->cyclingT)));
                    }
                }
                ui->table_of_process->viewport()->update();
                //paint
                flag = 1;
                t->start();
                init_flag = false;
            }else{                                          //inable to print picture
                on_clear_clicked();
                QMessageBox::warning(this,"Warning","Please check your input",QMessageBox::Yes);
                rept_flag = false;
            }
        }else{//inable to simulate
            init_flag = false;
            on_clear_clicked();
            QMessageBox::warning(this,"Warning","Please clear and initialize at first",QMessageBox::Yes);
        }
    }
}

void SchWidget::on_clear_clicked()
{

    if(t != nullptr){
        if(t->isActive()){
            t->stop();
        }
    }
    ui->table_of_process->clear();
    ui->spinBox->setValue(0);

    bq.clear();
    pq.clear();
    aq.clear();

    colorvec.clear();

    graphlenvec.clear();
    graphlenvec.push_back(0);
    //flags
    init_flag =false;
    rept_flag = false;
    spin_flag =false;
    ptremained = -1;
    delete s;
    s = nullptr;
    ui->timecounter->setText(QString::number(0));
    allow_to_init = true;
    inittable();
    initgraph();
}

bool SchWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->mygraph && event->type() == QEvent::Paint && flag == 1)
    {
        int graphlen = graphlenvec[graphlenvec.size()-1];
        QPainter painter(ui->mygraph);
        painter.setPen(Qt::black);
        for(size_t i = 0; i <execQ.size();i++){
            if(execQ[i]->pid!= -1){
                if(execQ[i-1]->pid == -1){
                    painter.setPen(Qt::black);
                    painter.setBrush(Qt::GlobalColor::transparent);
                    painter.drawRect(graphlen,40,5*(execQ[i]->arrivaltime),100);
                    graphlen += 5*(execQ[i]->arrivaltime);

                    QBrush * brush = new QBrush(*colorvec[(execQ[i])->pid-1]);
                    painter.setBrush(*brush);
                    painter.drawRect(graphlen,40,5*(execQ[i]->timeRemain),100);
                    graphlen += 5*(execQ[i]->timeRemain);
                    delete brush;
                }else{
                    QBrush * brush = new QBrush(*colorvec[(execQ[i])->pid-1]);
                    painter.setBrush(*brush);
                    painter.drawRect(graphlen,40,5*(execQ[i]->timeRemain),100);
                    graphlen += 5*(execQ[i]->timeRemain);
                    delete brush;
                }
            }

            ui->timecounter->setText(QString::number(ptremained));
        }
        int temp = graphlenvec.size();
        graphlenvec.push_back((-5)*temp);
    }
    if(watched == ui->mygraph && event->type() == QEvent::Paint && flag == 2){
        QPainter p(ui->mygraph);
        p.setPen(Qt::color0);
        p.setBrush(Qt::GlobalColor::transparent);
        p.drawRect(0,0,ui->mygraph->size().width(),ui->mygraph->size().height());
        ui->timecounter->setText(QString::number(ptremained));
    }
    return QWidget::eventFilter(watched,event);
}

void SchWidget::on_comboBox_activated(const QString &arg1)
{
    if(arg1 =="First-Come First-Served"){
        algo_sign = 0;
    }
    if(arg1 =="Shortest-Job First"){
        algo_sign = 1;
    }
    if(arg1 =="Shortest-Remaining Time"){
        algo_sign = 2;
    }
    if(arg1 =="Highest-Response Ratio Next"){
        algo_sign = 3;
    }
    if(arg1 =="Round_Robin"){
        algo_sign = 4;
    }
}

void SchWidget::initcolorvec(){
    for(int i = 0; i< number_of_process;i++){
        colorvec.push_back(new QColor(rand()%(255 - 0 +1),rand()%(255 - 0 +1),rand()%(255 - 0 +1)));
    }
}

void SchWidget::inittable(){
    //initialize table
    QList<QString> list_of_label;
    ui->table_of_process->setColumnCount(8);
    list_of_label<<("pid")<<("time remain")<<("Arrive Time")<<("Priority")<<("Wait Time")<<("Response Time")<<("Cycling Time")<<("Color");
    QStringList vertical_label(list_of_label);
    ui->table_of_process->setHorizontalHeaderLabels(vertical_label);
    ui->table_of_process->setStyleSheet("selection-background-color: pink");
    for(int i =0;i<number_of_process;i++){
        for(int j =0;j<8;j++){
            ui->table_of_process->setItem(i,j,new QTableWidgetItem());
        }
    }
}

void SchWidget::initgraph(){
    flag = 2;
    ui->mygraph->repaint();
}

void SchWidget::on_initialize_clicked()
{
    if(allow_to_init == true){
        s = new scheduling;
        init_flag = true;
        allow_to_init = false;
        spin_flag = true;
    }else{
        QMessageBox::warning(this,"Warning","You cannot initialize for now. You should clear first.");
    }
}

void SchWidget::on_timeslice_textEdited(const QString &arg1)
{
    timeslice = arg1.toInt();
}

void SchWidget::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Schdedule",root);
}


void SchWidget::setPID(int pid){
    PID=pid;
}

void SchWidget::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
    system_timer->start(100);
}

void SchWidget::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
    system_timer->start(100);
}

void SchWidget::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void SchWidget::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void SchWidget::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void SchWidget::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void SchWidget::refresh(){
    CPU->operationDet(PID,refreshing);
    system_timer->start(100);
}

void SchWidget::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void SchWidget::closeEvent(QCloseEvent *event){
    CPU->terminateP(PID);
    if (created){
        memory->deallocate(PID,memory_size);
    }
    event->accept();
}

void SchWidget::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
        showNormal();
    }
}

void SchWidget::on_pause_clicked()
{
    if(t != nullptr){
        t->stop();
    }
}

void SchWidget::on_play_clicked()
{
    if(t != nullptr){
        t->start();
    }
}

bool SchWidget::repetitiondetect(int i, vector<int> v){
    for(int j = 0; j< v.size();j++){
        if(i == v[j]){
            return false;
        }
    }
    return true;
}

bool SchWidget::checkempyt(int i, int j, int k){
    for(int n = j; n <= k; n++){
        if(ui->table_of_process->item(i,n)->text() == ""){
            return false;
        }
    }
    return true;
}

