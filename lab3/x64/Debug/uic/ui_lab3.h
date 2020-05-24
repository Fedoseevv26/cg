/********************************************************************************
** Form generated from reading UI file 'lab3.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB3_H
#define UI_LAB3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab3Class)
    {
        if (lab3Class->objectName().isEmpty())
            lab3Class->setObjectName(QString::fromUtf8("lab3Class"));
        lab3Class->resize(600, 400);
        menuBar = new QMenuBar(lab3Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        lab3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab3Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        lab3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(lab3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lab3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lab3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        lab3Class->setStatusBar(statusBar);

        retranslateUi(lab3Class);

        QMetaObject::connectSlotsByName(lab3Class);
    } // setupUi

    void retranslateUi(QMainWindow *lab3Class)
    {
        lab3Class->setWindowTitle(QCoreApplication::translate("lab3Class", "lab3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab3Class: public Ui_lab3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB3_H
