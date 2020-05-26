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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QPushButton *btn_TaskManager;
    QPushButton *btn_TextEditor;
    QPushButton *btn_Calendar;
    QPushButton *btn_game;
    QPushButton *btn_calc;
    QToolButton *btn_FileSystem;
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_TaskManager = new QPushButton(centralwidget);
        btn_TaskManager->setObjectName(QString::fromUtf8("btn_TaskManager"));
        btn_TaskManager->setMinimumSize(QSize(50, 50));
        btn_TaskManager->setMaximumSize(QSize(200, 200));
        btn_TaskManager->setSizeIncrement(QSize(1, 1));
        btn_TaskManager->setFlat(true);

        gridLayout->addWidget(btn_TaskManager, 0, 6, 1, 1);

        btn_TextEditor = new QPushButton(centralwidget);
        btn_TextEditor->setObjectName(QString::fromUtf8("btn_TextEditor"));
        btn_TextEditor->setMinimumSize(QSize(50, 50));
        btn_TextEditor->setMaximumSize(QSize(200, 200));
        btn_TextEditor->setSizeIncrement(QSize(1, 1));
        btn_TextEditor->setFlat(true);

        gridLayout->addWidget(btn_TextEditor, 0, 7, 1, 1);

        btn_Calendar = new QPushButton(centralwidget);
        btn_Calendar->setObjectName(QString::fromUtf8("btn_Calendar"));
        btn_Calendar->setMinimumSize(QSize(50, 50));
        btn_Calendar->setMaximumSize(QSize(200, 200));
        btn_Calendar->setSizeIncrement(QSize(1, 1));
        btn_Calendar->setFlat(true);

        gridLayout->addWidget(btn_Calendar, 0, 1, 1, 1);

        btn_game = new QPushButton(centralwidget);
        btn_game->setObjectName(QString::fromUtf8("btn_game"));
        btn_game->setMinimumSize(QSize(50, 50));
        btn_game->setMaximumSize(QSize(200, 200));
        btn_game->setSizeIncrement(QSize(1, 1));
        btn_game->setFlat(true);

        gridLayout->addWidget(btn_game, 0, 9, 1, 1);

        btn_calc = new QPushButton(centralwidget);
        btn_calc->setObjectName(QString::fromUtf8("btn_calc"));
        btn_calc->setMinimumSize(QSize(50, 50));
        btn_calc->setMaximumSize(QSize(200, 200));
        btn_calc->setSizeIncrement(QSize(1, 1));
        btn_calc->setFlat(true);

        gridLayout->addWidget(btn_calc, 0, 4, 1, 1);

        btn_FileSystem = new QToolButton(centralwidget);
        btn_FileSystem->setObjectName(QString::fromUtf8("btn_FileSystem"));
        btn_FileSystem->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btn_FileSystem, 0, 5, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 888, 21));
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
        btn_TaskManager->setText(QApplication::translate("MainWindow", "TaskManager", nullptr));
        btn_TextEditor->setText(QApplication::translate("MainWindow", "TextEditor", nullptr));
        btn_Calendar->setText(QApplication::translate("MainWindow", "Calendar", nullptr));
        btn_game->setText(QApplication::translate("MainWindow", "Game", nullptr));
        btn_calc->setText(QApplication::translate("MainWindow", "Calculator", nullptr));
        btn_FileSystem->setText(QApplication::translate("MainWindow", "FileSystem", nullptr));
        menuSystem->setTitle(QApplication::translate("MainWindow", "System", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
