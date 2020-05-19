#include <m_task.h>

m_task::m_task(int ID, int size){
    PID = ID;
    memory = size;
}

bool m_task::operator< (const m_task &t)const{
    return PID < t.PID;
}
