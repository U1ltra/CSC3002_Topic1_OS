/********************************************************************************
** Form generated from reading UI file 'texteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextEditor
{
public:
    QAction *action_NewFile;
    QAction *action_OpenFile;
    QAction *action_Save;
    QAction *action_SaveAs;
    QAction *action_Exit;
    QAction *action_Undo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Paste;
    QAction *action_Find;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TextEditor)
    {
        if (TextEditor->objectName().isEmpty())
            TextEditor->setObjectName(QString::fromUtf8("TextEditor"));
        TextEditor->resize(800, 600);
        action_NewFile = new QAction(TextEditor);
        action_NewFile->setObjectName(QString::fromUtf8("action_NewFile"));
        action_OpenFile = new QAction(TextEditor);
        action_OpenFile->setObjectName(QString::fromUtf8("action_OpenFile"));
        action_Save = new QAction(TextEditor);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_SaveAs = new QAction(TextEditor);
        action_SaveAs->setObjectName(QString::fromUtf8("action_SaveAs"));
        action_Exit = new QAction(TextEditor);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Undo = new QAction(TextEditor);
        action_Undo->setObjectName(QString::fromUtf8("action_Undo"));
        action_Cut = new QAction(TextEditor);
        action_Cut->setObjectName(QString::fromUtf8("action_Cut"));
        action_Copy = new QAction(TextEditor);
        action_Copy->setObjectName(QString::fromUtf8("action_Copy"));
        action_Paste = new QAction(TextEditor);
        action_Paste->setObjectName(QString::fromUtf8("action_Paste"));
        action_Find = new QAction(TextEditor);
        action_Find->setObjectName(QString::fromUtf8("action_Find"));
        centralwidget = new QWidget(TextEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 70, 711, 431));
        TextEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TextEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        TextEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(TextEditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TextEditor->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menu->addAction(action_NewFile);
        menu->addAction(action_OpenFile);
        menu->addAction(action_Save);
        menu->addAction(action_SaveAs);
        menu->addAction(action_Exit);
        menuEdit->addAction(action_Undo);
        menuEdit->addAction(action_Cut);
        menuEdit->addAction(action_Copy);
        menuEdit->addAction(action_Paste);
        menuEdit->addAction(action_Find);

        retranslateUi(TextEditor);

        QMetaObject::connectSlotsByName(TextEditor);
    } // setupUi

    void retranslateUi(QMainWindow *TextEditor)
    {
        TextEditor->setWindowTitle(QApplication::translate("TextEditor", "MainWindow", nullptr));
        action_NewFile->setText(QApplication::translate("TextEditor", "New File(N)", nullptr));
        action_OpenFile->setText(QApplication::translate("TextEditor", "Open File(O)", nullptr));
        action_Save->setText(QApplication::translate("TextEditor", "Save(S)", nullptr));
        action_SaveAs->setText(QApplication::translate("TextEditor", "Save As(A)", nullptr));
        action_Exit->setText(QApplication::translate("TextEditor", "Exit(X)", nullptr));
        action_Undo->setText(QApplication::translate("TextEditor", "Undo(U)", nullptr));
        action_Cut->setText(QApplication::translate("TextEditor", "Cut(T)", nullptr));
        action_Copy->setText(QApplication::translate("TextEditor", "Copy(C)", nullptr));
        action_Paste->setText(QApplication::translate("TextEditor", "Paste(P)", nullptr));
        action_Find->setText(QApplication::translate("TextEditor", "Find(F)", nullptr));
        menu->setTitle(QApplication::translate("TextEditor", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("TextEditor", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextEditor: public Ui_TextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H
