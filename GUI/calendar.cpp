#include "calendar.h"
#include <QCalendarWidget>
Calendar::Calendar()
    : QCalendarWidget()
{

}

void Calendar::setID(int id){
    pid = id;
}

QString Calendar::getID(){
    return "Calendar"+QString::number(pid);
}
