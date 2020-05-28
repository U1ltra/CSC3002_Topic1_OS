/********************************************************************************
** Form generated from reading UI file 'login_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_INTERFACE_H
#define UI_LOGIN_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *Password;
    QLineEdit *UserName;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *login_btn_Login;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *login_btn_Shutdown;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *Parent_Mode;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(801, 465);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 18, -1, -1);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 1, 1, 1);

        Password = new QLineEdit(widget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(Password, 4, 2, 1, 1);

        UserName = new QLineEdit(widget);
        UserName->setObjectName(QString::fromUtf8("UserName"));

        gridLayout->addWidget(UserName, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 2, 1);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        login_btn_Login = new QPushButton(widget_3);
        login_btn_Login->setObjectName(QString::fromUtf8("login_btn_Login"));

        gridLayout_3->addWidget(login_btn_Login, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 0, 2, 1, 1);

        login_btn_Shutdown = new QPushButton(widget_3);
        login_btn_Shutdown->setObjectName(QString::fromUtf8("login_btn_Shutdown"));

        gridLayout_3->addWidget(login_btn_Shutdown, 0, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_4, 1, 2, 1, 1);


        verticalLayout->addWidget(widget_3);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        widget_4 = new QWidget(Widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 20);
        horizontalSpacer_7 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        Parent_Mode = new QRadioButton(widget_4);
        Parent_Mode->setObjectName(QString::fromUtf8("Parent_Mode"));
        Parent_Mode->setTabletTracking(false);
        Parent_Mode->setChecked(true);

        gridLayout_2->addWidget(Parent_Mode, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 49, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 1, 1, 1, 1);


        verticalLayout->addWidget(widget_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "User", nullptr));
        label_2->setText(QApplication::translate("Widget", "Password", nullptr));
        Password->setText(QString());
        UserName->setText(QString());
        login_btn_Login->setText(QApplication::translate("Widget", "Login", nullptr));
        login_btn_Shutdown->setText(QApplication::translate("Widget", "Shutdown", nullptr));
        Parent_Mode->setText(QApplication::translate("Widget", "Parent Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_INTERFACE_H
