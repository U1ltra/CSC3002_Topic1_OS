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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShutdown;
    QAction *actionSleep;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Calendar;
    QPushButton *btn_calc;
    QPushButton *btn_FileSystem;
    QPushButton *btn_TaskManager;
    QPushButton *btn_TextEditor;
    QPushButton *btn_game;
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
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_Calendar = new QPushButton(centralwidget);
        btn_Calendar->setObjectName(QString::fromUtf8("btn_Calendar"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_Calendar->sizePolicy().hasHeightForWidth());
        btn_Calendar->setSizePolicy(sizePolicy);
        btn_Calendar->setMinimumSize(QSize(50, 50));
        btn_Calendar->setMaximumSize(QSize(100, 100));
        btn_Calendar->setSizeIncrement(QSize(1, 1));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/images/Calendar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Calendar->setIcon(icon);
        btn_Calendar->setIconSize(QSize(100, 100));

        horizontalLayout->addWidget(btn_Calendar);

        btn_calc = new QPushButton(centralwidget);
        btn_calc->setObjectName(QString::fromUtf8("btn_calc"));
        sizePolicy.setHeightForWidth(btn_calc->sizePolicy().hasHeightForWidth());
        btn_calc->setSizePolicy(sizePolicy);
        btn_calc->setMinimumSize(QSize(50, 50));
        btn_calc->setMaximumSize(QSize(100, 100));
        btn_calc->setSizeIncrement(QSize(1, 1));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/images/Calculator.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_calc->setIcon(icon1);
        btn_calc->setIconSize(QSize(100, 100));

        horizontalLayout->addWidget(btn_calc);

        btn_FileSystem = new QPushButton(centralwidget);
        btn_FileSystem->setObjectName(QString::fromUtf8("btn_FileSystem"));
        sizePolicy.setHeightForWidth(btn_FileSystem->sizePolicy().hasHeightForWidth());
        btn_FileSystem->setSizePolicy(sizePolicy);
        btn_FileSystem->setMinimumSize(QSize(50, 50));
        btn_FileSystem->setMaximumSize(QSize(100, 100));
        btn_FileSystem->setSizeIncrement(QSize(1, 1));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/images/FileSystem.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_FileSystem->setIcon(icon2);
        btn_FileSystem->setIconSize(QSize(100, 100));

        horizontalLayout->addWidget(btn_FileSystem);

        btn_TaskManager = new QPushButton(centralwidget);
        btn_TaskManager->setObjectName(QString::fromUtf8("btn_TaskManager"));
        sizePolicy.setHeightForWidth(btn_TaskManager->sizePolicy().hasHeightForWidth());
        btn_TaskManager->setSizePolicy(sizePolicy);
        btn_TaskManager->setMinimumSize(QSize(50, 50));
        btn_TaskManager->setMaximumSize(QSize(100, 100));
        btn_TaskManager->setSizeIncrement(QSize(1, 1));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/images/TaskManager.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_TaskManager->setIcon(icon3);
        btn_TaskManager->setIconSize(QSize(100, 100));

        horizontalLayout->addWidget(btn_TaskManager);

        btn_TextEditor = new QPushButton(centralwidget);
        btn_TextEditor->setObjectName(QString::fromUtf8("btn_TextEditor"));
        sizePolicy.setHeightForWidth(btn_TextEditor->sizePolicy().hasHeightForWidth());
        btn_TextEditor->setSizePolicy(sizePolicy);
        btn_TextEditor->setMinimumSize(QSize(50, 50));
        btn_TextEditor->setMaximumSize(QSize(100, 100));
        btn_TextEditor->setSizeIncrement(QSize(1, 1));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/images/TextEditor.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_TextEditor->setIcon(icon4);
        btn_TextEditor->setIconSize(QSize(100, 100));

        horizontalLayout->addWidget(btn_TextEditor);

        btn_game = new QPushButton(centralwidget);
        btn_game->setObjectName(QString::fromUtf8("btn_game"));
        sizePolicy.setHeightForWidth(btn_game->sizePolicy().hasHeightForWidth());
        btn_game->setSizePolicy(sizePolicy);
        btn_game->setMinimumSize(QSize(50, 50));
        btn_game->setMaximumSize(QSize(100, 100));
        btn_game->setSizeIncrement(QSize(1, 1));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/images/Game.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_game->setIcon(icon5);
        btn_game->setIconSize(QSize(100, 100));

        horizontalLayout->addWidget(btn_game);

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
        menuSystem->addAction(actionSleep);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionShutdown->setText(QApplication::translate("MainWindow", "Shutdown", nullptr));
        actionSleep->setText(QApplication::translate("MainWindow", "Sleep", nullptr));
        btn_Calendar->setText(QString());
        btn_calc->setText(QString());
        btn_FileSystem->setText(QString());
        btn_TaskManager->setText(QString());
        btn_TextEditor->setText(QString());
        btn_game->setText(QString());
        menuSystem->setTitle(QApplication::translate("MainWindow", "System", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
