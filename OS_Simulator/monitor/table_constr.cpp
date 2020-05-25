
/*
 * File: table_constr.cpp
 * ----------------------
 * This file implements the supportive class, <code>table_constr</code>.
 */

//#include
#include <QStandardItemModel>
#include <monitor/table_constr.h>

using namespace std;


stdTable::stdTable(int rowN, int colN){       // create the table modle and a two dimensional array for items storing
    table = new QStandardItemModel;
    items = new QStandardItem * [colN];
    for (int i=0; i<rowN; i++){
        items[i] = new QStandardItem [rowN];
    }
    rows = rowN;
    cols = colN;
}

stdTable::~stdTable(){
    delete  table;
    for (int i=0; i<rows; i++){
        delete [] items[i];
    }
    delete [] items;
}

int stdTable::setTitle(vector<QVariant>, vector<QVariant>){

}



