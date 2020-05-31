/********************************************************************************
** Form generated from reading UI file 'Schwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHWIDGET_H
#define UI_SCHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SchWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *timecounter;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *mygraph;
    QFrame *frame_right;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pause;
    QPushButton *play;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *simulate;
    QPushButton *clear;
    QPushButton *initialize;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *timeslice;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QTableWidget *table_of_process;

    void setupUi(QWidget *SchWidget)
    {
        if (SchWidget->objectName().isEmpty())
            SchWidget->setObjectName(QString::fromUtf8("SchWidget"));
        SchWidget->resize(657, 442);
        gridLayout = new QGridLayout(SchWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_2 = new QFrame(SchWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        timecounter = new QLabel(frame_2);
        timecounter->setObjectName(QString::fromUtf8("timecounter"));
        timecounter->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(timecounter);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        mygraph = new QWidget();
        mygraph->setObjectName(QString::fromUtf8("mygraph"));
        mygraph->setGeometry(QRect(0, 0, 391, 181));
        scrollArea->setWidget(mygraph);

        gridLayout_3->addWidget(scrollArea, 2, 0, 1, 1);


        gridLayout->addWidget(frame_2, 1, 0, 1, 1);

        frame_right = new QFrame(SchWidget);
        frame_right->setObjectName(QString::fromUtf8("frame_right"));
        frame_right->setFrameShape(QFrame::StyledPanel);
        frame_right->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_right);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pause = new QPushButton(frame_right);
        pause->setObjectName(QString::fromUtf8("pause"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pause->sizePolicy().hasHeightForWidth());
        pause->setSizePolicy(sizePolicy);
        pause->setMaximumSize(QSize(70, 16777215));
        pause->setAutoFillBackground(false);

        horizontalLayout_5->addWidget(pause);

        play = new QPushButton(frame_right);
        play->setObjectName(QString::fromUtf8("play"));
        sizePolicy.setHeightForWidth(play->sizePolicy().hasHeightForWidth());
        play->setSizePolicy(sizePolicy);
        play->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_5->addWidget(play);


        gridLayout_4->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame_right);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 20));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(frame_right);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(comboBox);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame_right);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(frame_right);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_2->addWidget(spinBox);


        gridLayout_4->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        simulate = new QPushButton(frame_right);
        simulate->setObjectName(QString::fromUtf8("simulate"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(simulate->sizePolicy().hasHeightForWidth());
        simulate->setSizePolicy(sizePolicy1);
        simulate->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(simulate, 3, 0, 1, 1);

        clear = new QPushButton(frame_right);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(clear, 4, 0, 1, 1);

        initialize = new QPushButton(frame_right);
        initialize->setObjectName(QString::fromUtf8("initialize"));
        initialize->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(initialize, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(frame_right);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_4);

        timeslice = new QLineEdit(frame_right);
        timeslice->setObjectName(QString::fromUtf8("timeslice"));
        sizePolicy.setHeightForWidth(timeslice->sizePolicy().hasHeightForWidth());
        timeslice->setSizePolicy(sizePolicy);
        timeslice->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(timeslice);


        gridLayout_4->addLayout(horizontalLayout_3, 6, 0, 1, 1);


        gridLayout->addWidget(frame_right, 1, 1, 1, 1);

        frame_3 = new QFrame(SchWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        table_of_process = new QTableWidget(frame_3);
        table_of_process->setObjectName(QString::fromUtf8("table_of_process"));
        table_of_process->setAutoFillBackground(true);

        gridLayout_2->addWidget(table_of_process, 0, 0, 2, 1);


        gridLayout->addWidget(frame_3, 0, 0, 1, 2);


        retranslateUi(SchWidget);

        QMetaObject::connectSlotsByName(SchWidget);
    } // setupUi

    void retranslateUi(QWidget *SchWidget)
    {
        SchWidget->setWindowTitle(QApplication::translate("SchWidget", "Widget", nullptr));
#ifndef QT_NO_WHATSTHIS
        SchWidget->setWhatsThis(QApplication::translate("SchWidget", "<html><head/><body><p><span style=\" font-size:288pt;\">S</span></p><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("SchWidget", "Graphic of scheduling (white represents empty)", nullptr));
        label_6->setText(QApplication::translate("SchWidget", "Time counter:", nullptr));
        timecounter->setText(QApplication::translate("SchWidget", "0", nullptr));
        pause->setText(QApplication::translate("SchWidget", "pause", nullptr));
        play->setText(QApplication::translate("SchWidget", "play", nullptr));
        label->setText(QApplication::translate("SchWidget", "Algorithms", nullptr));
        comboBox->setItemText(0, QApplication::translate("SchWidget", "First-Come First-Served", nullptr));
        comboBox->setItemText(1, QApplication::translate("SchWidget", "Shortest Remaining Time", nullptr));
        comboBox->setItemText(2, QApplication::translate("SchWidget", "Shortest Job First", nullptr));
        comboBox->setItemText(3, QApplication::translate("SchWidget", "Highest-Response Ratio Next", nullptr));
        comboBox->setItemText(4, QApplication::translate("SchWidget", "Round_Robin", nullptr));

        label_2->setText(QApplication::translate("SchWidget", "Process", nullptr));
        simulate->setText(QApplication::translate("SchWidget", "Simulate", nullptr));
        clear->setText(QApplication::translate("SchWidget", "Clear", nullptr));
        initialize->setText(QApplication::translate("SchWidget", "Initialize", nullptr));
        label_4->setText(QApplication::translate("SchWidget", "Timeslice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SchWidget: public Ui_SchWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHWIDGET_H
