/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShutdown;
    QAction *actionSleep;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *clock_layout;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_calc;
    QToolButton *btn_Calendar;
    QToolButton *btn_FileSystem;
    QToolButton *btn_TextEditor;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btn_Memory_Simulator;
    QToolButton *btn_TaskManager;
    QToolButton *btn_Schedule_Simulator;
    QMenuBar *menubar;
    QMenu *menuSystem;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(888, 556);
        MainWindow->setSizeIncrement(QSize(1, 1));
        actionShutdown = new QAction(MainWindow);
        actionShutdown->setObjectName(QString::fromUtf8("actionShutdown"));
        actionSleep = new QAction(MainWindow);
        actionSleep->setObjectName(QString::fromUtf8("actionSleep"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        clock_layout = new QHBoxLayout();
        clock_layout->setObjectName(QString::fromUtf8("clock_layout"));
        clock_layout->setSizeConstraint(QLayout::SetFixedSize);

        gridLayout->addLayout(clock_layout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_calc = new QToolButton(centralwidget);
        btn_calc->setObjectName(QString::fromUtf8("btn_calc"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_calc->sizePolicy().hasHeightForWidth());
        btn_calc->setSizePolicy(sizePolicy);
        btn_calc->setMinimumSize(QSize(100, 100));
        btn_calc->setMaximumSize(QSize(200, 200));
        btn_calc->setSizeIncrement(QSize(1, 1));

        horizontalLayout->addWidget(btn_calc);

        btn_Calendar = new QToolButton(centralwidget);
        btn_Calendar->setObjectName(QString::fromUtf8("btn_Calendar"));
        sizePolicy.setHeightForWidth(btn_Calendar->sizePolicy().hasHeightForWidth());
        btn_Calendar->setSizePolicy(sizePolicy);
        btn_Calendar->setMinimumSize(QSize(100, 100));
        btn_Calendar->setMaximumSize(QSize(200, 200));

        horizontalLayout->addWidget(btn_Calendar);

        btn_FileSystem = new QToolButton(centralwidget);
        btn_FileSystem->setObjectName(QString::fromUtf8("btn_FileSystem"));
        sizePolicy.setHeightForWidth(btn_FileSystem->sizePolicy().hasHeightForWidth());
        btn_FileSystem->setSizePolicy(sizePolicy);
        btn_FileSystem->setMinimumSize(QSize(100, 100));
        btn_FileSystem->setMaximumSize(QSize(200, 200));
        btn_FileSystem->setSizeIncrement(QSize(1, 1));
        btn_FileSystem->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(btn_FileSystem);

        btn_TextEditor = new QToolButton(centralwidget);
        btn_TextEditor->setObjectName(QString::fromUtf8("btn_TextEditor"));
        sizePolicy.setHeightForWidth(btn_TextEditor->sizePolicy().hasHeightForWidth());
        btn_TextEditor->setSizePolicy(sizePolicy);
        btn_TextEditor->setMinimumSize(QSize(100, 100));
        btn_TextEditor->setMaximumSize(QSize(200, 200));
        btn_TextEditor->setSizeIncrement(QSize(1, 1));

        horizontalLayout->addWidget(btn_TextEditor);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_Memory_Simulator = new QToolButton(centralwidget);
        btn_Memory_Simulator->setObjectName(QString::fromUtf8("btn_Memory_Simulator"));
        sizePolicy.setHeightForWidth(btn_Memory_Simulator->sizePolicy().hasHeightForWidth());
        btn_Memory_Simulator->setSizePolicy(sizePolicy);
        btn_Memory_Simulator->setMinimumSize(QSize(100, 100));
        btn_Memory_Simulator->setMaximumSize(QSize(200, 200));
        btn_Memory_Simulator->setSizeIncrement(QSize(1, 1));

        horizontalLayout_2->addWidget(btn_Memory_Simulator);

        btn_TaskManager = new QToolButton(centralwidget);
        btn_TaskManager->setObjectName(QString::fromUtf8("btn_TaskManager"));
        sizePolicy.setHeightForWidth(btn_TaskManager->sizePolicy().hasHeightForWidth());
        btn_TaskManager->setSizePolicy(sizePolicy);
        btn_TaskManager->setMinimumSize(QSize(100, 100));
        btn_TaskManager->setMaximumSize(QSize(200, 200));
        btn_TaskManager->setSizeIncrement(QSize(1, 1));

        horizontalLayout_2->addWidget(btn_TaskManager);

        btn_Schedule_Simulator = new QToolButton(centralwidget);
        btn_Schedule_Simulator->setObjectName(QString::fromUtf8("btn_Schedule_Simulator"));
        sizePolicy.setHeightForWidth(btn_Schedule_Simulator->sizePolicy().hasHeightForWidth());
        btn_Schedule_Simulator->setSizePolicy(sizePolicy);
        btn_Schedule_Simulator->setMinimumSize(QSize(100, 100));
        btn_Schedule_Simulator->setMaximumSize(QSize(200, 200));
        btn_Schedule_Simulator->setSizeIncrement(QSize(1, 1));

        horizontalLayout_2->addWidget(btn_Schedule_Simulator);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 888, 22));
        menuSystem = new QMenu(menubar);
        menuSystem->setObjectName(QString::fromUtf8("menuSystem"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuSystem->menuAction());
        menubar->addAction(menuFile->menuAction());
        menuSystem->addAction(actionShutdown);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionShutdown->setText(QApplication::translate("MainWindow", "Shutdown", nullptr));
        actionSleep->setText(QApplication::translate("MainWindow", "Sleep", nullptr));
        btn_calc->setText(QApplication::translate("MainWindow", "Calculator", nullptr));
        btn_Calendar->setText(QApplication::translate("MainWindow", "Calendar", nullptr));
        btn_FileSystem->setText(QApplication::translate("MainWindow", "FileSystem", nullptr));
        btn_TextEditor->setText(QApplication::translate("MainWindow", "Text Editor", nullptr));
        btn_Memory_Simulator->setText(QApplication::translate("MainWindow", "Memory Stimulator", nullptr));
        btn_TaskManager->setText(QApplication::translate("MainWindow", "Task Manager", nullptr));
        btn_Schedule_Simulator->setText(QApplication::translate("MainWindow", "Schedule Stimulator", nullptr));
        menuSystem->setTitle(QApplication::translate("MainWindow", "System", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
