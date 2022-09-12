#ifndef BONUS_H
#define BONUS_H

#include <QWidget>

class Bonus: public QWidget
{
public:
    int food_x = 0;
    int food_y = 0;
    int minus_x = 100;
    int minus_y = 100;
    explicit Bonus(QWidget *parent = nullptr);

    void randfood();
    int getfoodX();
    int getfoodY();
    void randminus();
    int getMinusX();
    int getMinusY();

    signals:

    public slots:
};

#endif // BONUS_H
