/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *choose2btn;
    QLabel *label_2;
    QTextBrowser *resultshow;
    QPushButton *comparebtn;
    QPushButton *choose1btn;
    QLabel *label;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QWidget *tab_2;
    QPushButton *CFG_compare_btn;
    QPushButton *CFG_get_btn1;
    QPushButton *CFG_get_btn2;
    QTextEdit *CFG_file_show;
    QLabel *label_3;
    QTextEdit *CFG_filefold_show;
    QLabel *label_4;
    QTextBrowser *CFG_resultshow;
    QLabel *label_5;
    QLabel *picshow;
    QWidget *tab_3;
    QTextEdit *CFG_file_show_2;
    QPushButton *CFG_get_btn1_2;
    QTextEdit *CFG_filefold_show_2;
    QPushButton *CFG_get_btn2_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *CFG_compare_btn_2;
    QLabel *CFG_show;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTextEdit *CFG_resultshow_2;
    QWidget *tab_4;
    QPushButton *choose2btn_2;
    QTextEdit *textEdit_4;
    QLabel *label_10;
    QPushButton *comparebtn_2;
    QPushButton *comparebtn_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *resultshow_2;
    QWidget *tab_5;
    QLabel *label_11;
    QTextBrowser *resultshow_3;
    QPushButton *choose2btn_3;
    QTextEdit *textEdit_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(608, 543);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 611, 481));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        choose2btn = new QPushButton(tab);
        choose2btn->setObjectName(QStringLiteral("choose2btn"));
        choose2btn->setGeometry(QRect(410, 170, 113, 32));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 110, 131, 31));
        resultshow = new QTextBrowser(tab);
        resultshow->setObjectName(QStringLiteral("resultshow"));
        resultshow->setGeometry(QRect(70, 260, 301, 111));
        comparebtn = new QPushButton(tab);
        comparebtn->setObjectName(QStringLiteral("comparebtn"));
        comparebtn->setGeometry(QRect(410, 300, 113, 32));
        choose1btn = new QPushButton(tab);
        choose1btn->setObjectName(QStringLiteral("choose1btn"));
        choose1btn->setGeometry(QRect(410, 60, 113, 32));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 20, 81, 31));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(70, 60, 301, 31));
        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(70, 150, 301, 71));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        CFG_compare_btn = new QPushButton(tab_2);
        CFG_compare_btn->setObjectName(QStringLiteral("CFG_compare_btn"));
        CFG_compare_btn->setGeometry(QRect(190, 380, 113, 32));
        CFG_get_btn1 = new QPushButton(tab_2);
        CFG_get_btn1->setObjectName(QStringLiteral("CFG_get_btn1"));
        CFG_get_btn1->setGeometry(QRect(190, 80, 113, 32));
        CFG_get_btn2 = new QPushButton(tab_2);
        CFG_get_btn2->setObjectName(QStringLiteral("CFG_get_btn2"));
        CFG_get_btn2->setGeometry(QRect(190, 200, 113, 32));
        CFG_file_show = new QTextEdit(tab_2);
        CFG_file_show->setObjectName(QStringLiteral("CFG_file_show"));
        CFG_file_show->setGeometry(QRect(120, 40, 261, 31));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 40, 81, 31));
        CFG_filefold_show = new QTextEdit(tab_2);
        CFG_filefold_show->setObjectName(QStringLiteral("CFG_filefold_show"));
        CFG_filefold_show->setGeometry(QRect(120, 120, 261, 71));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 140, 101, 31));
        CFG_resultshow = new QTextBrowser(tab_2);
        CFG_resultshow->setObjectName(QStringLiteral("CFG_resultshow"));
        CFG_resultshow->setGeometry(QRect(120, 250, 261, 121));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 300, 71, 20));
        picshow = new QLabel(tab_2);
        picshow->setObjectName(QStringLiteral("picshow"));
        picshow->setGeometry(QRect(410, 40, 151, 331));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        CFG_file_show_2 = new QTextEdit(tab_3);
        CFG_file_show_2->setObjectName(QStringLiteral("CFG_file_show_2"));
        CFG_file_show_2->setGeometry(QRect(120, 50, 261, 31));
        CFG_get_btn1_2 = new QPushButton(tab_3);
        CFG_get_btn1_2->setObjectName(QStringLiteral("CFG_get_btn1_2"));
        CFG_get_btn1_2->setGeometry(QRect(190, 90, 113, 32));
        CFG_filefold_show_2 = new QTextEdit(tab_3);
        CFG_filefold_show_2->setObjectName(QStringLiteral("CFG_filefold_show_2"));
        CFG_filefold_show_2->setGeometry(QRect(120, 130, 261, 71));
        CFG_get_btn2_2 = new QPushButton(tab_3);
        CFG_get_btn2_2->setObjectName(QStringLiteral("CFG_get_btn2_2"));
        CFG_get_btn2_2->setGeometry(QRect(190, 210, 113, 32));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 50, 81, 31));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 320, 71, 20));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 150, 101, 31));
        CFG_compare_btn_2 = new QPushButton(tab_3);
        CFG_compare_btn_2->setObjectName(QStringLiteral("CFG_compare_btn_2"));
        CFG_compare_btn_2->setGeometry(QRect(120, 390, 113, 32));
        CFG_show = new QLabel(tab_3);
        CFG_show->setObjectName(QStringLiteral("CFG_show"));
        CFG_show->setGeometry(QRect(420, 50, 151, 331));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 390, 113, 32));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(122, 420, 111, 32));
        CFG_resultshow_2 = new QTextEdit(tab_3);
        CFG_resultshow_2->setObjectName(QStringLiteral("CFG_resultshow_2"));
        CFG_resultshow_2->setGeometry(QRect(120, 270, 261, 111));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        choose2btn_2 = new QPushButton(tab_4);
        choose2btn_2->setObjectName(QStringLiteral("choose2btn_2"));
        choose2btn_2->setGeometry(QRect(100, 350, 113, 32));
        textEdit_4 = new QTextEdit(tab_4);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(70, 60, 181, 281));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(100, 20, 131, 31));
        comparebtn_2 = new QPushButton(tab_4);
        comparebtn_2->setObjectName(QStringLiteral("comparebtn_2"));
        comparebtn_2->setGeometry(QRect(340, 360, 113, 32));
        comparebtn_3 = new QPushButton(tab_4);
        comparebtn_3->setObjectName(QStringLiteral("comparebtn_3"));
        comparebtn_3->setGeometry(QRect(470, 360, 113, 32));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 400, 113, 32));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 400, 113, 32));
        resultshow_2 = new QTextEdit(tab_4);
        resultshow_2->setObjectName(QStringLiteral("resultshow_2"));
        resultshow_2->setGeometry(QRect(340, 60, 241, 291));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(230, 30, 131, 31));
        resultshow_3 = new QTextBrowser(tab_5);
        resultshow_3->setObjectName(QStringLiteral("resultshow_3"));
        resultshow_3->setGeometry(QRect(100, 260, 391, 111));
        choose2btn_3 = new QPushButton(tab_5);
        choose2btn_3->setObjectName(QStringLiteral("choose2btn_3"));
        choose2btn_3->setGeometry(QRect(230, 210, 113, 32));
        textEdit_5 = new QTextEdit(tab_5);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(60, 80, 471, 111));
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 608, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        choose2btn->setText(QApplication::translate("MainWindow", "choose", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "choose compare file", nullptr));
        comparebtn->setText(QApplication::translate("MainWindow", "compare", nullptr));
        choose1btn->setText(QApplication::translate("MainWindow", "choose", nullptr));
        label->setText(QApplication::translate("MainWindow", "choose file", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\345\220\214\346\272\220\346\200\247\346\243\200\346\265\213", nullptr));
        CFG_compare_btn->setText(QApplication::translate("MainWindow", "compare", nullptr));
        CFG_get_btn1->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        CFG_get_btn2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "choose file", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "choose file fold", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "result show", nullptr));
        picshow->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "CFG\345\257\271\346\257\224", nullptr));
        CFG_get_btn1_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        CFG_get_btn2_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "choose file", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "result show", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "choose file fold", nullptr));
        CFG_compare_btn_2->setText(QApplication::translate("MainWindow", "compare JAVA", nullptr));
        CFG_show->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "compare C#", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "JavaScript", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\350\267\250\350\257\255\350\250\200\345\220\214\346\272\220\346\200\247\346\243\200\346\265\213", nullptr));
        choose2btn_2->setText(QApplication::translate("MainWindow", "choose", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "choose compare file", nullptr));
        comparebtn_2->setText(QApplication::translate("MainWindow", "\346\240\210\346\272\242\345\207\272", nullptr));
        comparebtn_3->setText(QApplication::translate("MainWindow", "\346\225\264\346\225\260\345\256\275\345\272\246\346\272\242\345\207\272", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\240\274\345\274\217\345\214\226\345\255\227\347\254\246\344\270\262", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\251\272\346\214\207\351\222\210\345\274\225\347\224\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\347\274\223\345\206\262\345\214\272\346\272\242\345\207\272\346\243\200\346\265\213", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "choose compare file", nullptr));
        choose2btn_3->setText(QApplication::translate("MainWindow", "choose", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
