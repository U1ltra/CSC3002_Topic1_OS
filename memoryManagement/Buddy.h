#ifndef BUDDY_H
#define BUDDY_H
#include <pair.h>
#include <vector>
#include <list>
#include <map>
#include <m_task.h>
using namespace std;

class Buddy{
public:
    Buddy(int s);

    vector<list<Pair>> arr;
    map<m_task,int> Bu_map;

    bool allocate(int PID,int size);
    bool allocate(m_task &current);
    bool deallocate(m_task &current);
    bool deallocate(int PID,int size);
    int getsize();

private:
    int index;
    int size;
};

#endif // BUDDY_H
