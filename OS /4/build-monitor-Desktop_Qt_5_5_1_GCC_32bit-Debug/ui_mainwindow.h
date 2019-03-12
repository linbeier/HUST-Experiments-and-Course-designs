/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *tab_2;
    QProgressBar *progressBar;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *cpu_total;
    QLabel *cpu_used;
    QLabel *cpu_left;
    QCustomPlot *widget;
    QWidget *tab_3;
    QLabel *label_17;
    QLabel *label_18;
    QProgressBar *progressBar_2;
    QLabel *memory_used;
    QLabel *memory_left;
    QLabel *memory_total;
    QLabel *label_19;
    QLabel *swap_left;
    QProgressBar *progressBar_3;
    QLabel *swap_total;
    QLabel *swap_used;
    QWidget *tab_4;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QListWidget *listWidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *tab_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(501, 403);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 501, 281));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 101, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 140, 101, 21));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 170, 101, 21));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 200, 101, 21));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 110, 321, 31));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 140, 91, 21));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(150, 170, 91, 21));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(150, 200, 331, 31));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 91, 31));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 40, 111, 31));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 70, 111, 31));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(150, 20, 81, 21));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(150, 40, 311, 31));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(150, 70, 341, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        progressBar = new QProgressBar(tab_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(110, 40, 321, 23));
        progressBar->setValue(24);
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 10, 101, 21));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(70, 40, 31, 21));
        cpu_total = new QLabel(tab_2);
        cpu_total->setObjectName(QStringLiteral("cpu_total"));
        cpu_total->setGeometry(QRect(110, 70, 111, 17));
        cpu_used = new QLabel(tab_2);
        cpu_used->setObjectName(QStringLiteral("cpu_used"));
        cpu_used->setGeometry(QRect(230, 70, 111, 17));
        cpu_left = new QLabel(tab_2);
        cpu_left->setObjectName(QStringLiteral("cpu_left"));
        cpu_left->setGeometry(QRect(350, 70, 111, 17));
        widget = new QCustomPlot(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 110, 421, 121));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 10, 111, 21));
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(40, 50, 67, 17));
        progressBar_2 = new QProgressBar(tab_3);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(110, 50, 321, 23));
        progressBar_2->setValue(24);
        memory_used = new QLabel(tab_3);
        memory_used->setObjectName(QStringLiteral("memory_used"));
        memory_used->setGeometry(QRect(230, 80, 111, 17));
        memory_left = new QLabel(tab_3);
        memory_left->setObjectName(QStringLiteral("memory_left"));
        memory_left->setGeometry(QRect(350, 80, 101, 17));
        memory_total = new QLabel(tab_3);
        memory_total->setObjectName(QStringLiteral("memory_total"));
        memory_total->setGeometry(QRect(110, 80, 111, 17));
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(60, 120, 41, 21));
        swap_left = new QLabel(tab_3);
        swap_left->setObjectName(QStringLiteral("swap_left"));
        swap_left->setGeometry(QRect(350, 150, 91, 17));
        progressBar_3 = new QProgressBar(tab_3);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(110, 120, 321, 23));
        progressBar_3->setValue(24);
        swap_total = new QLabel(tab_3);
        swap_total->setObjectName(QStringLiteral("swap_total"));
        swap_total->setGeometry(QRect(110, 150, 111, 17));
        swap_used = new QLabel(tab_3);
        swap_used->setObjectName(QStringLiteral("swap_used"));
        swap_used->setGeometry(QRect(230, 150, 111, 17));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(360, 30, 111, 41));
        label_21 = new QLabel(tab_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(360, 80, 111, 41));
        label_22 = new QLabel(tab_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(360, 130, 111, 41));
        listWidget = new QListWidget(tab_4);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 331, 221));
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 220, 99, 27));
        pushButton_4 = new QPushButton(tab_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(390, 180, 99, 27));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 300, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(398, 300, 91, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 501, 31));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "model name:", 0));
        label_3->setText(QApplication::translate("MainWindow", "cpu cores:", 0));
        label_4->setText(QApplication::translate("MainWindow", "cache sizes:", 0));
        label_5->setText(QApplication::translate("MainWindow", "address size:", 0));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_9->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label->setText(QApplication::translate("MainWindow", "system type:", 0));
        label_10->setText(QApplication::translate("MainWindow", "system version:", 0));
        label_11->setText(QApplication::translate("MainWindow", "gcc version:", 0));
        label_12->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_13->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_14->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "info", 0));
        label_15->setText(QApplication::translate("MainWindow", "CPU using rate", 0));
        label_16->setText(QApplication::translate("MainWindow", "cpu:", 0));
        cpu_total->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        cpu_used->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        cpu_left->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "CPU", 0));
        label_17->setText(QApplication::translate("MainWindow", "memory&swap", 0));
        label_18->setText(QApplication::translate("MainWindow", "memory:", 0));
        memory_used->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        memory_left->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        memory_total->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_19->setText(QApplication::translate("MainWindow", "swap:", 0));
        swap_left->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        swap_total->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        swap_used->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "memory", 0));
        label_20->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_21->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_22->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "kill", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "refresh", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "process", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "help", 0));
        pushButton->setText(QApplication::translate("MainWindow", "shut down", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "reboot", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
