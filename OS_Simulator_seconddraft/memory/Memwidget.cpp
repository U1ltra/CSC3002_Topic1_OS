/*
 * File: Memwidget.cpp
 * ---------------
 * This file implements the memwidget.h interface.
 */

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
    //        this->setFixedSize(600,500);
    ui->scrollAreaWidgetContents->installEventFilter(this);
    //设置表格内容
    ui->tableWidget->setColumnCount(3);

    //设置表头内容
    inittable();

    flag = 0;//event filter
    init_flag = false;//initialize memory
    success_flag = true;//allocate memory success
    clear_flag = false;
    mouse_flag = 1;
    tused = 0;
    ui->currentused->setText(QString::number(tused));
    ui->currentused->displayText();
    ui->currentused->setReadOnly(true);
    setMouseTracking(true);

    system_timer = new QTimer();
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
}

Mem_Widget::~Mem_Widget(){
    delete ui;
}


void Mem_Widget::on_clear_clicked(){
    sleeping();
    to_effect_Click();
    cout <<clear_flag<<endl;
    if(clear_flag == true){

        ui->spinBox->setValue(0);

        tasknumber = 0;
        flag = 2;
        task_vector.clear();
        promptvec.clear();
        if(bd != nullptr){
            delete bd;
        }
        bd = nullptr;
        tused = 0;
        ui->currentused->setText(QString::number(tused));
        ui->currentused->displayText();
        ui->scrollAreaWidgetContents->repaint();
        //initialize the spinbox and lineedit
        ui->memorystorage->setText("");

        init_flag = false;
        success_flag = true;
        clear_flag = false;
    }else{
        QMessageBox::warning(this,"Warning","You have already cleared",QMessageBox::Yes);
    }
    cout <<"end"<<clear_flag<<endl;
}

void Mem_Widget::on_spinBox_valueChanged(int arg1){
    sleeping();
    to_effect_Click();
    //set task number
    tasknumber = arg1;
    //change the table
    ui->tableWidget->setRowCount(tasknumber);
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header<<("Name")<<("PID")<<("Size");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(font);
    clear_flag = true;
}

bool Mem_Widget::eventFilter(QObject *watched, QEvent *event){
    if(watched == ui->scrollAreaWidgetContents && event->type() == QEvent::Paint &&flag ==1 &&init_flag == true)
    {
        QPainter painter(ui->scrollAreaWidgetContents);
        painter.setPen(Qt::yellow);
        painter.setBrush(Qt::yellow);
        int my_width = ui->scrollAreaWidgetContents->frameGeometry().width();
        int my_height = ui->scrollAreaWidgetContents->frameGeometry().height();
        painter.drawRect(0,0,my_width,my_height);
        for (int i = 0; i <bd->arr.size() ; i++) {
            vector<list<Pair>> temp = (*bd).arr;
            for (list<Pair>::iterator it = temp[i].begin();it!=temp[i].end();it++){
                painter.setPen(Qt::magenta);
                painter.setBrush(QBrush(Qt::magenta));
                painter.drawRect(0,double((it->lb))/(bd->getsize())*my_height,my_width,double((it->ub+1 - it->lb))/(bd->getsize())*my_height);
                promptvec.push_back(new QString("Memory from " +QString::number(it->lb) +" to " + QString::number(it->ub) + " allocated"));
                tused += it->ub+1 - it->lb;
                ui->currentused->setText(QString::number(bd->getsize()-tused));
                ui->currentused->displayText();
            }
        }
        tused = 0;
        init_flag =false;
        clear_flag = true;
    }
    if(watched == ui->scrollAreaWidgetContents && event->type() == QEvent::Paint &&flag ==2){
        QPainter painter(ui->scrollAreaWidgetContents);
        painter.setPen(Qt::transparent);
        painter.setBrush(Qt::transparent);
        int my_width = ui->scrollAreaWidgetContents->frameGeometry().width();
        int my_height = ui->scrollAreaWidgetContents->frameGeometry().height();
        painter.drawRect(0,0,my_width,my_height);
        clear_flag = true;
    }
    ui->scrollArea->update();
    ui->scrollAreaWidgetContents->update();
    refresh();
}

void Mem_Widget::on_simulate_clicked(){
    sleeping();
    to_effect_Click();
    if(init_flag == true && bd != nullptr ){
        if(bd->getsize() > 0){
            //set table content
            ui->tableWidget->setColumnCount(3);

            //retrieve data from table
            for(int i = 0; i<tasknumber;i++){
                if(ui->tableWidget->item(i,1) != NULL &&ui->tableWidget->item(i,2) != NULL &&ui->tableWidget->item(i,2)->text().toInt() > 0
                        &&ui->tableWidget->item(i,2)->text().toInt() <= bd->getsize()){//filter the event when the memory allocated is larger than total storage
                    std::cout<<"****"<<i<<"*******"<<std::endl;
                    task_vector.push_back(new m_task(atoi(ui->tableWidget->item(i,1)->text().toStdString().c_str()),
                                                     atoi(ui->tableWidget->item(i,2)->text().toStdString().c_str())));
                    std::cout<<"**Pid**"<<ui->tableWidget->item(i,1)->text().toInt()<<"*******"<<std::endl;
                    std::cout<<"**memory**"<<ui->tableWidget->item(i,2)->text().toInt()<<"*******"<<std::endl;
                }
                else{
                    success_flag = false;// 一级
                    break;
                }
            }

            if(success_flag == true){//2nd filter
                //check whether allocate successfully
                for(int i = 0;i<tasknumber;i++){
                    if(!bd->mem_allocation(*task_vector[i])){
                        success_flag = false;
                        break;
                    }
                }
                if(success_flag == true){//3rd filter
                    flag = 1;
                    ui->scrollAreaWidgetContents->update();
                    clear_flag = true;
                }

                }else{//Fail when allocating
                    QMessageBox::warning(this,"Warning","Fail to allocate memory");
                    ui->memorystorage->setText("");
                    clear_flag = true;
                    on_clear_clicked();
            }

        }else{//memory is allocatable
            QMessageBox::warning(this,"Warning","Fail to allocate memory");
            ui->memorystorage->setText("");
            clear_flag = true;
            on_clear_clicked();
        }

    }else{//have not initialize yet
        QMessageBox::warning(this,"Warning", "You cannot simulate now. Please First Clear and Input the Memory Size", QMessageBox::Ok);
        ui->memorystorage->setText("");
        clear_flag = true;
    }

}

void Mem_Widget::inittable(){
    QStringList header;
    header<<("Name")<<("PID")<<("Size");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(font);
    clear_flag = true;
}


void Mem_Widget::on_memorystorage_editingFinished()
{   sleeping();
    to_effect_Click();
    int num = atoi(ui->memorystorage->text().toStdString().c_str());
    std::cout<<"storage is"<<atoi(ui->memorystorage->text().toStdString().c_str())<<"*******"<<std::endl;
    if(num > 0){
        init_flag = true;
        bd = new Buddy(num);
        success_flag = true;
        int len = QString::number(num,16).size();
        QString str = "Address: 0x";
        for(int i = 0; i<len; i++){
            str += "0";
        }
        ui->label_6->setText(str);
        ui->uplimit->setText("Address: 0x"+QString::number(num,16));
        clear_flag = true;
    }
    else{
        QMessageBox::warning(this,"Warning","Fail to initialize memory",QMessageBox::Ok);
        clear_flag = true;
        on_clear_clicked();
    }

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
        while(!CPU->isFreeToClose(PID)){
            sleep(1);
        }
    }
    event->accept();
}


void Mem_Widget::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
        showNormal();
    }
}

void Mem_Widget::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    sleeping();
    to_effect_Click();
}



