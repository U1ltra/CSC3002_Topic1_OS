#ifndef M_TASK_H
#define M_TASK_H

class m_task{
public:
    int PID;
    int memory;
    int starting_Address;
    m_task(int ID, int size);
    bool operator< (const m_task &t)const;
};


#endif // M_TASK_H
