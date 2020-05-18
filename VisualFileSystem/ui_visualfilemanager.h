/********************************************************************************
** Form generated from reading UI file 'visualfilemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALFILEMANAGER_H
#define UI_VISUALFILEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualFileManager
{
public:
    QWidget *centralwidget;
    QPushButton *btn_Cd;
    QPushButton *btn_Up;
    QPushButton *btn_Paste;
    QPushButton *btn_Copy;
    QPushButton *btn_Exit;
    QLabel *lbl_Menu;
    QListWidget *lwt_File;
    QPushButton *btn_Create;
    QPushButton *btn_Root;
    QLineEdit *let_Menu;
    QPushButton *btn_Delete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VisualFileManager)
    {
        if (VisualFileManager->objectName().isEmpty())
            VisualFileManager->setObjectName(QStringLiteral("VisualFileManager"));
        VisualFileManager->resize(800, 600);
        centralwidget = new QWidget(VisualFileManager);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btn_Cd = new QPushButton(centralwidget);
        btn_Cd->setObjectName(QStringLiteral("btn_Cd"));
        btn_Cd->setGeometry(QRect(160, 330, 81, 61));
        btn_Up = new QPushButton(centralwidget);
        btn_Up->setObjectName(QStringLiteral("btn_Up"));
        btn_Up->setGeometry(QRect(60, 330, 81, 61));
        btn_Paste = new QPushButton(centralwidget);
        btn_Paste->setObjectName(QStringLiteral("btn_Paste"));
        btn_Paste->setGeometry(QRect(160, 170, 81, 61));
        btn_Copy = new QPushButton(centralwidget);
        btn_Copy->setObjectName(QStringLiteral("btn_Copy"));
        btn_Copy->setGeometry(QRect(60, 170, 81, 61));
        btn_Exit = new QPushButton(centralwidget);
        btn_Exit->setObjectName(QStringLiteral("btn_Exit"));
        btn_Exit->setGeometry(QRect(680, 460, 81, 61));
        lbl_Menu = new QLabel(centralwidget);
        lbl_Menu->setObjectName(QStringLiteral("lbl_Menu"));
        lbl_Menu->setGeometry(QRect(350, 40, 81, 41));
        lwt_File = new QListWidget(centralwidget);
        lwt_File->setObjectName(QStringLiteral("lwt_File"));
        lwt_File->setGeometry(QRect(350, 90, 421, 351));
        btn_Create = new QPushButton(centralwidget);
        btn_Create->setObjectName(QStringLiteral("btn_Create"));
        btn_Create->setGeometry(QRect(60, 250, 81, 61));
        btn_Root = new QPushButton(centralwidget);
        btn_Root->setObjectName(QStringLiteral("btn_Root"));
        btn_Root->setGeometry(QRect(60, 100, 81, 61));
        let_Menu = new QLineEdit(centralwidget);
        let_Menu->setObjectName(QStringLiteral("let_Menu"));
        let_Menu->setGeometry(QRect(430, 40, 301, 31));
        btn_Delete = new QPushButton(centralwidget);
        btn_Delete->setObjectName(QStringLiteral("btn_Delete"));
        btn_Delete->setGeometry(QRect(160, 250, 81, 61));
        VisualFileManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VisualFileManager);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        VisualFileManager->setMenuBar(menubar);
        statusbar = new QStatusBar(VisualFileManager);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        VisualFileManager->setStatusBar(statusbar);

        retranslateUi(VisualFileManager);

        QMetaObject::connectSlotsByName(VisualFileManager);
    } // setupUi

    void retranslateUi(QMainWindow *VisualFileManager)
    {
        VisualFileManager->setWindowTitle(QApplication::translate("VisualFileManager", "VisualFileManager", Q_NULLPTR));
        btn_Cd->setText(QApplication::translate("VisualFileManager", "Cd", Q_NULLPTR));
        btn_Up->setText(QApplication::translate("VisualFileManager", "Up", Q_NULLPTR));
        btn_Paste->setText(QApplication::translate("VisualFileManager", "Paste", Q_NULLPTR));
        btn_Copy->setText(QApplication::translate("VisualFileManager", "Copy", Q_NULLPTR));
        btn_Exit->setText(QApplication::translate("VisualFileManager", "Exit", Q_NULLPTR));
        lbl_Menu->setText(QApplication::translate("VisualFileManager", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Menu</span></p></body></html>", Q_NULLPTR));
        btn_Create->setText(QApplication::translate("VisualFileManager", "Create", Q_NULLPTR));
        btn_Root->setText(QApplication::translate("VisualFileManager", "Root", Q_NULLPTR));
        btn_Delete->setText(QApplication::translate("VisualFileManager", "Delete", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VisualFileManager: public Ui_VisualFileManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALFILEMANAGER_H
