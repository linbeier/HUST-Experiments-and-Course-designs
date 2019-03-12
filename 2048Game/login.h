#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"qlineedit.h"
#include"qstring.h"
#include"qpushbutton.h"
#include"game.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    QString stuname;
private:
    Ui::login *ui;
    //“name”标签
    QLineEdit *nameedt;
    QPushButton *ready;

private slots:
    void start2048();
};

#endif // LOGIN_H
