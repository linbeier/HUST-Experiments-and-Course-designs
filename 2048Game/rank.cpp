#include "rank.h"
#include "ui_rank.h"
#include "qfile.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <qtextstream.h>
#include"qiodevice.h"
typedef struct
{
    char name[10];
    int score;
}record;

Rank::Rank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);
    //
    QFile fp("/Users/bin/rank");
    QString str;
    QFont font1;
    font1.setFamily("Consolas");
    font1.setBold(true);
    font1.setPixelSize(15);

      fp.open( QIODevice::ReadOnly);
        QTextStream out(&fp);

            str=out.readLine();
            ui->name1->setText(QString(str));
            ui->name1->setFont(font1);
            str=out.readLine();
            ui->score1->setText(QString(str));
            ui->score1->setFont(font1);
            str=out.readLine();
            ui->name2->setText(QString(str));
            ui->name2->setFont(font1);
            str=out.readLine();
            ui->score2->setText(QString(str));
            ui->score2->setFont(font1);
            str=out.readLine();
            ui->name3->setText(QString(str));
            ui->name3->setFont(font1);
            str=out.readLine();
            ui->score3->setText(QString(str));
            ui->score3->setFont(font1);
            str=out.readLine();
            ui->name4->setText(QString(str));
            ui->name4->setFont(font1);
            str=out.readLine();
            ui->score4->setText(QString(str));
            ui->score4->setFont(font1);
            str=out.readLine();
            ui->name5->setText(QString(str));
            ui->name5->setFont(font1);
            str=out.readLine();
            ui->score5->setText(QString(str));
            ui->score5->setFont(font1);
            str=out.readLine();
            ui->name6->setText(QString(str));
            ui->name6->setFont(font1);
            str=out.readLine();
            ui->score6->setText(QString(str));
            ui->score6->setFont(font1);
            str=out.readLine();
            ui->name7->setText(QString(str));
            ui->name7->setFont(font1);
            str=out.readLine();
            ui->score7->setText(QString(str));
            ui->score7->setFont(font1);
            str=out.readLine();
            ui->name8->setText(QString(str));
            ui->name8->setFont(font1);
            str=out.readLine();
            ui->score8->setText(QString(str));
            ui->score8->setFont(font1);
            str=out.readLine();
            ui->name9->setText(QString(str));
            ui->name9->setFont(font1);
            str=out.readLine();
            ui->score9->setText(QString(str));
            ui->score9->setFont(font1);
            str=out.readLine();
            ui->name10->setText(QString(str));
            ui->name10->setFont(font1);
            str=out.readLine();
            ui->score10->setText(QString(str));
            ui->score10->setFont(font1);
       fp.close();

}

Rank::~Rank()
{
    delete ui;

}
