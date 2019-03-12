#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<qmessagebox.h>
#include"rank.h"
#include"login.h"
#include <QLabel>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();



private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void start();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
