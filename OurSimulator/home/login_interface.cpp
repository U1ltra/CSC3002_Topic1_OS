
/*
 * File: login_interface.cpp
 * -------------------------
 * This file implements the login_interface.h interface.
 */

#include <QMessageBox>
#include "ui_login_interface.h"
#include "home/login_interface.h"

const QFont LabelF = QFont("Helvatica", 18);
const QPalette LabelP = QPalette(QPalette::WindowText, Qt::white);
int CHILDTIME = 7000;

login_interface::login_interface(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /* Set background */
    this->setWindowTitle("Login Page");
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->label->setFont(LabelF);
    ui->label_2->setFont(LabelF);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/images/background.jpg")));
    this->setPalette(pal);
    ui->label->setFont(LabelF);
    ui->label_2->setFont(LabelF);

    /* Set the username and passward. */
    ParentBook = QMap<QString,QString>();
    ChildrenBook = QMap<QString,QString>();
    ParentBook.insert("parent","1");
    ChildrenBook.insert("child","1");

    mw.installEventFilter(this);
}

login_interface::~login_interface()
{
    delete ui;
}

/* Private Slots */

/*
 * Implementation notes: on_login_btn_Login_clicked
 * ------------------------------------------------
 * Based on the selected mode, compare user's input to the pair of username and
 * passward in corresponding QMap and log in corresponding system.
 */

void login_interface::on_login_btn_Login_clicked()
{
    username = ui->UserName->text();
    password = ui->Password->text();
    if (parentMode_active) {  // Parent mode
        if (ParentBook.contains(username) && password.trimmed() == ParentBook.find(username)->trimmed()) {
            parent_accept();
        } else {
            QMessageBox::critical(this,"Login Failure","Invalid Password");
            ui->UserName->clear();
            ui->Password->clear();
            ui->UserName->setFocus();
        }
    } else {                  // Child mode
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
    mw.showFullScreen();
    mw.logging(true);
}

/*
 * Implementation notes: children_accept
 * -------------------------------------
 * This system will automatically log out and shut down in 15 minutes by
 * using QTimer.
 */

void login_interface::children_accept(){
    this->close();
    mw.showFullScreen();
    mw.isChildM();
    mw.logging(true);
    QTimer::singleShot(CHILDTIME, this, SLOT(closeWindow()));
}

void login_interface::closeWindow() {
    mw.close();
}

void login_interface::on_login_btn_Shutdown_clicked()
{
    mw.close();
    this->close();
}

void login_interface::on_Password_returnPressed()
{
    login_interface::on_login_btn_Login_clicked();
}

bool login_interface::eventFilter(QObject *watched, QEvent *event){
    if (watched == &mw && event->type() == QEvent::Close){
        this->close();
    }
    return false;
}
