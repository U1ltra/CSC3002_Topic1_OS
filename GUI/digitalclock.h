#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QAbstractItemModel>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
     DigitalClock();
     void setID(int id);
     QString getID();

private:
     QTimer clock_timer;
     int pid;
private slots:
     void ontimeout();
};

#endif // DIGITALCLOCK_H
