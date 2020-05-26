#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include<stdlib.h>
#include <QMessageBox>
Mem_Widget::Mem_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->scrollAreaWidgetContents->installEventFilter(this);
    //设置表格内容
    ui->tableWidget->setColumnCount(3);

    //设置表头内容
     inittable();


     flag = 0;//event filter
     init_flag = false;//initialize memory
     success_flag = true;//allocate memory success
     tused = 0;
     ui->currentused->setText(QString::number(tused));
     ui->currentused->displayText();
     ui->currentused->setReadOnly(true);
}

Mem_Widget::~Mem_Widget()
{
    delete ui;
}


void Mem_Widget::on_clear_clicked()
{
    ui->tableWidget->clearContents();
    tasknumber = 0;
    flag = 2;
    task_vector.clear();

    delete bd;
    bd = nullptr;

    tused = 0;
    ui->currentused->setText(QString::number(tused));
    ui->currentused->displayText();

    init_flag = false;
    success_flag = true;
    ui->scrollAreaWidgetContents->update();
}

void Mem_Widget::on_spinBox_valueChanged(int arg1)
{

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
//    ui->tableWidget->setItem(0,tasknumber-1,new QTableWidgetItem(Qt::number(tasknumber)));
}

bool Mem_Widget::eventFilter(QObject *watched, QEvent *event){
    //填入你想画的图
    if(watched == ui->scrollAreaWidgetContents && event->type() == QEvent::Paint &&flag ==1 &&init_flag == true)
       {
    QPainter painter(ui->scrollAreaWidgetContents);
    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::yellow);
    int my_width = ui->scrollAreaWidgetContents->frameGeometry().width();
    int my_height = ui->scrollAreaWidgetContents->frameGeometry().height();
    painter.drawRect(0,0,my_width,my_height);
    std::cout<<"hhhhhhhh"<<my_height<<std::endl;
    for (int i = 0; i <bd->arr.size() ; i++){
        //painter.drawRect(0,0,100,i*10);

        vector<list<Pair>> temp = (*bd).arr;

        for (list<Pair>::iterator it = temp[i].begin();it!=temp[i].end();it++){

            cout<<(bd->getsize())<<endl;
            cout<<"ub"<<it->ub<<endl;
            cout<<"lb"<<it->lb<<endl;
            cout<<my_height<<endl;
            painter.setPen(Qt::magenta);
            painter.setBrush(QBrush(Qt::magenta));

            painter.drawRect(0,double((it->lb))/(bd->getsize())*my_height,my_width,double((it->ub+1 - it->lb))/(bd->getsize())*my_height);
            tused += it->ub+1 - it->lb;
            ui->currentused->setText(QString::number(bd->getsize()-tused));
            ui->currentused->displayText();
        }

    }
    init_flag =false;
  }
    if(watched == ui->scrollAreaWidgetContents && event->type() == QEvent::Paint &&flag ==2)
       {
        QPainter painter(ui->scrollAreaWidgetContents);
        painter.setPen(Qt::transparent);
        painter.setBrush(Qt::transparent);
        int my_width = ui->scrollAreaWidgetContents->frameGeometry().width();
        int my_height = ui->scrollAreaWidgetContents->frameGeometry().height();
        painter.drawRect(0,0,my_width,my_height);
    }
}

void Mem_Widget::on_simulate_clicked()
{
    if(init_flag == true && bd != nullptr ){
        if(bd->getsize() > 0){
        //设置表格内容
        ui->tableWidget->setColumnCount(3);
        flag = 1;
        //retrieve data from table
        for(int i = 0; i<tasknumber;i++){
            if(ui->tableWidget->item(i,1) != NULL &&ui->tableWidget->item(i,2) != NULL &&ui->tableWidget->item(i,2)->text().toInt() > 0){
            std::cout<<"****"<<i<<"*******"<<std::endl;
            task_vector.push_back(new m_task(atoi(ui->tableWidget->item(i,1)->text().toStdString().c_str()),
                                            atoi(ui->tableWidget->item(i,2)->text().toStdString().c_str())));
            std::cout<<"**Pid**"<<ui->tableWidget->item(i,1)->text().toInt()<<"*******"<<std::endl;
            std::cout<<"**memory**"<<ui->tableWidget->item(i,2)->text().toInt()<<"*******"<<std::endl;
        }
            else{
                success_flag = false;
            }
    }
        for(int i = 0;i<tasknumber;i++){
            //bd->allocate(*task_vector[i]);
            if(!bd->allocate(*task_vector[i])){
                success_flag = false;
                }
        }
        if(success_flag){
            ui->scrollAreaWidgetContents->update();
        }
        else{
            QMessageBox::warning(this,"Warning","Fail to allocate memory");
        }
    }
}
    else{
        QMessageBox::warning(this,"Warning", "Please Input the Memory Size at first", QMessageBox::Ok);
    }

}


void Mem_Widget::inittable(){
    QStringList header;
    header<<("Name")<<("PID")<<("Size");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(font);
}





void Mem_Widget::on_lineEdit_editingFinished()
{
    int num = atoi(ui->lineEdit->text().toStdString().c_str());
    std::cout<<"storage is"<<atoi(ui->lineEdit->text().toStdString().c_str())<<"*******"<<std::endl;
    if(num > 0){
        init_flag = true;
        bd = new Buddy(num);
        success_flag = true;
    }
    else{
        QMessageBox::warning(this,"Warning","Fail to initialize memory",QMessageBox::Ok);
    }


}
