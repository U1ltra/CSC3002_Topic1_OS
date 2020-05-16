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
#include <QtWidgets/QHBoxLayout>
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
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *UserName;
    QLabel *label;
    QLineEdit *Password;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *login_btn_Login;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *login_btn_Shutdown;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *Parent_Mode;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(801, 309);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        UserName = new QLineEdit(widget);
        UserName->setObjectName(QString::fromUtf8("UserName"));

        gridLayout->addWidget(UserName, 0, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        Password = new QLineEdit(widget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(Password, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        login_btn_Login = new QPushButton(widget_3);
        login_btn_Login->setObjectName(QString::fromUtf8("login_btn_Login"));

        horizontalLayout_3->addWidget(login_btn_Login);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        login_btn_Shutdown = new QPushButton(widget_3);
        login_btn_Shutdown->setObjectName(QString::fromUtf8("login_btn_Shutdown"));

        horizontalLayout_3->addWidget(login_btn_Shutdown);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(Widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        Parent_Mode = new QRadioButton(widget_4);
        Parent_Mode->setObjectName(QString::fromUtf8("Parent_Mode"));
        Parent_Mode->setTabletTracking(false);
        Parent_Mode->setChecked(true);

        horizontalLayout_4->addWidget(Parent_Mode);

        horizontalSpacer_8 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addWidget(widget_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label_2->setText(QApplication::translate("Widget", "Password", nullptr));
        UserName->setText(QString());
        label->setText(QApplication::translate("Widget", "User", nullptr));
        Password->setText(QString());
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
