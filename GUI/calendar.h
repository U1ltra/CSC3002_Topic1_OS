#ifndef CALENDAR_H
#define CALENDAR_H

#include <QAbstractItemModel>
#include <QCalendarWidget>
class Calendar : public QCalendarWidget
{
    Q_OBJECT

public:
    explicit Calendar();
    void setID(int id);
    QString getID();

private:
    int pid;
};

#endif // CALENDAR_H
