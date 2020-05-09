#include "login_interface.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_interface w;
    MainWindow mw;
    w.show();
    mw.show();
    return a.exec();
}
