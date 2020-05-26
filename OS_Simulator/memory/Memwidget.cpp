
#include "memory/Memwidget.h"
#include "ui_Memwidget.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <QMessageBox>
#include <QTimer>

Mem_Widget::Mem_Widget(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Mem_Widget)
{
    ui->setupUi(this);

    ui->scrollAreaWidgetContents->installEventFilter(this);
    //设置表格内容
    ui->tableWidget->setColumnCount(3);

    //设置表头内容
     QStringList header;
     header<<("Name")<<("PID")<<("Size");
     ui->tableWidget->setHorizontalHeaderLabels(header);
     QFont font = ui->tableWidget->horizontalHeader()->font();
     font.setBold(true);
     ui->tableWidget->horizontalHeader()->setFont(font);

     bd = new Buddy(256);
     flag = 0;

     setMouseTracking(true);

     system_timer = new QTimer();  // To return to the fluctuation.
     system_timer->setSingleShot(true);
     connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
     connect(this,SIGNAL(closeEvent()),this,SLOT(shutdown()));
}

Mem_Widget::~Mem_Widget()
{
    delete ui;
}


void Mem_Widget::on_clear_clicked()
{
    to_effect_Click();
    sleeping();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    tasknumber = 0;
    flag = 0;

}

void Mem_Widget::on_spinBox_valueChanged(int arg1)
{
    //set task number
    tasknumber = arg1;
    //change the table
    ui->tableWidget->setRowCount(tasknumber);


}
bool Mem_Widget::eventFilter(QObject *watched, QEvent *event){
    //填入你想画的图
    if(watched == ui->scrollAreaWidgetContents && event->type() == QEvent::Paint &&flag ==1)
       {
    QPainter painter(ui->scrollAreaWidgetContents);
    painter.setPen(Qt::color0);
    painter.setBrush(Qt::yellow);
    int my_width = ui->scrollAreaWidgetContents->frameGeometry().width();
    int my_height = ui->scrollAreaWidgetContents->frameGeometry().height();
    painter.drawRect(0,0,my_width,my_height);
    std::cout<<"hhhhhhhh"<<my_height<<std::endl;
    for (int i = 0; i <bd->arr.size() ; i++){
        //painter.drawRect(0,0,100,i*10);

        vector<list<Pair>> temp = (*bd).arr;
        vector<int> vector_of_lastub;
        for (list<Pair>::iterator it = temp[i].begin();it!=temp[i].end();it++){

            cout<<(bd->getsize())<<endl;
            cout<<"ub"<<it->ub<<endl;
            cout<<"lb"<<it->lb<<endl;
            cout<<my_height<<endl;
            painter.setBrush(QBrush(Qt::magenta,Qt::Dense3Pattern));
            if(vector_of_lastub.empty()){
                painter.drawRect(0,double((it->lb))/(bd->getsize())*my_height,my_width,double((it->ub - it->lb))/(bd->getsize())*my_height);
            }
            else{
                int j = vector_of_lastub.size();
                 painter.drawRect(0,double((it->lb))/(bd->getsize())*my_height-1,my_width,double((it->ub - it->lb))/(bd->getsize())*my_height+1);
            }
            vector_of_lastub.push_back(it->ub);
        }
    }
  }
}

void Mem_Widget::on_simulate_clicked()
{
    to_effect_Click();
    sleeping();
    //设置表格内容
    ui->tableWidget->setColumnCount(3);

    //设置表头内容
     QStringList header;
     header<<("Name")<<("PID")<<("Size");
     ui->tableWidget->setHorizontalHeaderLabels(header);
     QFont font = ui->tableWidget->horizontalHeader()->font();
     font.setBold(true);
     ui->tableWidget->horizontalHeader()->setFont(font);
    std::cout<<"***********"<<std::endl;
    flag = 1;
    //retrieve data from table
    for(int i = 0; i<tasknumber;i++){
        std::cout<<"****"<<i<<"*******"<<std::endl;
        task_vector.push_back(new m_task(atoi(ui->tableWidget->item(i,1)->text().toStdString().c_str()),
                                        atoi(ui->tableWidget->item(i,2)->text().toStdString().c_str())));
        std::cout<<"**Pid**"<<ui->tableWidget->item(i,1)->text().toInt()<<"*******"<<std::endl;
        std::cout<<"**memory**"<<ui->tableWidget->item(i,2)->text().toInt()<<"*******"<<std::endl;
    }

    for(int i = 0;i<tasknumber;i++){
        bd->allocate(*task_vector[i]);

    }

//    for(int i = 0;i<tasknumber;i++){
//        bd->deallocate(*task_vector[i]);

//    }
    update();
}

void Mem_Widget::on_lineEdit_textEdited(const QString &arg1)
{
    int num = atoi(arg1.toStdString().c_str());
    bd = new Buddy(num);
    std::cout<<"storage is"<<atoi(arg1.toStdString().c_str())<<"*******"<<std::endl;
}



void Mem_Widget::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Mem_Widget",user);
}


void Mem_Widget::setPID(int pid){
    PID=pid;
}

void Mem_Widget::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void Mem_Widget::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}


void Mem_Widget::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void Mem_Widget::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void Mem_Widget::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void Mem_Widget::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void Mem_Widget::refresh(){
    CPU->operationDet(PID,refreshing);
    system_timer->start(100);
}

void Mem_Widget::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void Mem_Widget::closeEvent(QCloseEvent *event){
    CPU->terminateP(PID);
    if (created){
    memory->deallocate(PID,memory_size);
    }
    event->accept();
}


void Mem_Widget::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->allocate(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
    }
}

void Mem_Widget::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    to_simple_Click();
}

void Mem_Widget::on_spinBox_valueChanged(const QString &arg1)
{
    to_effect_Click();
    sleeping();
}


