#include "home/login_interface.h"
#include "home/mainwindow.h"
#include "app/calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_interface login;
    login.showFullScreen();
    //login.show();

    return a.exec();
}
