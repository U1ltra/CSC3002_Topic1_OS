
/*
 * File: main.cpp
 * --------------
 * Our operating system starts with constructing login
 * interface.
 */

#include <QApplication>
#include "app/calculator.h"
#include "home/mainwindow.h"
#include "home/login_interface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_interface login;
    login.showFullScreen();
    return a.exec();
}
