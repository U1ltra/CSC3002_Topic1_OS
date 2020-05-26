/********************************************************************************
** Form generated from reading UI file 'saveaslist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEASLIST_H
#define UI_SAVEASLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saveAsList
{
public:
    QLineEdit *pathEdit;
    QLineEdit *saveAs;
    QLabel *save_as;
    QLabel *directory;
    QListWidget *fileList;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLabel *save_as_2;

    void setupUi(QDialog *saveAsList)
    {
        if (saveAsList->objectName().isEmpty())
            saveAsList->setObjectName(QString::fromUtf8("saveAsList"));
        saveAsList->resize(599, 378);
        pathEdit = new QLineEdit(saveAsList);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
        pathEdit->setGeometry(QRect(210, 60, 371, 41));
        saveAs = new QLineEdit(saveAsList);
        saveAs->setObjectName(QString::fromUtf8("saveAs"));
        saveAs->setGeometry(QRect(210, 10, 101, 41));
        save_as = new QLabel(saveAsList);
        save_as->setObjectName(QString::fromUtf8("save_as"));
        save_as->setGeometry(QRect(30, 10, 81, 41));
        directory = new QLabel(saveAsList);
        directory->setObjectName(QString::fromUtf8("directory"));
        directory->setGeometry(QRect(20, 60, 181, 41));
        fileList = new QListWidget(saveAsList);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        fileList->setGeometry(QRect(30, 110, 441, 251));
        saveButton = new QPushButton(saveAsList);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(490, 280, 81, 41));
        cancelButton = new QPushButton(saveAsList);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(490, 320, 81, 41));
        save_as_2 = new QLabel(saveAsList);
        save_as_2->setObjectName(QString::fromUtf8("save_as_2"));
        save_as_2->setGeometry(QRect(300, 10, 81, 41));

        retranslateUi(saveAsList);

        QMetaObject::connectSlotsByName(saveAsList);
    } // setupUi

    void retranslateUi(QDialog *saveAsList)
    {
        saveAsList->setWindowTitle(QApplication::translate("saveAsList", "Dialog", nullptr));
        save_as->setText(QApplication::translate("saveAsList", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">save as</span></p></body></html>", nullptr));
        directory->setText(QApplication::translate("saveAsList", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">directory</span></p></body></html>", nullptr));
        saveButton->setText(QApplication::translate("saveAsList", "save", nullptr));
        cancelButton->setText(QApplication::translate("saveAsList", "cancel", nullptr));
        save_as_2->setText(QApplication::translate("saveAsList", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">.txt</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saveAsList: public Ui_saveAsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEASLIST_H
