#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QTimer>
#include <QStringList>
#include <QRegExp>
#include <QDebug>
#include <QCoreApplication>
#include <QTime>
#include <dirent.h>
#include <QListWidgetItem>
#include "qcustomplot/qcustomplot.h"
#include <QQueue>
#include <QVector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //int getstart();
    QString tempstr,pro;
    QQueue<double> cpupoint;
    QQueue<int> cputime;
    int cpucount=0;
    QFile tempfile;
    QFile tempfile2;
    int getstart();
    void pidread(char *path);
    void graphshow(QCustomPlot *customplot);
public slots:
    void cpuupdate();
    void memupdate();
    void pidupdate();
    void graph();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int sleepcount=0,runcount=0,stopcount=0;
    int changerangeflag=0;
};

#endif // MAINWINDOW_H
