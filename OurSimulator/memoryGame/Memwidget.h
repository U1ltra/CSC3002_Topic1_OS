
/*
 * File: Memwidget.h
 * -----------------
 * This file exports a memory allocation game based on our
 * buddy allocation memory strategy.
 */

#ifndef MEMWIDGET_H
#define MEMWIDGET_H

#include <QFont>
#include <QEvent>
#include <vector>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QPainter>
#include <QLineEdit>
#include <QBoxLayout>
#include <QTableView>
#include <QPushButton>
#include <QScrollArea>
#include "monitor/cpuMon.h"
#include "memoryGame/Buddy.h"
#include "memoryGame/table_constr.h"
#include "memoryGame/paintground.h"

class Mem_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Mem_widget(QWidget *parent = nullptr);
    ~Mem_widget();

    /*
     * Create the tableview to get user input
     */
    void initTable();

    /*
     * Initialize created labels
     */
    void initLabels();

    /*
     * Set up the created scroll view
     */
    void initScroll();

    /*
     * Set up widget layout
     */
    void initLayout();

    /*
     * Initialize buttons
     */
    void initButtons();

    /*
     * Randomly assign different color to each process
     */
    void initColor();

    /*
     * Try to fetch data from the table view input. Return true if
     * successful
     */
    bool tableFill();

    void setPID(int pid);
    void set_CPU(cpuMon *);
    void set_memory(Buddy * memory);

private:

    QLabel * title;
    QLabel * processN;
    QLabel * TMem;
    QLabel * AddrTop;
    QLabel * AddrBot;
    QLabel * TUsed;
    QLineEdit * processEdit;
    QLineEdit * MemEdit;

    stdTable * constructor;
    QStandardItemModel * tableModel;
    QTableView * visualTable;
    QScrollArea * visualMem;
    QWidget * scrollContent;
    paintGround * ground;
    QPainter * painter;

    QPushButton * start;
    QPushButton * clear;

    QVBoxLayout * mainLayout;
    QHBoxLayout * playground;
    QVBoxLayout * drawingArea;
    QVBoxLayout * inputArea;
    QHBoxLayout * processLayout;
    QHBoxLayout * memoryLayout;
    QHBoxLayout * buttonLayout;
    QGridLayout * inside;

    std::vector<const QVariant> * attributes;

    int Memory;
    int Process;
    bool dirty;
    Buddy * bd;
    vector<int> * colors;

    int PID;                      /* The pid for main window.                            */
    cpuMon* CPU;                     /* Assigned CPU for main window.                       */
    Buddy* memory;                   /* Assigned memory for main window.                    */
    bool created = false;            /* Turn true when memory are allocated to main window. */
    int memory_size=250;             /* The memory size for main window.                    */
    QTimer *system_timer;

    /* Private Functions: Updage usage of CPU for different oparetions.*/

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void refresh();

    void back_to_fluctuation();

    void set_up_memory();

    void sleeping();

    /*
     * Used to trigger data fetching and drawing, if data proper
     * prompted in
     */
    void onStartClicked();

    /*
     * Used to clear everything displaying and reset displays to
     * default
     */
    void onClearClicked();

    /*
     * Fetch data from the table and lineEdit
     */
    void setInput();

    //    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;


protected:
    void mousePressEvent(QMouseEvent *e) override;      /* Dectect the oparation of simple(invalid) click.*/

    void mouseMoveEvent(QMouseEvent *e) override;       /* Dectect the oparation of moving around.        */

    void closeEvent(QCloseEvent*event) override;

    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void closing();


};

#endif // MEMWIDGET_H
