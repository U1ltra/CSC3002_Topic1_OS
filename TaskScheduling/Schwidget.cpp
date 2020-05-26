#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QList>
#include <QStringList>
#include <QScrollBar>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QImage>
#include <ctime>
#include <QTimer>
#include <QTextEdit>
//#include <unistd.h>
#include <QMessageBox>
//#include "monitor/cpuMon.h"
SchWidget::SchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SchWidget)
{

    //create the ui
    ui->setupUi(this);


    ui->mygraph->installEventFilter(this);//在label上安装事件过滤器，this指针指定当事件发生时调用当前类中的事件过滤器进行处理

    t = new QTimer(this);
    //initialize timeslice
    timeslice = -1;
    ptremained = 0;
    init_flag = false;
    rept_flag = false;
    graphlenvec.push_back(0);
    //mythrd = new mythread;
    //qthrd = new QThread(this);
    //mythrd->moveToThread(qthrd);
    //QImage mythrd_image;
    //启动子线程  但是没有启动子线程处理函数
    //qthrd->start();

    //子线程绘图函数 drawImage（）必须通过 signals-- slots来调用实现
    //connect(ui->simulate , &QPushButton::clicked , mythrd , &mythread::drawImage);

    //将子线程绘制完成时发出的信号与自定义槽函数getImage(QImage)连接起来
    //connect(mythrd , &mythread::updateimage , this , &SchWidget::getImage);

    //*************退出窗口时 关闭子线程*************
    //connect(this, &SchWidget::destroyed, this , &SchWidget::kill_thread);

   // setMouseTracking(true);

}

SchWidget::~SchWidget()
{
    delete ui;

}



void SchWidget::on_spinBox_valueChanged(int arg1)
{
    //设置进程数
    if(s != nullptr){
        number_of_process = arg1;
        ui->table_of_process->setRowCount(number_of_process);
        s->Tprocess = number_of_process;
        //设置列，设置其名字
        QList<QString> list_of_label;
        ui->table_of_process->setColumnCount(8);
        list_of_label<<("pid")<<("time remain")<<("Arrive Time")<<("Priority")<<("Wait Time")<<("Response Time")<<("Cycling Time")<<("Color");
        QStringList vertical_label(list_of_label);
        ui->table_of_process->setHorizontalHeaderLabels(vertical_label);
        ui->table_of_process->setStyleSheet("selection-background-color: pink");
        inittable();//初始化表格
        //PID
        for(int i = 0; i<number_of_process;i++){
            QString s = QString::number(i+1);
            ui->table_of_process->setItem(i,0,new QTableWidgetItem(s));
        }
        cout << arg1<<endl;
    }
    else{
        QMessageBox::warning(this,"Warning","Please click initialize at first",QMessageBox::Yes);

    }

}


void SchWidget::on_simulate_clicked(){
    if(algo_sign == 5 && timeslice == -1){
        QMessageBox::warning(this, "Warning", "Please input timeslice",QMessageBox::Yes);
    }
    else{
        if(s != nullptr && init_flag == true){
                flag = 1;
                printcolor_map();

                //设置表格内容


                //颜色
                    initcolorvec();
                    for(int i = 0; i< number_of_process;++i){
                        ui->table_of_process->setItem(i,7,new QTableWidgetItem());
                        ui->table_of_process->item(i,7)->setBackground(QBrush(*colorvec[i]));
                    }
                //获取表格内容
                    cout<<"**************8"<<endl;
                for(int i=0; i<number_of_process; i++){ // 取出每个格子的内容
                        if(ui->table_of_process->item(i,1) != NULL&&ui->table_of_process->item(i,2) != NULL&&                                   //不能同时有相同的到达
                                ui->table_of_process->item(i,3) != NULL && repetitiondetect(ui->table_of_process->item(i,2)->text().toInt(),aq)){//一定要先判断非空，否则会报错
                        bq.push_back(ui->table_of_process->item(i,1)->text().toInt());
                        aq.push_back(ui->table_of_process->item(i,2)->text().toInt());
                        pq.push_back(ui->table_of_process->item(i,3)->text().toInt());
                        rept_flag = false;
                        qDebug()<<"finish"<<endl;//可复制
                     }
                        else{
                            rept_flag = true;
                        }
                }
                //模拟
                if(rept_flag == false){
                s->setCondition(algo_sign,bq,aq,pq,timeslice);
                s->simulation();
                s->efficiency();
                s->check();
                execQ = s->exeQ;
                //print execq
                for(int j = 0; j< execQ.size();j++){
                    cout <<execQ[j]->pid<<endl;
                }
                //打印表格
                for(int i=0; i<number_of_process; i++){ // 取出每个格子的内容
                        if(ui->table_of_process->item(i,4) != NULL&&ui->table_of_process->item(i,5) != NULL&&
                                ui->table_of_process->item(i,6) != NULL){
                                ui->table_of_process->setItem(i,4,new QTableWidgetItem(QString::number(s->pqueue[i]->waitT)));
                                ui->table_of_process->setItem(i,5,new QTableWidgetItem(QString::number(s->pqueue[i]->responseT)));
                                ui->table_of_process->setItem(i,6,new QTableWidgetItem(QString::number(s->pqueue[i]->cyclingT)));
                        }
                    }
                //绘图
                t = new QTimer(this);
                t->setInterval(1000);
                connect(t, &QTimer::timeout,[=](){ui->mygraph->update();
                                                    ptremained++;});
                    flag = 1;
                    ui->mygraph->repaint();
                    t->start();
                    init_flag = false;
            }else{
                   QMessageBox::warning(this,"Warning","Please check your input",QMessageBox::Yes);
                   rept_flag = false;

                }
        }else{
            init_flag = false;
            QMessageBox::warning(this,"Warning","Please click initialize at first",QMessageBox::Yes);

        }
        //prevent double click simulate

    }
}

/*
*Function usage:when button "clear" is clicked
*----------
*/
///New Change
void SchWidget::on_clear_clicked()
{
    ui->table_of_process->clear();
    ui->spinBox->setValue(0);


    bq.clear();
    pq.clear();
    aq.clear();
    if(t != nullptr){
        t->stop();
    }
    colorvec.clear();

    graphlenvec.clear();
    graphlenvec.push_back(0);
    init_flag =false;
    rept_flag = false;
    ptremained = 0;
    delete s;
    s = nullptr;
    if(s == nullptr){
        cout<<"empty null"<<endl;
    }
    initgraph();
}
/*
*Function usage:return process number
*----------
*/
int SchWidget::returnprocessnum(){
    return number_of_process;
}

///need change:实现在timer的调用下
bool SchWidget::eventFilter(QObject *watched, QEvent *event)
 {
    if(watched == ui->mygraph && event->type() == QEvent::Paint && flag == 1)
       {
        int graphlen = graphlenvec[graphlenvec.size()-1];
        QPainter painter(ui->mygraph);
        painter.setPen(Qt::black);
        cout<<"exec length:"<<execQ.size()<<endl;
        for(int i = 0; i <execQ.size();i++){
            if(execQ[i]->pid!= -1){
                QBrush * brush = new QBrush(*colorvec[(execQ[i])->pid-1]);
                 cout<<"pid is"<<(execQ[i])->pid<<endl;
                 painter.setBrush(*brush);
                 painter.drawRect(graphlen,40,5*(execQ[i]->timeRemain),100);
                 graphlen += 5*(execQ[i]->timeRemain);
            }
            else{
                painter.setPen(Qt::black);
                painter.setBrush(Qt::GlobalColor::transparent);
                painter.drawRect(graphlen,40,5,100);
                graphlen += 5;
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

void SchWidget::printcolor_map(){
    map<string,QColor*>::iterator it = color_map.begin();
    for(it; it!= color_map.end(); it++){
        std::cout<<(*it).first<<std::endl;
    }
}

void SchWidget::initcolorvec(){
    for(int i = 0; i< number_of_process;i++){
        colorvec.push_back(new QColor(rand()%(255 - 0 +1),rand()%(255 - 0 +1),rand()%(255 - 0 +1)));
    }
    cout<<"color vec size is"<< colorvec.size()<<endl;

}

void SchWidget::inittable(){
    //初始化表格
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
    s = new scheduling;
    init_flag = true;
    cout <<"initialized"<<endl;
}

void SchWidget::on_timeslice_textEdited(const QString &arg1)
{
    timeslice = arg1.toInt();
}


/*
* CPU::Connection
* -------------------------------------------
*/

//void Widget::set_CPU(cpuMon * cpu){
//    CPU=cpu;
//    CPU->createP(PID,"Schdedule",root);
//}


//void Widget::setPID(int pid){
//    PID=pid;
//}

//void Widget::mousePressEvent(QMouseEvent *e){
//    to_simple_Click();
//    system_timer->start(100);
//}

//void Widget::mouseMoveEvent(QMouseEvent *e)
//{
//    to_moving_around();
//    system_timer->start(100);
//}

//void Widget::back_to_fluctuation(){
//    CPU->operationDet(PID,fluctuation);
//}


//void Widget::to_effect_Click(){
//    CPU->operationDet(PID,effectClick);
//    system_timer->start(100);
//}

//void Widget::to_simple_Click(){
//    CPU->operationDet(PID,simpleClick);
//    system_timer->start(100);
//}

//void Widget::to_moving_around(){
//    CPU->operationDet(PID,movingAround);
//    system_timer->start(100);
//}

//void Widget::refresh(){
//    CPU->operationDet(PID,refreshing);
//    system_timer->start(100);
//}

//void Widget::sleeping(){
//    if (CPU->isBusy()){
//        sleep(1);
//    }
//}

//void Widget::closeEvent(QCloseEvent *event){
//    CPU->terminateP(PID);
//    if (created){
//    memory->deallocate(PID,memory_size);
//    }
//    event->accept();
//}


//void Widget::set_memory(Buddy *Memory){
//    memory = Memory;
//    if (!memory->allocate(PID,memory_size)){
//        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
//        close();
//    }else{
//        created = true;
//    }
//}

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
