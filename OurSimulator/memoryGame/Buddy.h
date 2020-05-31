
/*
 * File: Buddy.h
 * -------------
 * This is the core header file for memory system. It helps allocate
 * and deallocate memory space for tasks with specific PIDs and memory
 * sizes. Also, an interface is given to GUI and helps monitor apps in
 * operating system.
 */

#ifndef BUDDY_H
#define BUDDY_H

#include <map>
#include <list>
#include <vector>
#include "memoryGame/pair.h"
#include "memoryGame/m_task.h"

using namespace std;

class Buddy{
public:
    /*
     * Constructor: Buddy
     * Usage: Buddy(int s)
     * ------------------------
     * Creates a Buddy object. The constructor sets the memory
     * system to be of size s.
     */
    Buddy(int s);

    vector<list<Pair>> arr; //The vector to store unused blocks
    map<m_task,int> Bu_map; //The map that assign memory size to tasks

    /*
     * Method: mem_allocation
     * Usage: bool b = bd.mem_allocation(int PID, int size)
     *        bool b = bd.mem_allocation(m_task &current)
     * ----------------------------------
     * allocates a task with specific PID and size into the memory system.
     * Returns true if current space is valid for allocation, else return false.
     * The return value is mainly for GUI to jump the message box and warn
     * the memory error.
     */
    bool mem_allocation(int PID,int size);
    bool mem_allocation(m_task &current);

    /*
     * Method: deallocate
     * Usage: bool b = bd.deallocate(int PID, int size)
     *        bool b = bd.deallocate(m_task &current)
     * ----------------------------------
     * Deallocates a specific task. If no such task exists, return false.
     */
    bool deallocate(m_task &current);
    bool deallocate(int PID,int size);

    /*
     * Method: getsize
     * Usage: int i = bd.getsize()
     * ----------------------------------
     * Returns the size of memory system.
     */
    int getsize();

private:
    int index;
    int size;//size of the memory system

    /*
     * Method: merge
     * Usage: bd.merge()
     * ----------------------------------
     * Helps deallocate memory space recursively.
     */
    void merge(int num, int index);
};

#endif // BUDDY_H
