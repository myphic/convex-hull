/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *up;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QPushButton *start;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QLabel *label_12;
    QWidget *widget;
    QLabel *label_7;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *score;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *health;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *attake;
    QPushButton *pushButton_5;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1293, 670);
        Form->setStyleSheet(QString::fromUtf8("background-color:rgb(63,62,60);"));
        gridLayout_4 = new QGridLayout(Form);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(20);
        gridLayout_2->setVerticalSpacing(6);
        up = new QPushButton(Form);
        up->setObjectName(QString::fromUtf8("up"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(up->sizePolicy().hasHeightForWidth());
        up->setSizePolicy(sizePolicy);
        up->setMinimumSize(QSize(0, 0));
        up->setMaximumSize(QSize(100, 50));
        up->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(up, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(80, 21, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(80, 21, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(80, 21, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(80, 21, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        left = new QPushButton(Form);
        left->setObjectName(QString::fromUtf8("left"));
        left->setMinimumSize(QSize(0, 0));
        left->setMaximumSize(QSize(100, 50));
        left->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(left, 1, 0, 1, 1);

        right = new QPushButton(Form);
        right->setObjectName(QString::fromUtf8("right"));
        right->setMinimumSize(QSize(0, 0));
        right->setMaximumSize(QSize(100, 50));
        right->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(right, 1, 2, 1, 1);

        down = new QPushButton(Form);
        down->setObjectName(QString::fromUtf8("down"));
        down->setMinimumSize(QSize(0, 0));
        down->setMaximumSize(QSize(100, 50));
        down->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(down, 2, 1, 1, 1);

        start = new QPushButton(Form);
        start->setObjectName(QString::fromUtf8("start"));
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);
        start->setMaximumSize(QSize(100, 100));
        start->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(start, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(Form);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 0));
        pushButton_8->setMaximumSize(QSize(100, 30));
        pushButton_8->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_7 = new QPushButton(Form);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 0));
        pushButton_7->setMaximumSize(QSize(100, 30));
        pushButton_7->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout->addWidget(pushButton_7, 1, 3, 1, 1);

        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMinimumSize(QSize(0, 0));
        textBrowser->setMaximumSize(QSize(1000, 200));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 75 10pt \"Malgun Gothic\";\n"
"color: rgb(62, 120, 122);\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 4);

        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setMaximumSize(QSize(700, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 75 10pt \"Malgun Gothic\";\n"
"color: rgb(62, 120, 122);\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        label_12 = new QLabel(Form);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(1000, 16777215));

        gridLayout_3->addWidget(label_12, 0, 0, 1, 1);

        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 79, 200, 151));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(200, 200));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 250, 136, 134));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMaximumSize(QSize(100, 16777215));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(label_8);

        score = new QLabel(layoutWidget);
        score->setObjectName(QString::fromUtf8("score"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(score->sizePolicy().hasHeightForWidth());
        score->setSizePolicy(sizePolicy3);
        score->setMaximumSize(QSize(50, 16777215));
        score->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(score);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        horizontalLayout_2->addWidget(label_2);

        health = new QLabel(layoutWidget);
        health->setObjectName(QString::fromUtf8("health"));
        health->setMaximumSize(QSize(50, 16777215));
        health->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        horizontalLayout_2->addWidget(health);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        horizontalLayout_3->addWidget(label_3);

        attake = new QLabel(layoutWidget);
        attake->setObjectName(QString::fromUtf8("attake"));
        attake->setMaximumSize(QSize(50, 16777215));
        attake->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));

        horizontalLayout_3->addWidget(attake);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 20, 91, 50));
        pushButton_5->setMaximumSize(QSize(100, 50));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 75 15pt \"Malgun Gothic\";\n"
"color: white;\n"
"border:5px solid  rgb(62, 120, 122);\n"
"border-radius: 5px;"));
        layoutWidget->raise();
        label_7->raise();
        pushButton_5->raise();

        gridLayout_3->addWidget(widget, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        up->setText(QCoreApplication::translate("Form", "up", nullptr));
        left->setText(QCoreApplication::translate("Form", "left", nullptr));
        right->setText(QCoreApplication::translate("Form", "right", nullptr));
        down->setText(QCoreApplication::translate("Form", "down", nullptr));
        start->setText(QCoreApplication::translate("Form", "Quite", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Form", "drop", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Form", "pick up", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Malgun Gothic'; font-size:10pt; font-weight:72; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">               #######################################</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">              ##                                                                                              ##</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-b"
                        "lock-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">             ##          Devoloped by:                                                             ##</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">            ##                                 Ahmed alshlemy                                    ##</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">           ##                                 Ahmed salah                                          ##</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2"
                        "'; font-size:8pt; font-weight:400;\">          ##                                 Ahmed ayman                                        ##</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">         ##                                 Ahmedsaad                                            ##</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">        ##                                 Abd al hamiad                                         ##</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400;\">       #####################################"
                        "###</span></p></body></html>", nullptr));
        label_12->setText(QString());
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("Form", "Score : ", nullptr));
        score->setText(QCoreApplication::translate("Form", "0", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Health : ", nullptr));
        health->setText(QCoreApplication::translate("Form", "0", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Attack : ", nullptr));
        attake->setText(QCoreApplication::translate("Form", "0", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Form", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
