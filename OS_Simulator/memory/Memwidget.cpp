
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
        this->setFixedSize(600,500);
        ui->scrollAreaWidgetContents->installEventFilter(this);
        //设置表格内容
        ui->tableWidget->setColumnCount(3);

        //设置表头内容
         inittable();

         flag = 0;//event filter
         init_flag = false;//initialize memory
         success_flag = true;//allocate memory success
         clear_flag = true;
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
        cout <<clear_flag<<endl;
        if(clear_flag == true){
            if(bd->getsize() >0 && bd->getsize() != 32766 ){
                cout<<"******************^^^^^^^^^^^"<<endl;
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);
            tasknumber = 0;
            flag = 2;
            task_vector.clear();
            promptvec.clear();


            delete bd;
            bd = nullptr;

            tused = 0;
            ui->currentused->setText(QString::number(tused));
            ui->currentused->displayText();
            ui->scrollAreaWidgetContents->repaint();
            cout<<"******************^^^^^^^^^^^"<<endl;

            ui->memorystorage->setText("");
            ui->spinBox->setValue(0);

            init_flag = false;
            success_flag = true;
            clear_flag = false;
        }
      }
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
        clear_flag = true;
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

                promptvec.push_back(new QString("Memory from " +QString::number(it->lb) +" to " + QString::number(it->ub) + " allocated"));
                tused += it->ub+1 - it->lb;
                ui->currentused->setText(QString::number(bd->getsize()-tused));
                ui->currentused->displayText();
            }


        }
        tused = 0;
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
        clear_flag = true;
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
                if(ui->tableWidget->item(i,1) != NULL &&ui->tableWidget->item(i,2) != NULL &&ui->tableWidget->item(i,2)->text().toInt() > 0
                        &&ui->tableWidget->item(i,2)->text().toInt() <= bd->getsize()){
                std::cout<<"****"<<i<<"*******"<<std::endl;
                task_vector.push_back(new m_task(atoi(ui->tableWidget->item(i,1)->text().toStdString().c_str()),
                                                atoi(ui->tableWidget->item(i,2)->text().toStdString().c_str())));
                std::cout<<"**Pid**"<<ui->tableWidget->item(i,1)->text().toInt()<<"*******"<<std::endl;
                std::cout<<"**memory**"<<ui->tableWidget->item(i,2)->text().toInt()<<"*******"<<std::endl;
            }
                else{
                    success_flag = false;
                    break;
                    cout<<"走到这里";
                }
            }
            if(success_flag == true){
                //check whether allocate successfully
                for(int i = 0;i<tasknumber;i++){
                    if(!bd->allocate(*task_vector[i])){
                        success_flag = false;
                        }
                    }
                ui->scrollAreaWidgetContents->update();
            }else{
                QMessageBox::warning(this,"Warning","Fail to allocate memory");
                }
            }
        }else{
            QMessageBox::warning(this,"Warning", "Please Input the Memory Size at first", QMessageBox::Ok);
        }
        clear_flag = true;
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

    void Mem_Widget::on_change_clicked()
    {
    //    subwidget sub;

    //    sub.show();
        clear_flag = true;
    }

    void Mem_Widget::on_memorystorage_editingFinished()
    {
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
        }
        else{
            QMessageBox::warning(this,"Warning","Fail to initialize memory",QMessageBox::Ok);
        }
        clear_flag = true;
    }
    void Mem_Widget::resizeEvent(QResizeEvent *event){
        ui->scrollAreaWidgetContents->repaint();
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


