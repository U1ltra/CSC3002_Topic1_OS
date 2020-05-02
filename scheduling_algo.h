
/* File: schedule_algo.h
 * ---------------------
 * This file exports several traditional task scheduling algorithm.
 */

#ifndef SCHEDULING_ALGO_H
#define SCHEDULING_ALGO_H

// First-Come First-Served Scheduling //
int FCFS();

// Shortest-Job First Scheduling //
int SJF();

// Shortest-Process Next Scheduling //
int SPN();

// Shortest- Remaining Time Scheduling //
int SRT();

// Highest-Response Ratio Next Scheduling //
int HRRN();

// Round_Robin Scheduling //
int RR();

// Multipule-Feedback Queque Scheduling //
int MFQ();

// Fair-Sharing Scheduling //
int FSS();


#endif // SCHEDULING_ALGO_H
