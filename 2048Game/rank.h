#ifndef RANK_H
#define RANK_H
#include"qstring.h"
#include <QDialog>

namespace Ui {
class Rank;
}
#define LBLSTYLESHEET "QLabel {color: orange;background: #FFFFCC;border: %1px solid orange;border-radius: %2px;}"
class Rank : public QDialog
{
    Q_OBJECT

public:
    explicit Rank(QWidget *parent = 0);
    ~Rank();

private:
    Ui::Rank *ui;
};

#endif // RANK_H
