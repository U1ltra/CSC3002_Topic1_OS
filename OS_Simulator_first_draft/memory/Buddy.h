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
    void allocate(m_task &current);
    void deallocate(m_task &current);
    int getsize();
private:
    int index;
    int size;
};

#endif // BUDDY_H
