/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(548, 441);
        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(154, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(300, 80));
        pushButton->setMaximumSize(QSize(300, 80));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 75 20pt \"Malgun Gothic\";\n"
"color: rgb(62, 120, 122);\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(5, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(300, 80));
        pushButton_2->setMaximumSize(QSize(300, 80));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(62, 120, 122);\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;\n"
"font: 75 20pt \"Malgun Gothic\";"));

        verticalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(145, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(450, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_5, 0, 3, 3, 1);

        verticalSpacer = new QSpacerItem(17, 90, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer, 0, 0, 3, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 1, 1, 2, 2);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "New Game", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Exit", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
