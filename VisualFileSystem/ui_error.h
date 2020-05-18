/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Error
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lbl_Menu;

    void setupUi(QDialog *Error)
    {
        if (Error->objectName().isEmpty())
            Error->setObjectName(QStringLiteral("Error"));
        Error->resize(327, 166);
        buttonBox = new QDialogButtonBox(Error);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 120, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lbl_Menu = new QLabel(Error);
        lbl_Menu->setObjectName(QStringLiteral("lbl_Menu"));
        lbl_Menu->setGeometry(QRect(40, 50, 221, 41));

        retranslateUi(Error);
        QObject::connect(buttonBox, SIGNAL(accepted()), Error, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Error, SLOT(reject()));

        QMetaObject::connectSlotsByName(Error);
    } // setupUi

    void retranslateUi(QDialog *Error)
    {
        Error->setWindowTitle(QApplication::translate("Error", "Dialog", Q_NULLPTR));
        lbl_Menu->setText(QApplication::translate("Error", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; color:#fc0107;\">Error:</span><span style=\" font-size:20pt;\"> File does not exist!</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Error: public Ui_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
