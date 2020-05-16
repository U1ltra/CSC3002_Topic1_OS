#include "mainwindow.h"
#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Calculator cal;
    cal.show();
    return a.exec();
}
