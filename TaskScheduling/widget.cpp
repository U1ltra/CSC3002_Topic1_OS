#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QList>
#include<QStringList>
#include<QScrollBar>
#include<QPen>
#include<QBrush>
#include<QPainter>
#include<QImage>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    //create the ui
    ui->setupUi(this);


    ui->mygraph->installEventFilter(this);//在label上安装事件过滤器，this指针指定当事件发生时调用当前类中的事件过滤器进行处理


}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_spinBox_valueChanged(int arg1)
{
    //设置进程数
    number_of_process = arg1;
    ui->table_of_process->setRowCount(number_of_process);
    s.Tprocess = number_of_process;
    //设置列，设置其名字
    QList<QString> list_of_label;
    ui->table_of_process->setColumnCount(8);
    list_of_label<<("pid")<<("time remain")<<("Arrive Time")<<("Priority")<<("Wait Time")<<("Response Time")<<("Cycling Time")<<("Color");
    QStringList vertical_label(list_of_label);
    ui->table_of_process->setHorizontalHeaderLabels(vertical_label);
    ui->table_of_process->setStyleSheet("selection-background-color: red");
    inittable();//初始化表格
    cout << arg1<<endl;
}


void Widget::on_simulate_clicked(){
    flag = 1;
    printcolor_map();
    //设置表格内容
    //PID
    for(int i = 0; i<number_of_process;i++){
        QString s = QString::number(i+1);
        ui->table_of_process->setItem(i,0,new QTableWidgetItem(s));
    }

    //颜色
        initcolorvec();
        for(int i = 0; i< number_of_process;++i){
            ui->table_of_process->setItem(i,7,new QTableWidgetItem());
            ui->table_of_process->item(i,7)->setBackground(QBrush(*colorvec[i]));
        }
    //获取表格内容

    for(int i=0; i<number_of_process; i++){ // 取出每个格子的内容
            if(ui->table_of_process->item(i,1) != NULL&&ui->table_of_process->item(i,2) != NULL&&
                    ui->table_of_process->item(i,3) != NULL){//一定要先判断非空，否则会报错
            bq.push_back(ui->table_of_process->item(i,1)->text().toInt());
            aq.push_back(ui->table_of_process->item(i,2)->text().toInt());
            pq.push_back(ui->table_of_process->item(i,3)->text().toInt());
            qDebug()<<"finish"<<endl;//可复制
         }
    }
    //模拟
    s.setCondition(algo_sign,bq,aq,pq,0);
    s.simulation();
    //s.efficiency();
//    s.check();
    execQ = s.exeQ;
    //绘图
    update();
}
/*
*Function usage:when button "clear" is clicked
*----------
*/
void Widget::on_clear_clicked()
{
    ui->table_of_process->clear();
    ui->table_of_process->setColumnCount(0);
    ui->table_of_process->setRowCount(0);
    number_of_process = 0;
}
/*
*Function usage:return process number
*----------
*/
int Widget::returnprocessnum(){
    return number_of_process;
}


bool Widget::eventFilter(QObject *watched, QEvent *event)
 {

    if(watched == ui->mygraph && event->type() == QEvent::Paint && flag == 1)
       {
        QPainter painter(ui->mygraph);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::yellow);
        cout<<"exec length:"<<execQ.size()<<endl;
        for(int i = 1;i< execQ.size();i++){
            //QBrush * brush = new QBrush(*colorvec[(execQ[i])->pid]);
            cout<<"pid is"<<(execQ[i])->pid<<endl;
            painter.setBrush(QBrush(*colorvec[(execQ[i])->pid-1]));
            painter.drawRect(10*i,10,10,100);
        }}
       return QWidget::eventFilter(watched,event);
 }




void Widget::on_comboBox_activated(const QString &arg1)
{

    if(arg1 =="First-Come First-Served"){
        algo_sign = 1;
        }
    if(arg1 =="Shortest-Job First"){
        algo_sign = 2;
        }
    if(arg1 =="Shortest-Remaining Time"){
        algo_sign = 3;
        }
    if(arg1 =="Highest-Response Ratio Next"){
        algo_sign = 4;
        }
    if(arg1 =="Round_Robin"){
        algo_sign = 5;
        }
    cout<<"algo sign is:"<<algo_sign<<endl;;

}

void Widget::printcolor_map(){
    map<string,QColor*>::iterator it = color_map.begin();
    for(it; it!= color_map.end(); it++){
        std::cout<<(*it).first<<std::endl;
    }
}

void Widget::initcolorvec(){
    for(int i = 0; i< number_of_process;i++){
        colorvec.push_back(new QColor(rand()%(255 - 0 +1),rand()%(255 - 0 +1),rand()%(255 - 0 +1)));
    }
    cout<<"color vec size is"<< colorvec.size()<<endl;

}

void Widget::inittable(){
    //初始化表格
    for(int i =0;i<number_of_process;i++){
        for(int j =0;j<8;j++){
            ui->table_of_process->setItem(i,j,new QTableWidgetItem());
        }
    }
}
