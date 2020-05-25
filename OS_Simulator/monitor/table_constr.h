
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


/*
 * Class: stdTable
 * ---------------
 * This class builds a standard table model and provides convenient
 * ways to help the data updating of the constructed table.
 */
class stdTable{

public:

    stdTable(int, int);

    ~stdTable();

    /*
     * Set the row and column title of the table according to the
     * given vector storing names.
     * Use template in order to match definition of <code>getAttributes</code>
     * in cpuMon class.
     */
    int setTitle(std::vector<QVariant>, std::vector<QVariant>);

    /*
     * Change the whole column with index <code>col</code> according
     * to the values specified by the given vector
     */
    template<typename ValueType>
    int tableChange(int col, std::vector<ValueType> values);

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

private:

    QStandardItemModel * table;         // the modle object of the table
    QStandardItem ** items;             // two dimensional array storing the items
    cpuMon * CPU;                       // if no need to support scheduling, i could add a cpuMon here
    int rows;
    int cols;

    /*
     * Illegalize normal and copying construction
     */
    stdTable();
    stdTable(stdTable &);

};


template<typename ValueType>
int setTitle(std::vector<ValueType> rowNames, std::vector<ValueType> colNames){

}



//// function prototype //

///*
// * Construct a M * N table. Set row and column names
// */
//template<typename ValueType>
//QStandardItemModel * tableConstr(int,int,std::vector<QVariant>, std::vector<QVariant>);

///*
// * Update the data in the given table using the given vector
// */
//template<typename ValueType>
//QStandardItemModel * tableChange(QStandardItemModel*,std::vector<ValueType>);

///*
// * Return the reference to the standard table of current cpu
// * usage statistics
// */
//QStandardItemModel * cpuMon2Table(QStandardItemModel *, cpuMon *);



//// function definition //

//template<typename ValueType>
//QStandardItemModel * tableConstr(std::vector<QVariant> v1, std::vector<QVariant> v2){
//    QStandardItemModel * model = new QStandardItemModel;
//    model->setRowCount(v1.size());
//    model->setColumnCount(v2.size());
//    for (std::vector<QVariant>::size_type i=0; i<v1.size(); i++){
//        model->setHeaderData(i, Qt::Vertical, v1[i]);
//    }
//    for (int i=0; i<v2.size(); i++){
//        model->setHeaderData(i, Qt::Horizontal, v2[i]);
//    }
//    return model;
//}

//template<typename ValueType>
//QStandardItem ** tableChange(int rowN, int colN, QStandardItemModel* model, std::vector<ValueType> queue){
//    QStandardItem ** nest = new QStandardItem* [colN];
//    for (int i=0; i<row; i++){                              // write vertically a time
//        model->setItem(i, col, queue[i]);
//    }
//    return model;
//}

//QStandardItemModel * cpuMon2Table(QStandardItemModel * table, cpuMon * CPU){
//    QStandardItemModel * table1 = tableConstr(CPU->Tprocess(), 7,
//                                             CPU->getAttributesQ("Process_name"), CPU->getAttributesQ("Attr_name"));
//    tableChange(0, CPU->Tprocess(), table, CPU->getAttributesQ(.1));

//}


#endif // TABLE_CONSTR_H
