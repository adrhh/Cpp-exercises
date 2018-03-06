/********************************************************************************
** Form generated from reading UI file 'e02.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_E02_H
#define UI_E02_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_e02Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *e02Class)
    {
        if (e02Class->objectName().isEmpty())
            e02Class->setObjectName(QStringLiteral("e02Class"));
        e02Class->resize(600, 400);
        menuBar = new QMenuBar(e02Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        e02Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(e02Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        e02Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(e02Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        e02Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(e02Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        e02Class->setStatusBar(statusBar);

        retranslateUi(e02Class);

        QMetaObject::connectSlotsByName(e02Class);
    } // setupUi

    void retranslateUi(QMainWindow *e02Class)
    {
        e02Class->setWindowTitle(QApplication::translate("e02Class", "e02", nullptr));
    } // retranslateUi

};

namespace Ui {
    class e02Class: public Ui_e02Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_E02_H
