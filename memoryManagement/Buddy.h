#ifndef BUDDY_H
#define BUDDY_H
#include <pair.h>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Buddy{
public:
    int size;
    vector<list<Pair>> arr;
    map<int,int> Bu_map;
    Buddy(int s);
    void allocate(int s);
    void deallocate(int index);
};

#endif // BUDDY_H
