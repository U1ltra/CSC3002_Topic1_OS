
/*
 * File: pair.h
 * -------------
 * A pair represents a block, with lb meaning lower bound
 * of the block and ub meaning upper bound.
 */

#ifndef PAIR_H
#define PAIR_H

class Pair{
public:

    int lb;        //lower bound of the memory slice
    int ub;        //upper bound of the memory slice

    /*
     * Constructor: pair
     * Usage: Pair(int a, int b)
     * ----------------------------------------------------
     * Creates the pair object with lower bound of a and upper bound of
     * b.
     */
    Pair(int a, int b);
};

#endif // PAIR_H
