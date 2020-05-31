
/*
 * File: paintGround.h
 * -------------------
 * This file exports the painting area for memory game.
 */

#ifndef PAINTGROUND_H
#define PAINTGROUND_H

#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include "memoryGame/Buddy.h"

class paintGround : public QWidget
{
    Q_OBJECT

public:
    //    explicit paintGround(QWidget *parent = nullptr);
    paintGround(QWidget * parent = nullptr);
    ~paintGround()=default;

    /*
     * Used to set the size of the carvus
     */
    void setSize(int width, int height);

    /*
     * Pass in the memory algorithm object
     */
    void setBD(Buddy *);

    /*
     * Pass in the colors selected
     */
    void setColors(vector<int> * colours);

    /*
     * Pass in the pointer to the used label. Simplify
     * the coding work
     */
    void setUsedPrt(QLabel * usedPr);

    /*
     * Control the painting event
     */
    void switchStatus(bool status);

    /*
     * Rewrite paint event function to draw self defined
     * function
     */
    void paintEvent(QPaintEvent *event) override;

private:

    QLabel * TUsed;
    QPainter * paint;
    Buddy * bd;

    int width;
    int height;
    bool startPainting;
    std::vector<int> * colors;           // random colors

};


#endif // PAINTGROUND_H
