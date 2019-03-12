#include "dialog.h"
#include "ui_dialog.h"

struct record
{
    char name[10];
    int score;
};

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(start()));

}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::start(){

    login *b=new login(this);
    b->setWindowTitle("2048login!");
    this->hide();
    b->show();
    b->exec();
    this->show();
}

void Dialog::on_pushButton_4_clicked()
{
    QApplication* app;
      app->exit(0);
}

void Dialog::on_pushButton_3_clicked()
{

    QMessageBox::information(NULL, "帮助", "1玩家可以通过键盘上下左右和相应界面上的方向键进行控制\n2点击voice可以将音效关闭\n3首次悔棋需要按两次悔棋键（防止误按）\n\n这是IS1602林晓斌的作品，作品基于Qt4.5.1");

}


void Dialog::on_pushButton_2_clicked()
{
    Rank *a;
    a = new Rank(this);
    a->setObjectName("ranklist");
    a->setWindowTitle("rank!");
    this->hide();
    a->setStyleSheet("Rank#ranklist{border-image:url(:/image/bck2.jpg);}");
    a->show();
    a->exec();
    this->show();
}


