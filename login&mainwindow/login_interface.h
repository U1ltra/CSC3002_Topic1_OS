#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QMap>

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

private:
    Ui::Widget *ui;
    // Instance Variable //
    bool parentMode_active = true;
    QString password;
    QString username;


    QMap<QString,QString> ParentBook;
    QMap<QString,QString> ChildrenBook;

    void parent_accept();
    void children_accept();
};
#endif // WIDGET_H
