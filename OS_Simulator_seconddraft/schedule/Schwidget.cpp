#include "schedule/Schwidget.h"
#include "ui_Schwidget.h"
#include <QString>
#include <QList>
#include <QStringList>
#include <QScrollBar>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QTextEdit>
#include <unistd.h>
#include <QMessageBox>
#include "monitor/cpuMon.h"

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
    allow_to_init = true;//prevent double click simulate

    graphlenvec.push_back(0);

    system_timer = new QTimer(this);
    setMouseTracking(true);
    on_initialize_clicked();
}

SchWidget::~SchWidget()
{
    delete ui;
    delete s;
    s = nullptr;
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
        if(s != nullptr && init_flag == true&&number_of_process != 0){//able to simulate
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
                                ui->table_of_process->item(i,3) != NULL
                                && repetitiondetect(ui->table_of_process->item(i,2)->text().toInt(),aq)&&checkempyt(i,1,3)
                                &&repetitiondetect(ui->table_of_process->item(i,3)->text().toInt(),aq)){//一定要先判断非空，否则会报错
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
                }else{//inable to print picture
                       QMessageBox::warning(this,"Warning","Please check your input",QMessageBox::Yes);
                       rept_flag = false;
                    }
        }else{//inable to simulate
            init_flag = false;
            QMessageBox::warning(this,"Warning","Please clear and initialize at first",QMessageBox::Yes);
        }
        //prevent double click simulate

    }
}

/*
*Function usage:when button "clear" is clicked
*----------
*/

void SchWidget::on_clear_clicked()
{
    cout<<"iii"<<endl;
    if(t != nullptr){
        t->stop();
    }
    cout<<"iii"<<endl;
    ui->table_of_process->clear();
    ui->spinBox->setValue(0);
cout<<"iii"<<endl;

    bq.clear();
    pq.clear();
    aq.clear();
cout<<"iii"<<endl;
    colorvec.clear();

    graphlenvec.clear();
    graphlenvec.push_back(0);
    init_flag =false;
    rept_flag = false;
    ptremained = 0;
    cout<<"iii"<<endl;
    delete s;
    s = nullptr;
    if(s == nullptr){
        cout<<"empty null"<<endl;
    }
    allow_to_init = true;
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
    if(allow_to_init == true){
        s = new scheduling;
        init_flag = true;
        cout <<"initialized"<<endl;
        allow_to_init = false;
    }else{
        QMessageBox::warning(this,"Warning","You cannot initialize for now. You should clear first.");
    }
}

void SchWidget::on_timeslice_textEdited(const QString &arg1)
{
    timeslice = arg1.toInt();
}


/*
* CPU::Connection
* -------------------------------------------
*/

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

