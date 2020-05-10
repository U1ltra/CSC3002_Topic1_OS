#include "login_interface.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login_interface mw;
    mw.show();
    w.show();
    return a.exec();
}
