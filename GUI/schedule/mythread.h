#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include"widget.h"
class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = 0);

    void drawImage();
signals:
    void updateimage(Widget&);


public slots:
};

#endif // MYTHREAD_H
