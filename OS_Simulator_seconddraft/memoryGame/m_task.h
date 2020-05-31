/*
 * File: m_task.h
 * -------------
 * This interface exports the m_task class, which is used
 * to connect to operating's GUI system.
 */

#ifndef M_TASK_H
#define M_TASK_H

class m_task{
public:
    int PID;
    int memory;
    int starting_Address;

    /*
     * Constructor: m_task
     * Usage: m_task(int ID, int size)
     * ------------------------
     * Creates a m_task object. The constructor sets PID of the
     * task to be ID, and memory space of the task to be size.
     */
    m_task(int ID, int size);
    bool operator< (const m_task &t)const;
};


#endif // M_TASK_H
