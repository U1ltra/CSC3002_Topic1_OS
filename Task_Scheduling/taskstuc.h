
/* File: taskstuc.h
 * ----------------
 * This file exports taskstuc class. And comparison functions based on task structure.
 */

#ifndef TASKSTUC_H
#define TASKSTUC_H

#include <string>

class taskStuc
{
public:
    // constructors. no need for destructor since no heap memory is allocated
    taskStuc();
    taskStuc(int, int, int, int, int);
    taskStuc(taskStuc &);

    // comparison - for FCFS
    bool operator()(taskStuc, taskStuc);

    // get functoins
    int getAttributes(std::string);

    int setAttributes(std::string, int);

private:

    int pid;            // identity of tasks, which is according to the creating order of the task. basically is just for reference
    int brustime;       // time needed for the task to finish running
    int priority;       // priority of different tasks

    int arrivaltime;    // determine the time of arrival of the given task, which will affect the remaining time of other tasks
    int arrivalq;       // indicates the order of arrival of tasks, not considering the specific time of arrival. used for FCFS

};


bool cmp1(taskStuc, taskStuc);
bool cmp2(taskStuc, taskStuc);
bool cmp3(taskStuc, taskStuc);


#endif // TASKSTUC_H
