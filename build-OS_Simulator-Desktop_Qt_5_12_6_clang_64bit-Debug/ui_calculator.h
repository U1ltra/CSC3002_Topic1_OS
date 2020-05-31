/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QPushButton *calc_btn_0;
    QPushButton *calc_btn_1;
    QPushButton *calc_btn_2;
    QPushButton *calc_btn_3;
    QPushButton *calc_btn_4;
    QPushButton *calc_btn_5;
    QPushButton *calc_btn_6;
    QPushButton *calc_btn_7;
    QPushButton *calc_btn_8;
    QPushButton *calc_btn_9;
    QPushButton *calc_btn_plus;
    QPushButton *calc_btn_minus;
    QPushButton *calc_btn_multipy;
    QPushButton *calc_btn_division;
    QPushButton *calc_btn_equal;
    QPushButton *calc_btn_clean;
    QTextEdit *screen;

    void setupUi(QWidget *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(1269, 717);
        calc_btn_0 = new QPushButton(Calculator);
        calc_btn_0->setObjectName(QString::fromUtf8("calc_btn_0"));
        calc_btn_0->setGeometry(QRect(125, 308, 50, 50));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calc_btn_0->sizePolicy().hasHeightForWidth());
        calc_btn_0->setSizePolicy(sizePolicy);
        calc_btn_0->setMinimumSize(QSize(30, 30));
        calc_btn_0->setMaximumSize(QSize(50, 50));
        calc_btn_0->setSizeIncrement(QSize(1, 1));
        calc_btn_0->setBaseSize(QSize(30, 30));
        calc_btn_1 = new QPushButton(Calculator);
        calc_btn_1->setObjectName(QString::fromUtf8("calc_btn_1"));
        calc_btn_1->setGeometry(QRect(209, 308, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_1->sizePolicy().hasHeightForWidth());
        calc_btn_1->setSizePolicy(sizePolicy);
        calc_btn_1->setMinimumSize(QSize(30, 30));
        calc_btn_1->setMaximumSize(QSize(50, 50));
        calc_btn_1->setSizeIncrement(QSize(1, 1));
        calc_btn_1->setBaseSize(QSize(30, 30));
        calc_btn_2 = new QPushButton(Calculator);
        calc_btn_2->setObjectName(QString::fromUtf8("calc_btn_2"));
        calc_btn_2->setGeometry(QRect(293, 308, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_2->sizePolicy().hasHeightForWidth());
        calc_btn_2->setSizePolicy(sizePolicy);
        calc_btn_2->setMinimumSize(QSize(30, 30));
        calc_btn_2->setMaximumSize(QSize(50, 50));
        calc_btn_2->setSizeIncrement(QSize(1, 1));
        calc_btn_2->setBaseSize(QSize(30, 30));
        calc_btn_3 = new QPushButton(Calculator);
        calc_btn_3->setObjectName(QString::fromUtf8("calc_btn_3"));
        calc_btn_3->setGeometry(QRect(377, 308, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_3->sizePolicy().hasHeightForWidth());
        calc_btn_3->setSizePolicy(sizePolicy);
        calc_btn_3->setMinimumSize(QSize(30, 30));
        calc_btn_3->setMaximumSize(QSize(50, 50));
        calc_btn_3->setSizeIncrement(QSize(1, 1));
        calc_btn_3->setBaseSize(QSize(30, 30));
        calc_btn_4 = new QPushButton(Calculator);
        calc_btn_4->setObjectName(QString::fromUtf8("calc_btn_4"));
        calc_btn_4->setGeometry(QRect(461, 308, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_4->sizePolicy().hasHeightForWidth());
        calc_btn_4->setSizePolicy(sizePolicy);
        calc_btn_4->setMinimumSize(QSize(30, 30));
        calc_btn_4->setMaximumSize(QSize(50, 50));
        calc_btn_4->setSizeIncrement(QSize(1, 1));
        calc_btn_4->setBaseSize(QSize(30, 30));
        calc_btn_5 = new QPushButton(Calculator);
        calc_btn_5->setObjectName(QString::fromUtf8("calc_btn_5"));
        calc_btn_5->setGeometry(QRect(125, 373, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_5->sizePolicy().hasHeightForWidth());
        calc_btn_5->setSizePolicy(sizePolicy);
        calc_btn_5->setMinimumSize(QSize(30, 30));
        calc_btn_5->setMaximumSize(QSize(50, 50));
        calc_btn_5->setSizeIncrement(QSize(1, 1));
        calc_btn_5->setBaseSize(QSize(30, 30));
        calc_btn_6 = new QPushButton(Calculator);
        calc_btn_6->setObjectName(QString::fromUtf8("calc_btn_6"));
        calc_btn_6->setGeometry(QRect(209, 373, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_6->sizePolicy().hasHeightForWidth());
        calc_btn_6->setSizePolicy(sizePolicy);
        calc_btn_6->setMinimumSize(QSize(30, 30));
        calc_btn_6->setMaximumSize(QSize(50, 50));
        calc_btn_6->setSizeIncrement(QSize(1, 1));
        calc_btn_6->setBaseSize(QSize(30, 30));
        calc_btn_7 = new QPushButton(Calculator);
        calc_btn_7->setObjectName(QString::fromUtf8("calc_btn_7"));
        calc_btn_7->setGeometry(QRect(293, 373, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_7->sizePolicy().hasHeightForWidth());
        calc_btn_7->setSizePolicy(sizePolicy);
        calc_btn_7->setMinimumSize(QSize(30, 30));
        calc_btn_7->setMaximumSize(QSize(50, 50));
        calc_btn_7->setSizeIncrement(QSize(1, 1));
        calc_btn_7->setBaseSize(QSize(30, 30));
        calc_btn_8 = new QPushButton(Calculator);
        calc_btn_8->setObjectName(QString::fromUtf8("calc_btn_8"));
        calc_btn_8->setGeometry(QRect(377, 373, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_8->sizePolicy().hasHeightForWidth());
        calc_btn_8->setSizePolicy(sizePolicy);
        calc_btn_8->setMinimumSize(QSize(30, 30));
        calc_btn_8->setMaximumSize(QSize(50, 50));
        calc_btn_8->setSizeIncrement(QSize(1, 1));
        calc_btn_8->setBaseSize(QSize(30, 30));
        calc_btn_9 = new QPushButton(Calculator);
        calc_btn_9->setObjectName(QString::fromUtf8("calc_btn_9"));
        calc_btn_9->setGeometry(QRect(461, 373, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_9->sizePolicy().hasHeightForWidth());
        calc_btn_9->setSizePolicy(sizePolicy);
        calc_btn_9->setMinimumSize(QSize(30, 30));
        calc_btn_9->setMaximumSize(QSize(50, 50));
        calc_btn_9->setSizeIncrement(QSize(1, 1));
        calc_btn_9->setBaseSize(QSize(30, 30));
        calc_btn_plus = new QPushButton(Calculator);
        calc_btn_plus->setObjectName(QString::fromUtf8("calc_btn_plus"));
        calc_btn_plus->setGeometry(QRect(125, 438, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_plus->sizePolicy().hasHeightForWidth());
        calc_btn_plus->setSizePolicy(sizePolicy);
        calc_btn_plus->setMinimumSize(QSize(30, 30));
        calc_btn_plus->setMaximumSize(QSize(50, 50));
        calc_btn_plus->setSizeIncrement(QSize(1, 1));
        calc_btn_plus->setBaseSize(QSize(30, 30));
        calc_btn_minus = new QPushButton(Calculator);
        calc_btn_minus->setObjectName(QString::fromUtf8("calc_btn_minus"));
        calc_btn_minus->setGeometry(QRect(209, 438, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_minus->sizePolicy().hasHeightForWidth());
        calc_btn_minus->setSizePolicy(sizePolicy);
        calc_btn_minus->setMinimumSize(QSize(30, 30));
        calc_btn_minus->setMaximumSize(QSize(50, 50));
        calc_btn_minus->setSizeIncrement(QSize(1, 1));
        calc_btn_minus->setBaseSize(QSize(30, 30));
        calc_btn_multipy = new QPushButton(Calculator);
        calc_btn_multipy->setObjectName(QString::fromUtf8("calc_btn_multipy"));
        calc_btn_multipy->setGeometry(QRect(290, 440, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_multipy->sizePolicy().hasHeightForWidth());
        calc_btn_multipy->setSizePolicy(sizePolicy);
        calc_btn_multipy->setMinimumSize(QSize(30, 30));
        calc_btn_multipy->setMaximumSize(QSize(50, 50));
        calc_btn_multipy->setSizeIncrement(QSize(1, 1));
        calc_btn_multipy->setBaseSize(QSize(30, 30));
        calc_btn_division = new QPushButton(Calculator);
        calc_btn_division->setObjectName(QString::fromUtf8("calc_btn_division"));
        calc_btn_division->setGeometry(QRect(377, 438, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_division->sizePolicy().hasHeightForWidth());
        calc_btn_division->setSizePolicy(sizePolicy);
        calc_btn_division->setMinimumSize(QSize(30, 30));
        calc_btn_division->setMaximumSize(QSize(50, 50));
        calc_btn_division->setSizeIncrement(QSize(1, 1));
        calc_btn_division->setBaseSize(QSize(30, 30));
        calc_btn_equal = new QPushButton(Calculator);
        calc_btn_equal->setObjectName(QString::fromUtf8("calc_btn_equal"));
        calc_btn_equal->setGeometry(QRect(461, 438, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_equal->sizePolicy().hasHeightForWidth());
        calc_btn_equal->setSizePolicy(sizePolicy);
        calc_btn_equal->setMinimumSize(QSize(30, 30));
        calc_btn_equal->setMaximumSize(QSize(50, 50));
        calc_btn_equal->setSizeIncrement(QSize(1, 1));
        calc_btn_equal->setBaseSize(QSize(30, 30));
        calc_btn_clean = new QPushButton(Calculator);
        calc_btn_clean->setObjectName(QString::fromUtf8("calc_btn_clean"));
        calc_btn_clean->setGeometry(QRect(545, 438, 50, 50));
        sizePolicy.setHeightForWidth(calc_btn_clean->sizePolicy().hasHeightForWidth());
        calc_btn_clean->setSizePolicy(sizePolicy);
        calc_btn_clean->setMinimumSize(QSize(30, 30));
        calc_btn_clean->setMaximumSize(QSize(50, 50));
        calc_btn_clean->setSizeIncrement(QSize(1, 1));
        calc_btn_clean->setBaseSize(QSize(30, 30));
        screen = new QTextEdit(Calculator);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setGeometry(QRect(50, 90, 641, 81));

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QWidget *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Form", nullptr));
        calc_btn_0->setText(QApplication::translate("Calculator", "0", nullptr));
        calc_btn_1->setText(QApplication::translate("Calculator", "1", nullptr));
        calc_btn_2->setText(QApplication::translate("Calculator", "2", nullptr));
        calc_btn_3->setText(QApplication::translate("Calculator", "3", nullptr));
        calc_btn_4->setText(QApplication::translate("Calculator", "4", nullptr));
        calc_btn_5->setText(QApplication::translate("Calculator", "5", nullptr));
        calc_btn_6->setText(QApplication::translate("Calculator", "6", nullptr));
        calc_btn_7->setText(QApplication::translate("Calculator", "7", nullptr));
        calc_btn_8->setText(QApplication::translate("Calculator", "8", nullptr));
        calc_btn_9->setText(QApplication::translate("Calculator", "9", nullptr));
        calc_btn_plus->setText(QApplication::translate("Calculator", "+", nullptr));
        calc_btn_minus->setText(QApplication::translate("Calculator", "-", nullptr));
        calc_btn_multipy->setText(QApplication::translate("Calculator", "*", nullptr));
        calc_btn_division->setText(QApplication::translate("Calculator", "/", nullptr));
        calc_btn_equal->setText(QApplication::translate("Calculator", "=", nullptr));
        calc_btn_clean->setText(QApplication::translate("Calculator", "C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
