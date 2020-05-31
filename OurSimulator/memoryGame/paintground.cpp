
/*
 * File:" paintground.cpp
 * ----------------------
 * This file defines the widget class <code>playground</code>
 * which is going to be painted on.
 */

#include "memoryGame/paintground.h"

int tused = 0;

paintGround::paintGround(QWidget *parent) :
    QWidget(parent)
{
    width = 0;
    height = 0;
    startPainting = false;
}

void paintGround::paintEvent(QPaintEvent *event){
    if (!startPainting) return;
    this->resize(width, height);
    paint = new QPainter(this);
    int count = 0;
    for (map<m_task,int>::iterator it = bd->Bu_map.begin();it!=bd->Bu_map.end();it++){
        paint->setPen(Qt::transparent);
        paint->setBrush(QBrush(QColor((*colors)[count*3], (*colors)[count*3+1], (*colors)[count*3+2])));
        paint->drawRect(0,double((it->first.starting_Address))/(bd->getsize())*height,width,double((it->second))/(bd->getsize())*height);
        tused += it->second;
        count++;
    }
    TUsed->setText(QString("%1 %2").arg("Total Used: ").arg(QString::number(tused)));
    tused = 0;
    delete paint;
}

void paintGround::setSize(int w, int h){
    width = w;
    height = h;
    this->resize(width, height);
}

void paintGround::setBD(Buddy * mem){
    bd = mem;
}

void paintGround::setColors(vector<int> * colours){
    colors = colours;
}

void paintGround::setUsedPrt(QLabel * usedPr){
    TUsed = usedPr;
}

void paintGround::switchStatus(bool status){
    startPainting = status;
}


