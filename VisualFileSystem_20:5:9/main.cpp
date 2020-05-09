#include "visualfilemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VisualFileManager w;
    w.show();
    return a.exec();
}
