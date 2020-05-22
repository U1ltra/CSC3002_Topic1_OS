#include "login_interface.h"
#include "mainwindow.h"
#include "ui_login_interface.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

login_interface::login_interface(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ParentBook = QMap<QString,QString>();
    ChildrenBook = QMap<QString,QString>();
    ParentBook.insert("parent","1");
    ChildrenBook.insert("child","1");
    this->setWindowTitle("Login Page");
    mw = new MainWindow();
}

login_interface::~login_interface()
{
    delete ui;
}

void login_interface::on_login_btn_Login_clicked()
{
    username = ui->UserName->text();
    password = ui->Password->text();
    if (parentMode_active) {
        if (ParentBook.contains(username) && password.trimmed() == ParentBook.find(username)->trimmed()) {
            parent_accept();
        }else {
            QMessageBox::critical(this,"Login Failure","Invalid Password");
            ui->UserName->clear();
            ui->Password->clear();
            ui->UserName->setFocus();
        }
    }else {
        if (ChildrenBook.contains(username) && password.trimmed() == ChildrenBook.find(username)->trimmed()) {
            children_accept();
        }else {
            QMessageBox::critical(this,"Login Failure","Invalid Password");
            ui->UserName->clear();
            ui->Password->clear();
            ui->UserName->setFocus();
        }
    }
}

void login_interface::on_Parent_Mode_clicked()
{
    parentMode_active = !parentMode_active;
}

void login_interface::parent_accept(){
    this->close();
    mw->show();
}

void login_interface::children_accept(){
    this->close();
    mw->show();
    QTimer::singleShot(15*60000, this, SLOT(closeWindow()));
}

void login_interface::closeWindow() {
    mw->close();
}

void login_interface::on_login_btn_Shutdown_clicked()
{
    this->close();
}

void login_interface::on_Password_returnPressed()
{
    login_interface::on_login_btn_Login_clicked();
}
