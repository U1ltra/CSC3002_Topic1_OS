
/*
 * File: table_constr.cpp
 * ----------------------
 * This file implements the supportive class, <code>table_constr</code>.
 */

#include <QList>
#include <exception>
#include <memoryGame/table_constr.h>

using namespace std;

const QVariant ATTRIBUTES = "ATTR";                                 // consider changing this part to using <code>extern</code>
const QVariant PID = "PID";
const QVariant USER = "User";
const QVariant CPUPER = "CPU %";
const QVariant THREAD = "Thread";
const QVariant CPUTIME = "CPU Time";
const QVariant PNAME = "Process Name";
const QVariant IDLEW = "Idle wake ups";

stdTable::stdTable(){
    table = new QStandardItemModel;
}

stdTable::stdTable(int rowN, int colN){                             // create the table modle and a two dimensional array for items storing
    table = new QStandardItemModel;
    table->setRowCount(rowN);
    table->setColumnCount(colN);

    items = new vector<vector<QStandardItem*>> (rowN, vector<QStandardItem*>(colN));
    for (int i=0; i<colN; i++){
        for (int j=0; j<rowN; j++){
            (*items)[j][i] = new QStandardItem;
            table->setItem(j, i, (*items)[j][i]);                   // fit the item objects into the table
        }
    }

    rows = rowN;                                                    // record dimension info
    cols = colN;
    initialized=true;
}

void stdTable::setTable(int rowN, int colN){
    table->setRowCount(rowN);
    table->setColumnCount(colN);

    items = new vector<vector<QStandardItem*>> (rowN, vector<QStandardItem*>(colN));
    for (int i=0; i<colN; i++){
        for (int j=0; j<rowN; j++){
            (*items)[j][i] = new QStandardItem;
            table->setItem(j, i, (*items)[j][i]);                   // fit the item objects into the table

        }
    }

    rows = rowN;                                                    // record dimension info
    cols = colN;
    initialized=true;
}

int stdTable::setTitle(vector<const QVariant> rowNames, vector<const QVariant> colNames){
    if (!initialized) throw "object have not initialized";

    for (int i=0; i<rows; i++){
        table->setHeaderData(i, Qt::Vertical, i);                   // process names is already one of the column
    }
    for (int i=0; i<cols; i++){
        table->setHeaderData(i, Qt::Horizontal, colNames[i]);
    }
    return 0;
}

int stdTable::tableChange(int col, std::vector<const QVariant> values){
    if (!initialized) throw "object have not initialized";

    for (int i=0; i<rows; i++){                                     // set all rows of a given column a time
        //        std::cout << "am i here?: " << i << " " << col << endl;
        ((*items)[i][col])->setText(values[i].toString());          // QVariant to QString, text need to be QString
        //        if (i==rows-1) qDebug() << values[i].toString();
    }
    return 0;
}

int stdTable::cpuMon2table(cpuMon * CPU){
    if (!initialized) throw "object have not initialized";

    vector<const QVariant> colNames = CPU->getAttributesQ(ATTRIBUTES);
    for (int i=0; i<cols; i++){                                     // get the QVariant queue storing the values of given
        tableChange(i, CPU->getAttributesQ(colNames[i]));           // <code>colName</code> (attribute names) and pass it into
    }                                                               // <code>tableChange</code> to set the table items. The visualization
    return 0;                                                       // refering to the table pointer, as a result, could be updated.
}

int stdTable::game2table(){
    if (!initialized) throw "object have not initialized";

    return 0;
}

QStandardItemModel * stdTable::getTable(){
    if (!initialized) throw "object have not initialized";
    return table;
}

int stdTable::getRowN(){
    if (!initialized) throw "object have not initialized";
    return rows;
}

int stdTable::getColN(){
    if (!initialized) throw "object have not initialized";
    return  cols;
}

QString stdTable::getData(int row, int col){
    return (*items)[row][col]->text();
}

void stdTable::setColor(int col, vector<int> * colors){
    for (int i=0; i<rows; i++){
        int RGB1 = (*colors)[i*3];
        int RGB2 = (*colors)[i*3+1];
        int RGB3 = (*colors)[i*3+2];
        (*items)[i][cols-1]->setBackground(QBrush(QColor(RGB1, RGB2, RGB3)));
    }
}


