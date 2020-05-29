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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_calc;
    QToolButton *btn_Calendar;
    QToolButton *btn_FileSystem;
    QToolButton *btn_TextEditor;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btn_Memory_Stimulator;
    QToolButton *btn_TaskManager;
    QToolButton *btn_Schedule_Stimulator;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuSystem;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(888, 556);
        MainWindow->setSizeIncrement(QSize(1, 0));
        actionShutdown = new QAction(MainWindow);
        actionShutdown->setObjectName(QString::fromUtf8("actionShutdown"));
        actionSleep = new QAction(MainWindow);
        actionSleep->setObjectName(QString::fromUtf8("actionSleep"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 170, 861, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_calc = new QToolButton(layoutWidget);
        btn_calc->setObjectName(QString::fromUtf8("btn_calc"));

        horizontalLayout->addWidget(btn_calc);

        btn_Calendar = new QToolButton(layoutWidget);
        btn_Calendar->setObjectName(QString::fromUtf8("btn_Calendar"));

        horizontalLayout->addWidget(btn_Calendar);

        btn_FileSystem = new QToolButton(layoutWidget);
        btn_FileSystem->setObjectName(QString::fromUtf8("btn_FileSystem"));
        btn_FileSystem->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(btn_FileSystem);

        btn_TextEditor = new QToolButton(layoutWidget);
        btn_TextEditor->setObjectName(QString::fromUtf8("btn_TextEditor"));

        horizontalLayout->addWidget(btn_TextEditor);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 310, 861, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_Memory_Stimulator = new QToolButton(layoutWidget1);
        btn_Memory_Stimulator->setObjectName(QString::fromUtf8("btn_Memory_Stimulator"));

        horizontalLayout_2->addWidget(btn_Memory_Stimulator);

        btn_TaskManager = new QToolButton(layoutWidget1);
        btn_TaskManager->setObjectName(QString::fromUtf8("btn_TaskManager"));

        horizontalLayout_2->addWidget(btn_TaskManager);

        btn_Schedule_Stimulator = new QToolButton(layoutWidget1);
        btn_Schedule_Stimulator->setObjectName(QString::fromUtf8("btn_Schedule_Stimulator"));

        horizontalLayout_2->addWidget(btn_Schedule_Stimulator);

        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 888, 29));
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
        btn_Memory_Stimulator->setText(QApplication::translate("MainWindow", "Memory Stimulator", nullptr));
        btn_TaskManager->setText(QApplication::translate("MainWindow", "Task Manager", nullptr));
        btn_Schedule_Stimulator->setText(QApplication::translate("MainWindow", "Schedule Stimulator", nullptr));
        menuSystem->setTitle(QApplication::translate("MainWindow", "System", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
