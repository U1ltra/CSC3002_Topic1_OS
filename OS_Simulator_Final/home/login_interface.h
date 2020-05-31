/*
 * File: login_interface.h
 * -----------------------
 * This file designs the login page of GUI.
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QMap>
#include <QTimer>
#include "home/mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class login_interface : public QWidget
{
    Q_OBJECT

public:
    login_interface(QWidget *parent = nullptr);
    ~login_interface();

private slots:

    void on_login_btn_Login_clicked();

    void on_Parent_Mode_clicked();

    void on_login_btn_Shutdown_clicked();

    void on_Password_returnPressed();

/*
 * Slot Function: closeWindow
 * --------------------------
 * Close the main window in child mode.
 */
    void closeWindow();

private:
    /* Instance Variable */

    Ui::Widget *ui;
    bool parentMode_active = true;          /* If user logs into parent mode.            */
    QString password;
    QString username;
    QMap<QString,QString> ParentBook;       /* The username and password of parent mode. */
    QMap<QString,QString> ChildrenBook;     /* The username and password of child mode.  */
    MainWindow mw;

    /* Private Functions */

    void parent_accept();
    void children_accept();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
};
#endif // WIDGET_H
