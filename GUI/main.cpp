#include "login_interface.h"
#include "mainwindow.h"
#include "calculator.h"
#include <QApplication>
#include "texteditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_interface login;
    TextEditor te;
    te.show();
    //login.show();

    return a.exec();
}
