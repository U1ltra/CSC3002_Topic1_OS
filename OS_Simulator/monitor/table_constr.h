
/*
 * File: table_constr.h
 * --------------------
 * This file exports a class which organize the data into standard
 * table structure.
 */

#ifndef TABLE_CONSTR_H
#define TABLE_CONSTR_H

#include <vector>
#include <monitor/cpuMon.h>
#include <QStandardItemModel>
///


/*
 * Class: stdTable
 * ---------------
 * This class builds a standard table model and provides convenient
 * ways to help the data updating of the constructed table.
 */
class stdTable{

public:

    stdTable();
    stdTable(int, int);

    ~stdTable() = default;

    /*
     * This function must be called before any other method of this class,
     * if constructor <code>stdTable()</code> is called. This is because
     * with such constructor, the initialization has not completed yet.
     */
    void setTable(int, int);

    /*
     * Set the row and column title of the table according to the
     * given vector storing names.
     * Use template in order to match definition of <code>getAttributes</code>
     * in cpuMon class.
     */
    int setTitle(std::vector<const QVariant>, std::vector<const QVariant>);

    /*
     * Change the whole column with index <code>col</code> according
     * to the values specified by the given vector
     */
    int tableChange(int col, std::vector<const QVariant> values);

    /*
     * This function fills in the statistics of given <code>cpuMon</code>
     * object into the table. Therefore, this is a special interface for
     * our task monitor.
     */
    int cpuMon2table(cpuMon *);

    /*
     * This function fills in the statistics of given <code>scheduling</code>
     * object into the table. Therefore, this is a special interface for our
     * designed game.
     */
    int game2table();

    /*
     * Return the pointer the the constructed standerd table
     */
    QStandardItemModel * getTable();

    /*
     * Return the number of rows of the table model constructed
     */
    int getRowN();

    /*
     * Return the number of columns of the table model constructed
     */
    int getColN();

private:

    std::vector<std::vector<QStandardItem*>> * items;   // all items
    QStandardItemModel * table;                         // the modle object of the table
    cpuMon * CPU;                                       // if no need to support scheduling, i could add a cpuMon here
    int rows;
    int cols;
    bool initialized=false;

    /*
     * Illegalize copying construction
     */
    stdTable(stdTable &);

};


#endif // TABLE_CONSTR_H
