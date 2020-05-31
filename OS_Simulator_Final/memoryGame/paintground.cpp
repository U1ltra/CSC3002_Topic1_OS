
#include "memoryGame/paintground.h"
#include <iostream>

int tused = 0;

paintGround::paintGround(QWidget *parent) :
    QWidget(parent)
{
    width = 0;
    height = 0;
    startPainting = false;
}

//paintGround::~paintGround(){
//    delete  scroll;

//}

void paintGround::paintEvent(QPaintEvent *event){
    if (!startPainting) return;
    std::cout << "inside content" << std::endl;
    this->resize(width, height);
    paint = new QPainter(this);
//    paint->setPen(Qt::black);
//    paint->setBrush(Qt::red);           // should be replaced according to passed in colors
//    paint->drawRect(0,0,width,height);
    int count = 0;
    for (map<m_task,int>::iterator it = bd->Bu_map.begin();it!=bd->Bu_map.end();it++){
        paint->setPen(Qt::transparent);
        cout << "inside paintevent: " << (*colors)[0] << endl;
        cout << "aaaaaaaaaaaaa1 " << it->first.starting_Address << " aaaaaaaaaa2 " << it->second << endl;
        paint->setBrush(QBrush(QColor((*colors)[count*3], (*colors)[count*3+1], (*colors)[count*3+2])));
        paint->drawRect(0,double((it->first.starting_Address))/(bd->getsize())*height,width,double((it->second))/(bd->getsize())*height);
        tused += it->second;
        count++;
    }
    TUsed->setText(QString("%1 %2").arg("Total Used: ").arg(QString::number(tused)));
//    TUsed->update();
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
    cout << "inside setColors: " << (*colours)[0] << endl;
    colors = colours;
}

void paintGround::setUsedPrt(QLabel * usedPr){
    TUsed = usedPr;
}

void paintGround::switchStatus(bool status){
    startPainting = status;
}


