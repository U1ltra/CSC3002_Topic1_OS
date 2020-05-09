
/* File: taskstuc.cpp
 * ------------------
 * This file implements taskstuc class.
 * And functions making comparison on taskstuc objects data field.
 */

#include "taskstuc.h"


const int INITIAL = 0;


taskStuc::taskStuc(){

    pid = INITIAL;
    brustime = INITIAL;
    priority = INITIAL;
    arrivaltime = INITIAL;
    arrivalq = INITIAL;
}


taskStuc::taskStuc(int _pid, int _brust, int _priority, int _arrT, int _arrQ){

    pid = _pid;
    brustime = _brust;
    priority = _priority;
    arrivaltime = _arrT;
    arrivalq = _arrQ;
}


taskStuc::taskStuc(taskStuc & tS){

    pid = tS.pid;
    brustime = tS.brustime;
    priority = tS.priority;
    arrivaltime = tS.arrivaltime;
    arrivalq = tS.arrivalq;
}


bool taskStuc::operator()(taskStuc a, taskStuc b){
    return a.arrivalq < b.arrivalq;
}


int taskStuc::getAttributes(std::string Vname){
    int value;
    if (Vname == "pid")                 value = pid;
    else if (Vname == "brustime")       value = brustime;
    else if (Vname == "priority")       value = priority;
    else if (Vname == "arrivaltime")    value = arrivaltime;
    else if (Vname =="arrivalq")        value = arrivalq;
    else                                return 0;

    return value;
}


int taskStuc::setAttributes(std::string Attrname, int Attrvalue){
    if (Attrname == "pid")                  pid = Attrvalue;
    else if (Attrname == "brustime")        brustime = Attrvalue;
    else if (Attrname == "priority")        priority = Attrvalue;
    else if (Attrname == "arrivaltime")     arrivaltime = arrivaltime;
    else if (Attrname =="arrivalq")         arrivalq = arrivalq;
    else                                return 0;
}


bool cmp1(taskStuc a, taskStuc b){
    if (a.getAttributes("brustime") == b.getAttributes("brustime")) {
        return a.getAttributes("pid") < b.getAttributes("pid");
    }
    return  a.getAttributes("brustime") < b.getAttributes(("brustimg"));
}


bool cmp2(taskStuc a, taskStuc b){
    return  a.getAttributes("arrivaltime") < b.getAttributes("arrivaltime");
}


bool cmp3(taskStuc a, taskStuc b){
    if (a.getAttributes("priority") == b.getAttributes("priority")) {
        return a.getAttributes("pid") < b.getAttributes("pid");
    }
    return a.getAttributes("priority") < b.getAttributes("priority");
}



