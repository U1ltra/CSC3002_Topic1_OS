#include "login_interface.h"
#include "mainwindow.h"
#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login_interface mw;
    Calculator calc;
    mw.show();
    w.show();
    calc.show();
    return a.exec();
}
