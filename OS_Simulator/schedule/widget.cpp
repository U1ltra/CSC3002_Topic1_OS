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
#include<ctime>
#include<QTimer>
#include <unistd.h>
#include <QMessageBox>
#include "monitor/cpuMon.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    //create the ui
    ui->setupUi(this);


    ui->mygraph->installEventFilter(this);//在label上安装事件过滤器，this指针指定当事件发生时调用当前类中的事件过滤器进行处理

    setMouseTracking(true);

    system_timer = new QTimer();  // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
    connect(this,SIGNAL(closeEvent()),this,SLOT(shutdown()));
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
    s.efficiency();
//    s.check();
    execQ = s.exeQ;
    //打印表格
    for(int i = 0; i< number_of_process;++i){
        ui->table_of_process->setItem(i,4,new QTableWidgetItem());
        ui->table_of_process->setItem(i,5,new QTableWidgetItem());
        ui->table_of_process->setItem(i,6,new QTableWidgetItem());
        //ui->table_of_process->item(i,4)->setText();
    }
//    //绘图
//    QTimer* t = new QTimer(ui->mygraph);
//    t->start(1000);
//    t->setInterval(1000);
//    connect(t,SIGNAL(timeout()),this,SLOT(update()));
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
    ui->mygraph->clearMask();
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
        cout<<"exec length:"<<execQ.size()<<endl;
        for(int i = 0;i< execQ.size();i++){

            if(execQ[i]->pid!= -1){
               QBrush * brush = new QBrush(*colorvec[(execQ[i])->pid-1]);
                cout<<"pid is"<<(execQ[i])->pid<<endl;
                painter.setBrush(*brush);

                painter.drawRect(100+10*i,40,10,100);
            }
            else{
                painter.setBrush(Qt::GlobalColor::color0);
                painter.drawRect(100+10*i,40,10,100);
            }

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
    cout<<"algo sign is:"<<algo_sign<<endl;

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

void Widget::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Schdedule",root);
}


void Widget::setPID(int pid){
    PID=pid;
}

void Widget::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}

void Widget::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void Widget::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void Widget::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void Widget::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void Widget::refresh(){
    CPU->operationDet(PID,refreshing);
    system_timer->start(100);
}

void Widget::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void Widget::closeEvent(QCloseEvent *event){
    CPU->terminateP(PID);
    if (created){
    memory->deallocate(PID,memory_size);
    }
    event->accept();
}


void Widget::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->allocate(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
    }
}
