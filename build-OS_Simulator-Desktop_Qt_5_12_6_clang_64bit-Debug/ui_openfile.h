/********************************************************************************
** Form generated from reading UI file 'openfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENFILE_H
#define UI_OPENFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_openFile
{
public:
    QListWidget *fileList;
    QLineEdit *pathEdit;
    QLabel *directory;
    QPushButton *openButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *openFile)
    {
        if (openFile->objectName().isEmpty())
            openFile->setObjectName(QString::fromUtf8("openFile"));
        openFile->resize(571, 342);
        fileList = new QListWidget(openFile);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        fileList->setGeometry(QRect(20, 70, 441, 251));
        pathEdit = new QLineEdit(openFile);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
        pathEdit->setGeometry(QRect(190, 20, 361, 41));
        directory = new QLabel(openFile);
        directory->setObjectName(QString::fromUtf8("directory"));
        directory->setGeometry(QRect(20, 20, 161, 41));
        openButton = new QPushButton(openFile);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(470, 240, 81, 41));
        cancelButton = new QPushButton(openFile);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(470, 280, 81, 41));

        retranslateUi(openFile);

        QMetaObject::connectSlotsByName(openFile);
    } // setupUi

    void retranslateUi(QDialog *openFile)
    {
        openFile->setWindowTitle(QApplication::translate("openFile", "Dialog", nullptr));
        directory->setText(QApplication::translate("openFile", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">directory</span></p></body></html>", nullptr));
        openButton->setText(QApplication::translate("openFile", "open", nullptr));
        cancelButton->setText(QApplication::translate("openFile", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class openFile: public Ui_openFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFILE_H
