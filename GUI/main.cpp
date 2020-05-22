#include "login_interface.h"
#include "mainwindow.h"
#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_interface login;
    login.show();

    return a.exec();
}
