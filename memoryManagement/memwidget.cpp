#include "widget.h"
#include "ui_widget.h"

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
    QPainter painter(ui->scrollAreaWidgetContents);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::blue);


}

void Widget::on_simulate_clicked()
{
    //retrieve data from table
    for(int i = 0; i<tasknumber;i++){
        (*task_vector[i]).PID = ui->tableWidget->item(i,1)->text().toInt();
        (*task_vector[i]).memory = ui->tableWidget->item(i,2)->text().toInt();
    }
    for(int i = 0;i<tasknumber;i++){
        bd->allocate(*task_vector[i]);
    }
    for(int i = 0;i<tasknumber;i++){
        bd->deallocate(*task_vector[i]);
        update();
    }

}

void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    int num = arg1.toInt();
    bd = new Buddy(num);

}
