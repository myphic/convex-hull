/********************************************************************************
** Form generated from reading UI file 'mazemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZEMAINWINDOW_H
#define UI_MAZEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MazeMainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MazeMainWindow)
    {
        if (MazeMainWindow->objectName().isEmpty())
            MazeMainWindow->setObjectName(QString::fromUtf8("MazeMainWindow"));
        MazeMainWindow->resize(550, 550);
        action = new QAction(MazeMainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(MazeMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MazeMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MazeMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 21));
        MazeMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MazeMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MazeMainWindow->setStatusBar(statusBar);

        retranslateUi(MazeMainWindow);

        QMetaObject::connectSlotsByName(MazeMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MazeMainWindow)
    {
        MazeMainWindow->setWindowTitle(QCoreApplication::translate("MazeMainWindow", "MazeMainWindow", nullptr));
        action->setText(QCoreApplication::translate("MazeMainWindow", "\320\235\320\276\320\262\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MazeMainWindow: public Ui_MazeMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZEMAINWINDOW_H
