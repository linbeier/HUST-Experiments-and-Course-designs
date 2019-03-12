#include "game.h"
#include "ui_game.h"

#include <qtextstream.h>
#include"qiodevice.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"qpainter.h"
#include"qmath.h"
#include <string.h>
#include"qpushbutton.h"
#include"QTime"
#include"QtGlobal"
#include <QKeyEvent>
// 颜色数组 存储每个数字对应的背景色
QColor digitBkg[11] = {QColor::fromRgb(0xFF, 0xFF, 0xCC), QColor::fromRgb(0xFF, 0xFF, 0x99),
                            QColor::fromRgb(0xFF, 0xCC, 0xCC), QColor::fromRgb(0xFF, 0xCC, 0x99),
                            QColor::fromRgb(0xFF, 0x99, 0x99), QColor::fromRgb(0xFF, 0x99, 0x66),
                            QColor::fromRgb(0xFF, 0x66, 0x66), QColor::fromRgb(0xCC, 0x99, 0x66),
                            QColor::fromRgb(0xCC, 0x33, 0x33), QColor::fromRgb(0xCC, 0x00, 0x33),
                            QColor::fromRgb(0xFF, 0x00, 0x00)};
typedef struct
{
    QString name;
    int score;
}record;

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);


    up= new QPushButton(this);
    up->setGeometry(540,310,45,45);
    up->setStyleSheet("QPushButton{border-image: url(:/image/up.png);}"
                          "QPushButton:pressed{border-image: url(:/image/upclick.png);}");
    connect(up,SIGNAL(clicked()),this,SLOT(moveup()));

    down= new QPushButton(this);
    down->setGeometry(540,410,45,45);
    down->setStyleSheet("QPushButton{border-image: url(:/image/down.png);}"
                          "QPushButton:pressed{border-image: url(:/image/downclick.png);}");
    connect(down,SIGNAL(clicked()),this,SLOT(movedown()));

    left = new QPushButton(this);
    left->setGeometry(490,360,45,45);
    left->setStyleSheet("QPushButton{border-image: url(:/image/left.png);}"
                          "QPushButton:pressed{border-image: url(:/image/leftclick.png);}");
     connect(left,SIGNAL(clicked()),this,SLOT(moveleft()));

     right = new QPushButton(this);
     right->setGeometry(590,360,45,45);
     right->setStyleSheet("QPushButton{border-image: url(:/image/right.png);}"
                          "QPushButton:pressed{border-image: url(:/image/rightclick.png);}");
     connect(right,SIGNAL(clicked()),this,SLOT(moveright()));
    //设置焦点
    Qt::ClickFocus;
    //分数
    step=0;
    //初始化棋盘
    initboard();
    //设立随机数种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //字体对象
    QFont font1;
    font1.setFamily("Consolas");
    font1.setBold(true);
    font1.setPixelSize(25);
    QFont font2;
    font2.setFamily("Consolas");
    font2.setBold(true);
    font2.setPixelSize(16);
    //restart按钮
    restartBtn = new QPushButton("restart",this);
    restartBtn->setGeometry(515,20,100,45);
    restartBtn->setFont(font1);
    restartBtn->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    connect(restartBtn,SIGNAL(clicked()),this,SLOT(restart()));

    //score标签
    scoreLbl= new QLabel(QString("score:\n0"),this);
    scoreLbl->setGeometry(515,100,100,70);
    scoreLbl->setFont(font1);
    scoreLbl->setAlignment(Qt::AlignCenter);
    scoreLbl->setStyleSheet(QString(LBLSTYLESHEET).arg(5).arg(20));
    //returnButton
    returnBtn= new QPushButton("return",this);
    returnBtn->setGeometry(515,210,100,50);
    returnBtn->setFont(font1);
    returnBtn->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    connect(returnBtn,SIGNAL(clicked()),this,SLOT(return1()));
    //voiceButton
    voice= new QPushButton("voice",this);
    voice->setGeometry(0,0,80,40);
    voice->setFont(font1);
    voice->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    connect(voice,SIGNAL(clicked()),this,SLOT(play()));
    //音乐文件
    player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("/Users/bin/Desktop/橋本由香利 - キ・メ・ゼ・リ・フ.mp3"));
    player->setVolume(40);
    player->play();
    //悔棋Button
    huiqi= new QPushButton("悔棋",this);
    huiqi->setGeometry(542,362,40,40);
    huiqi->setFont(font2);
    huiqi->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    connect(huiqi,SIGNAL(clicked()),this,SLOT(returnstep()));
    //

    //先将第一步棋盘存入
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            returnboard[step][i][j]=board[i][j];
        }
    }
    returnscore[step]=0;
    step++;
   }
//回到上一步
void game::returnstep(){
    step--;
    if(step<0)return;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            board[i][j]=returnboard[step][i][j];
        }
    }
    onScoreInt(returnscore[step]);
    update();
}
//键盘事件
void game::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Up)moveup();
    if(event->key()==Qt::Key_Down)movedown();
    if(event->key()==Qt::Key_Left)moveleft();
    if(event->key()==Qt::Key_Right)moveright();
}
//暂停音乐
void game::play(){
    player->pause();
}
//返回主界面
void game::return1(){
    step=0;
    initboard();
    player->pause();
    this->hide();

}
//初始化
void game::initboard(){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            board[i][j]=0;
        }
    }
    board[qrand()%4][qrand()%4]=2*(qrand()%2+1);
    i=qrand()%4;
    j=qrand()%4;
    while (board[i][j]!=0) {
        i=qrand()%4;
        j=qrand()%4;
    }
    board[i][j]=2*(qrand()%2+1);
    score=0;
    step=0;
    update();
}
//重新开始
void game::restart(){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            board[i][j]=0;
        }
    }
    initboard();
    step=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            returnboard[step][i][j]=board[i][j];
        }
    }
    returnscore[step]=0;
    step++;
    onScoreInt(returnscore[step-1]);
    update();
}
//存储个人信息
void game::restore(){
    record onename;
    int fflag=0;
    QFile fp("/Users/bin/rank");
    QString str;
    bool ok;
    fp.open( QIODevice::ReadOnly);
    QTextStream out(&fp);
    for(i=0;i<10;i++)
    {
       str=out.readLine();
       tenname[i].name=str;
       str=out.readLine();
       int d=str.toInt(&ok);
       tenname[i].score=d;
    }
    fp.close();
    //循环查找用户数组中是否有该用户
    for (i=0;i<10 ; i++)
    {
        if (tenname[i].name==name)
        {
            fflag=1;//查找到该用户
            if (tenname[i].score<=returnscore[step-1])
            {
                tenname[i].score=returnscore[step-1];
                for (j=0;j<10;j++)//冒泡排序所有人的排名
                {
                for (i=0;i<9;i++)
                {
                    if (tenname[i].score<tenname[i+1].score)
                    {
                       onename.name=tenname[i].name;
                       onename.score=tenname[i].score;
                       tenname[i].name=tenname[i+1].name;
                       tenname[i].score=tenname[i+1].score;
                       tenname[i+1].name=onename.name;
                       tenname[i+1].score=onename.score;
                    }
                }
                }
            }
        }
    }
    if(fflag==0)//排行榜中没有该用户的姓名，若该玩家分数足够将会被重新洗入排行榜
   {
    for(i=0;i<10;i++)
    {
     if (tenname[i].score<=returnscore[step-1])
     {
       for (j=9; j>=i+1; j--)
       {
         tenname[j].name=tenname[j-1].name;
         tenname[j].score=tenname[j-1].score;
       }
         tenname[i].name=name;
         tenname[i].score=returnscore[step-1];
         break;
     }
   }
 }
    QString num;
    fp.open( QIODevice::WriteOnly);
    QTextStream in(&fp);
    for(i=0;i<10;i++){
    num = QString::number(tenname[i].score,10);
    in<< tenname[i].name <<"\n"<<num<<"\n";
    }
    fp.close();

}

int game::moveup(){
    int i,j,k,l;
        int flag=0;
        returnscore[step]=0;
        if(step>0){
        returnscore[step]=returnscore[step]+returnscore[step-1];
        }
        for (j=0; j<=3; j++) {
            for (i=0; i<=3; i++) {
                if (board[i][j]!=0) {
                    for (l=i+1; l<=3; l++) {
                            if(board[l][j]!=0){  //除board[i][j]之外的第一个不为0的数字与其合并，并且推出该层循环，避免与之后不为0的数字与board[i][j]合并
                        if(board[l][j]==board[i][j]){
                        board[i][j]=board[i][j]+board[l][j];
                        board[l][j]=0;
                        returnscore[step]+=board[i][j];

                        flag=1;
                            }
                                break;
                        }
                    }
                }
            }
        }
        for (j=0; j<=3; j++) {
            for(k=0;k<=3;k++){   //冒泡排序使得非零数字前移（可优化）
                for (i=2; i>=0; i--) {
                    if (board[i][j]==0&&board[i+1][j]!=0) {
                        board[i][j]=board[i+1][j];  //非零数字与0交换位置
                        board[i+1][j]=0;
                        flag=1;
                    }
                }
            }
        }
        //在排序完成之后的表盘中寻找空位添加新随机数
        int i1=0,j1=0;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                if(board[i][j]==0)flag=1;
            }
        }
        i1=qrand()%4+0;
        j1=qrand()%4+0;
        if(flag==1){

        while(board[i1][j1]!=0){
            i1=qrand()%4+0;
            j1=qrand()%4+0;
        }
        board[i1][j1]=2*(qrand()%2+1);
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                returnboard[step][i][j]=board[i][j];
            }
        }
        step++;
        onScoreInt(returnscore[step-1]);
        }
        update();
        gameover();
        win();
        if(flag) return 1;
        else return -1;

}
int game::movedown(){
    int i,j,k,l;
        int flag=0;
        returnscore[step]=0;
        if(step>0){
        returnscore[step]=returnscore[step]+returnscore[step-1];
        }
        for (j=0; j<=3; j++) {
            for (i=3; i>=0; i--) {
                if (board[i][j]!=0) {
                    for(l=i-1;l>=0;l--){
                        if(board[l][j]!=0){   //除board[i][j]之外的第一个不为0的数字与其合并，并且推出该层循环，避免与之后不为0的数字与board[i][j]合并
                        if(board[l][j]==board[i][j]){
                        board[i][j]=board[i][j]+board[l][j];
                        board[l][j]=0;
                        returnscore[step]+=board[i][j];

                        flag=1;
                            }
                            break;//退出l循环
                        }
                    }
                }
            }
        }
        for (j=0; j<=3; j++) {
            for(k=0;k<=3;k++){   //循环使得非零数字前移（需要循环4次吗）
                for (i=3; i>=1; i--) {
                    if (board[i][j]==0&&board[i-1][j]!=0) {
                        board[i][j]=board[i-1][j];  //非零数字与0交换位置
                        board[i-1][j]=0;
                        flag=1;
                    }
                }
            }
        }
        //在排序完成之后的表盘中寻找空位添加新随机数
        int i1=0,j1=0;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                if(board[i][j]==0)flag=1;
            }
        }
        i1=qrand()%4+0;
        j1=qrand()%4+0;
        if(flag==1){

            while(board[i1][j1]!=0){
                i1=qrand()%4+0;
                j1=qrand()%4+0;
            }
            board[i1][j1]=2*(qrand()%2+1);

            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    returnboard[step][i][j]=board[i][j];
                }
            }
                    step++;
                    onScoreInt(returnscore[step-1]);
        }
        update();
        gameover();
        win();
        if(flag) return 1;
        else return -1;

}
int game::moveleft(){
    int i,j,k,l;
        int flag=0;
        returnscore[step]=0;
        if(step>0){
        returnscore[step]=returnscore[step]+returnscore[step-1];
        }
        for (i=0; i<=3; i++) {
            for (j=0; j<=3; j++) {
                if (board[i][j]!=0) {
                    for(l=j+1;l<=3;l++){
                        if(board[i][l]!=0){
                    if(board[i][j]==board[i][l]){
                    board[i][j]=board[i][j]+board[i][l];
                    board[i][l]=0;
                    returnscore[step]+=board[i][j];

                        flag=1;
                            }
                        break;
                        }
                    }
                }
            }
        }
        for (i=0; i<=3; i++) {
            for(k=0;k<=3;k++){   //循环使得非零数字前移（需要循环4次吗）
            for (j=2; j>=0; j--) {
                if (board[i][j]==0&&board[i][j+1]!=0) {
                    board[i][j]=board[i][j+1];  //非零数字与0交换位置
                    board[i][j+1]=0;
                    flag=1;
                }
            }
            }
        }
        //在排序完成之后的表盘中寻找空位添加新随机数
        int i1=0,j1=0;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                if(board[i][j]==0)flag=1;
            }
        }
        i1=qrand()%4+0;
        j1=qrand()%4+0;
        if(flag==1){

            while(board[i1][j1]!=0){
                i1=qrand()%4+0;
                j1=qrand()%4+0;
            }
            board[i1][j1]=2*(qrand()%2+1);

            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    returnboard[step][i][j]=board[i][j];
                }
            }
                    step++;
                    onScoreInt(returnscore[step-1]);
        }
        update();
        gameover();
        win();
        if(flag) return 1;
        else return -1;
}
int game::moveright(){
    int i,j,k,l;
        int flag=0;
        returnscore[step]=0;
        if(step>0){
        returnscore[step]=returnscore[step]+returnscore[step-1];
        }
        for (i=0; i<=3; i++) {
            for (j=3; j>=0; j--) {
                if (board[i][j]!=0) {
                    for(l=j-1;l>=0;l--){
                        if(board[i][l]!=0){
                    if(board[i][j]==board[i][l]){
                        board[i][j]=board[i][j]+board[i][l];
                        board[i][l]=0;
                        returnscore[step]+=board[i][j];

                        flag=1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        for (i=0; i<=3; i++) {
            for(k=0;k<=3;k++){   //循环使得非零数字前移（需要循环4次吗）
                for (j=3; j>=1; j--) {
                    if (board[i][j]==0&&board[i][j-1]!=0) {
                        board[i][j]=board[i][j-1];  //非零数字与0交换位置
                        board[i][j-1]=0;
                        flag=1;
                    }
                }
            }
        }
        //在排序完成之后的表盘中寻找空位添加新随机数
        int i1=0,j1=0;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                if(board[i][j]==0)flag=1;
            }
        }
        i1=qrand()%4+0;
        j1=qrand()%4+0;
        if(flag==1){

            while(board[i1][j1]!=0){
                i1=qrand()%4+0;
                j1=qrand()%4+0;
            }
            board[i1][j1]=2*(qrand()%2+1);

            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    returnboard[step][i][j]=board[i][j];
                }
            }
                    step++;
                    onScoreInt(returnscore[step-1]);
        }
        update();
        gameover();
        win();
        if(flag) return 1;
        else return -1;

}
void game::win(){
    int i,j;

        for (i=0;i<4; i++) {
            for (j=0; j<4; j++) {
                if(board[i][j]==2048)
                   { onWin();
                    return ;}
            }
        }
        return ;
}
void game::gameover( ){
    int i,j;
        for (i=0;i<3;i++)
            for (j=0;j<4;j++)
            if (board[i][j]==board[i+1][j]||board[i][j]==0||board[i+1][j]==0) return;//纵向检查是否有合并
        for (i=0;i<4;i++)
            for (j=0;j<3;j++)
            if (board[i][j]==board[i][j+1]||board[i][j]==0||board[i][j+1]==0) return;//横向检查是否有合并

        onGameOver();
        return;
}
//使用画刷构建游戏界面
void game::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    //反锯齿绘图，使得图片更加圆滑
    painter.setRenderHint(QPainter::Antialiasing);
    //设置画刷
    QBrush brush(QColor::fromRgb(141,121,81));
    painter.setBrush(Qt::SolidPattern);
    painter.setBrush(brush);
    //去除描边
    painter.setPen(Qt::NoPen);
    //绘制矩形
    painter.drawRoundRect(30,50,400,400,12,12);
    //设置窗格内字体
    QFont font2;
    font2.setFamily("Consolas");
    font2.setBold(true);
    font2.setPixelSize(40);
    painter.setFont(font2);

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(board[i][j]!=0){
                //取颜色数组中的颜色
                brush.setColor(digitBkg[int(qLn(board[i][j])/qLn(2))]);
                //
                painter.setBrush(brush);
                //
                painter.drawRoundRect(40+100*j,60+100*i,80,80,10,10);
                //设置描边颜色黑色
                painter.setPen(QColor::fromRgb(0,0,0));
                //绘制数字
                painter.drawText(40+100*j+2,60+100*i+2,80,80,Qt::AlignCenter,QString::number(board[i][j]));
                //
                painter.setPen(Qt::NoPen);
            }
            else{
                brush.setColor(QColor::fromRgb(171,165,141));
                painter.setBrush(brush);
                painter.drawRoundRect(40+100*j,60+100*i,80,80,10,10);
            }
        }
    }
}
    void game::onScoreInt(int score){
        scoreLbl->setText(QString("score:\n%1").arg(score));

    };

    void game::onGameOver()
    {
        restore();
        QMessageBox::information(this,"Gameover!",QString("You lost! "));

    }

    void game::onWin()
    {
        restore();
        QMessageBox::information(this, "Congratulation!", QString("You win !"));
    }






game::~game()
{
    delete ui;
    delete returnBtn;
    delete voice;
    delete scoreLbl;
    delete restartBtn;
    delete huiqi;
    delete player;
}


