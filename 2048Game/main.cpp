#include "dialog.h"
#include <QApplication>
#include <QtGui>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog *w=new Dialog;
    w->setObjectName("mainwin");
    w->setWindowTitle("2048main");
    w->setStyleSheet("Dialog#mainwin{border-image:url(:/image/2048bck.png);}");
    w->show();
    return a.exec();
}

