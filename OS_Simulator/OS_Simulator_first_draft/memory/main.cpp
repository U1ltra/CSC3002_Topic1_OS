#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mem_Widget w;
    w.show();

    return a.exec();
}
