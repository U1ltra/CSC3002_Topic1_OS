#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include<stdlib.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
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
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_clear_clicked()
{
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    tasknumber = 0;
    flag = 0;

}

void Widget::on_spinBox_valueChanged(int arg1)
{
    //set task number
    tasknumber = arg1;
    //change the table
    ui->tableWidget->setRowCount(tasknumber);


}

bool Widget::eventFilter(QObject *watched, QEvent *event){
    //填入你想画的图
    if(watched == ui->scrollAreaWidgetContents && event->type() == QEvent::Paint &&flag ==1)
       {
    QPainter painter(ui->scrollAreaWidgetContents);
    painter.setPen(Qt::color0);
    painter.setBrush(Qt::gray);
    int my_width = ui->scrollAreaWidgetContents->frameGeometry().width();
    int my_height = ui->scrollAreaWidgetContents->frameGeometry().height();
    painter.drawRect(0,0,my_width,my_height);
    //std::cout<<"hhhhhhhh"<<my_height<<std::endl;
    for (int i = 0; i <bd->arr.size() ; i++){
        //painter.drawRect(0,0,100,i*10);

        vector<list<Pair>> temp = (*bd).arr;
        for (list<Pair>::iterator it = temp[i].begin();it!=temp[i].end();it++){
            cout<<"ub"<<it->ub<<endl;
            cout<<"lb"<<it->lb<<endl;
            painter.setBrush(QBrush(Qt::white,Qt::Dense3Pattern));
            /*if(it->ub == bd->getsize()-1){
                painter.drawRect(0,(double((it->lb)))/(bd->getsize())*my_height,my_width,double((it->ub)+1)/(bd->getsize())*my_height);
            }*/
            painter.drawRect(0,double((it->lb))/(bd->getsize())*(my_height),my_width,double((it->ub)+1)/(bd->getsize())*(my_height));
        }
    }
  }
}

void Widget::on_simulate_clicked()
{
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

void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    int num = atoi(arg1.toStdString().c_str());
    bd = new Buddy(num);
    std::cout<<"storage is"<<atoi(arg1.toStdString().c_str())<<"*******"<<std::endl;
}
