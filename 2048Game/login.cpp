#include "login.h"
#include "ui_login.h"

#include"qpushbutton.h"
#include"qlineedit.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QFont font1;
    font1.setFamily("Consolas");
    font1.setBold(true);
    font1.setPixelSize(16);
    //name标签
    //
    nameedt=new QLineEdit(this);
    nameedt->setGeometry(80,120,240,50);
    nameedt->setPlaceholderText("Welcome!What's your name?");
    nameedt->setEchoMode(QLineEdit::Normal);

    ready = new QPushButton("ready!",this);
    ready->setGeometry(150,220,100,40);
    ready->setFont(font1);
    ready->setStyleSheet("QPushButton{color:orange;}");
    connect(ready,SIGNAL(clicked()),this,SLOT(start2048()));
}
void login::start2048(){
    stuname=nameedt->text();
    game *d=new game(this);
    d->name=stuname;
    d->setWindowTitle("2048start!");
    d->setStyleSheet("background-color:orange;");
    this->hide();
    d->show();
    d->exec();

}
login::~login()
{
    delete ui;
    delete nameedt;
    delete ready;
}
