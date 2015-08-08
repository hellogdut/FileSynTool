/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <customlistwidget.h>
#include "customedit.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    CustomEdit *watchEdit;
    QPushButton *pushButton_2;
    QLabel *label_1;
    CustomEdit *compareEdit;
    QPushButton *pushButton;
    QCheckBox *autoSyn;
    QPushButton *manualSyn;
    QWidget *tab_8;
    QLabel *label;
    CustomListWidget *listWidget;
    QPushButton *pushButton_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(647, 556);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        layoutWidget = new QWidget(tab_1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 581, 471));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        watchEdit = new CustomEdit(layoutWidget);
        watchEdit->setObjectName(QStringLiteral("watchEdit"));

        gridLayout->addWidget(watchEdit, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        gridLayout->addWidget(label_1, 1, 0, 1, 1);

        compareEdit = new CustomEdit(layoutWidget);
        compareEdit->setObjectName(QStringLiteral("compareEdit"));

        gridLayout->addWidget(compareEdit, 1, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton, 1, 2, 1, 1);

        autoSyn = new QCheckBox(layoutWidget);
        autoSyn->setObjectName(QStringLiteral("autoSyn"));

        gridLayout->addWidget(autoSyn, 2, 0, 1, 1);

        manualSyn = new QPushButton(layoutWidget);
        manualSyn->setObjectName(QStringLiteral("manualSyn"));
        sizePolicy.setHeightForWidth(manualSyn->sizePolicy().hasHeightForWidth());
        manualSyn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(manualSyn, 2, 1, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        label = new QLabel(tab_8);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 40, 81, 16));
        listWidget = new CustomListWidget(tab_8);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(70, 70, 231, 231));
        pushButton_3 = new QPushButton(tab_8);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 310, 75, 20));
        tabWidget->addTab(tab_8, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\233\221\350\247\206\346\226\207\344\273\266\343\200\201\346\226\207\344\273\266\345\244\271", 0));
        watchEdit->setPlaceholderText(QApplication::translate("MainWindow", "\346\224\257\346\214\201\346\213\226\346\213\275\357\274\214\345\277\253\345\210\260\347\242\227\351\207\214\346\235\245", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        label_1->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\347\233\256\345\275\225", 0));
        compareEdit->setPlaceholderText(QApplication::translate("MainWindow", "\345\277\253\345\210\260\347\242\227\351\207\214\346\235\245", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        autoSyn->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\220\214\346\255\245", 0));
        manualSyn->setText(QApplication::translate("MainWindow", "\345\274\272\345\210\266\345\220\214\346\255\245", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\214\346\255\245", 0));
        label->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\345\210\227\350\241\250", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "\350\260\203\350\257\225\346\250\241\345\274\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
