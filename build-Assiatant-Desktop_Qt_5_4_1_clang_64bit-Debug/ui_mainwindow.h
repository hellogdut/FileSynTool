/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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
#include <QtWidgets/QGroupBox>
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
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_1;
    CustomEdit *compareEdit;
    QPushButton *pushButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    CustomEdit *watchEdit;
    QPushButton *pushButton_2;
    QPushButton *manualSyn;
    QCheckBox *autoSyn;
    QWidget *tab_8;
    QLabel *label;
    CustomListWidget *listWidget;
    QPushButton *pushButton_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(603, 484);
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
        groupBox = new QGroupBox(tab_1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 290, 96, 104));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(13, 30, 77, 20));
        checkBox->setChecked(true);
        checkBox->setTristate(false);
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(13, 51, 77, 20));
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setEnabled(false);
        checkBox_3->setGeometry(QRect(13, 72, 77, 20));
        widget = new QWidget(tab_1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 150, 491, 131));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(widget);
        label_1->setObjectName(QStringLiteral("label_1"));

        horizontalLayout_3->addWidget(label_1);

        compareEdit = new CustomEdit(widget);
        compareEdit->setObjectName(QStringLiteral("compareEdit"));

        horizontalLayout_3->addWidget(compareEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton);

        widget1 = new QWidget(tab_1);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(21, 18, 491, 121));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        watchEdit = new CustomEdit(widget1);
        watchEdit->setObjectName(QStringLiteral("watchEdit"));

        horizontalLayout_2->addWidget(watchEdit);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_2);

        manualSyn = new QPushButton(tab_1);
        manualSyn->setObjectName(QStringLiteral("manualSyn"));
        manualSyn->setGeometry(QRect(135, 340, 94, 32));
        sizePolicy.setHeightForWidth(manualSyn->sizePolicy().hasHeightForWidth());
        manualSyn->setSizePolicy(sizePolicy);
        autoSyn = new QCheckBox(tab_1);
        autoSyn->setObjectName(QStringLiteral("autoSyn"));
        autoSyn->setGeometry(QRect(140, 314, 77, 20));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\220\214\346\255\245\351\200\211\351\241\271", 0));
        checkBox->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\242\236\345\212\240", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\277\256\346\224\271", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\210\240\351\231\244", 0));
        label_1->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\346\226\207\344\273\266\345\244\271          ", 0));
        compareEdit->setPlaceholderText(QApplication::translate("MainWindow", "\345\277\253\345\210\260\347\242\227\351\207\214\346\235\245", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\233\221\350\247\206\346\226\207\344\273\266\343\200\201\346\226\207\344\273\266\345\244\271", 0));
        watchEdit->setPlaceholderText(QApplication::translate("MainWindow", "\346\224\257\346\214\201\346\213\226\346\213\275\357\274\214\345\277\253\345\210\260\347\242\227\351\207\214\346\235\245", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        manualSyn->setText(QApplication::translate("MainWindow", "\347\253\213\345\215\263\345\220\214\346\255\245", 0));
        autoSyn->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\220\214\346\255\245", 0));
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
