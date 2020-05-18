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


private:
     QTimer clock_timer;

private slots:
     void ontimeout();
};

#endif // DIGITALCLOCK_H
