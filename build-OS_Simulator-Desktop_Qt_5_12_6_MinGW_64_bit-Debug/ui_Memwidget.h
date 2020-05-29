/********************************************************************************
** Form generated from reading UI file 'Memwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMWIDGET_H
#define UI_MEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mem_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QLabel *uplimit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *currentused;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *memorystorage;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *simulate;
    QPushButton *clear;

    void setupUi(QWidget *Mem_Widget)
    {
        if (Mem_Widget->objectName().isEmpty())
            Mem_Widget->setObjectName(QString::fromUtf8("Mem_Widget"));
        Mem_Widget->resize(607, 431);
        gridLayout = new QGridLayout(Mem_Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Mem_Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Mem_Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(Mem_Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        scrollArea = new QScrollArea(Mem_Widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 283, 294));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        uplimit = new QLabel(Mem_Widget);
        uplimit->setObjectName(QString::fromUtf8("uplimit"));

        horizontalLayout_3->addWidget(uplimit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(Mem_Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        currentused = new QLineEdit(Mem_Widget);
        currentused->setObjectName(QString::fromUtf8("currentused"));

        horizontalLayout_4->addWidget(currentused);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_4, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget = new QTableWidget(Mem_Widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(Mem_Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_4);

        memorystorage = new QLineEdit(Mem_Widget);
        memorystorage->setObjectName(QString::fromUtf8("memorystorage"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(memorystorage->sizePolicy().hasHeightForWidth());
        memorystorage->setSizePolicy(sizePolicy1);
        memorystorage->setMaximumSize(QSize(70, 70));

        horizontalLayout_2->addWidget(memorystorage);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Mem_Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(16777215, 100));

        horizontalLayout->addWidget(label_3);

        spinBox = new QSpinBox(Mem_Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(spinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        simulate = new QPushButton(Mem_Widget);
        simulate->setObjectName(QString::fromUtf8("simulate"));

        verticalLayout->addWidget(simulate);

        clear = new QPushButton(Mem_Widget);
        clear->setObjectName(QString::fromUtf8("clear"));

        verticalLayout->addWidget(clear);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);


        retranslateUi(Mem_Widget);

        QMetaObject::connectSlotsByName(Mem_Widget);
    } // setupUi

    void retranslateUi(QWidget *Mem_Widget)
    {
        Mem_Widget->setWindowTitle(QApplication::translate("Mem_Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Mem_Widget", "Display: YELLOW:USED; PURPLE:UNUSED", nullptr));
        label_2->setText(QApplication::translate("Mem_Widget", "Settings", nullptr));
        label_6->setText(QApplication::translate("Mem_Widget", "Address:0x00", nullptr));
        uplimit->setText(QApplication::translate("Mem_Widget", "Address: ", nullptr));
        label_8->setText(QApplication::translate("Mem_Widget", "CURRENT USED: ", nullptr));
        label_4->setText(QApplication::translate("Mem_Widget", "Memory storage:", nullptr));
        label_3->setText(QApplication::translate("Mem_Widget", "Task number:", nullptr));
        simulate->setText(QApplication::translate("Mem_Widget", "Simulate", nullptr));
        clear->setText(QApplication::translate("Mem_Widget", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mem_Widget: public Ui_Mem_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMWIDGET_H
