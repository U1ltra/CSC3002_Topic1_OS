#include "widget.h"
#include "scheduling.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SchWidget w;
    w.show();



    return a.exec();
}
