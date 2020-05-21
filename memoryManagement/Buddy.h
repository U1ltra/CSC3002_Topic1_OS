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
    int size;
    vector<list<Pair>> arr;
    map<m_task,int> Bu_map;
    Buddy(int s);
    bool allocate(m_task &current);
    bool deallocate(m_task &current);
};

#endif // BUDDY_H
