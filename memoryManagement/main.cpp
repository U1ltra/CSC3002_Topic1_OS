#include <iostream>
#include "math.h"
#include <list>
#include <pair.h>
#include <Buddy.h>
#include <m_task.h>
using namespace std;

int main(){
    int ini = 128;
    Buddy obj = Buddy(128);
    m_task task1(10086,15);
    m_task task2(10010,16);
    m_task task3(11111,16);
    m_task task4(11123,16);
    obj.allocate(task1);
    obj.allocate(task2);
    obj.allocate(task3);
    obj.allocate(task4);
    obj.deallocate(task1);
    obj.deallocate(task3);
    obj.deallocate(task2);

    return 0;
}





