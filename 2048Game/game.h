#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include"qlabel.h"
#include"qlineedit.h"
#include"qmessagebox.h"
#include"qfile.h"
#include <qtextstream.h>
#include"qiodevice.h"
#include"qmediaplayer.h"

#define LBLSTYLESHEET "QLabel {color: orange;background: #FFFFCC;border: %1px solid orange;border-radius: %2px;}"
#define BTNSTYLESHEET "QPushButton {color: red;background: lightgray;border: %1px solid darkgray;border-radius: %2px;}QPushButton:pressed{color: white;background: orange;border: %1px solid darkgray;border-radius: %2px;}"


namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();
    typedef struct
    {
        QString name;
        int score;
    }record;
    QString name;
    void keyPressEvent(QKeyEvent  *event);
private:
    Ui::game *ui;
    //
    int board[4][4];
    //
    int returnboard[1000][4][4];
    //
    int returnscore[1000];
    int step=0;
    int i,j,l;
    //
    int score;
    //
    void initboard();
    //
    QPushButton *up;
    QPushButton *down;
    QPushButton *left;
    QPushButton *right;
    QPushButton *restartBtn;
    QPushButton *returnBtn;
    QPushButton *voice;
    QPushButton *huiqi;
    //“score”标签
    QLabel *scoreLbl;
    QMediaPlayer *player;
    //
    void paintEvent(QPaintEvent *);
    //
    void win();
    void gameover();
    record tenname[10];
public slots:
    void onScoreInt(int);
    void onGameOver();
    void onWin();
    int moveleft();
    int moveright();
    int moveup();
    int movedown();
    void restore();
    void restart();
    void return1();
    void play();
    void returnstep();
};

#endif // GAME_H
