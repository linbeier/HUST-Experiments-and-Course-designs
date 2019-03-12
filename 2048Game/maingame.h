#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>

class maingame : public QWidget
{
    Q_OBJECT
public:
    explicit maingame(QWidget *parent = nullptr);

signals:
    void scoreInc(int);
    void GameOver();
    void win();
public slots:
    void restart();
};

#endif // MAINGAME_H
