#include "login_interface.h"
#include "mainwindow.h"
#include "ui_login_interface.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
login_interface::login_interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ParentBook = QMap<QString,QString>();
    ChildrenBook = QMap<QString,QString>();
    ParentBook.insert("parent","1");
    ChildrenBook.insert("child","1");

}

login_interface::~login_interface()
{
    delete ui;
}

void login_interface::on_login_btn_Login_clicked()
{
    username = ui->UserName->text();
    password = ui->Password->text();
    if (ParentBook.contains(username)){
        if (password.trimmed() == ParentBook.find(username)->trimmed()){
            if (parentMode_active){
                parent_accept();
            }else{
                children_accept();
            }
        }else{
            QMessageBox::critical(this,"Login Failure","Invalid Password");
        }
    }else if (ChildrenBook.contains(username)){
        if (password.trimmed() == ChildrenBook.find(username)->trimmed()){
           children_accept();
        }else{
            QMessageBox::critical(this,"Login Failure","Invalid Password");
        }
    }else{
    QMessageBox::critical(this,"Login Failure","Invalid Username");
    }
}


void login_interface::on_Parent_Mode_clicked()
{
    parentMode_active = !parentMode_active;
}

void login_interface::parent_accept(){
    qDebug()<<"parent_accept"<<endl;
}

void login_interface::children_accept(){
    qDebug()<<"children_accept"<<endl;
}

void login_interface::on_login_btn_Shutdown_clicked()
{
    this->close();
}

void login_interface::on_Password_returnPressed()
{
    login_interface::on_login_btn_Login_clicked();
}
