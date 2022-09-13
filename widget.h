#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "snake.h"
#include <QKeyEvent>
#include "bonus.h"
#include <QTimer>

namespace Ui
{
class Widget;
}
class Widget : public QWidget
{
  Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void GameOver();
    void keyPressEvent(QKeyEvent *ev);
    Ui::Widget *ui;
    Snake snake;
    char key = 'd';
    Bonus food;
    QTimer *timer = new QTimer(this);

    int score = 0;
    int timerspeed = 200;
    bool bugflag = false;
    bool gameflag = false;
    bool gamewin = false;
    int timercount=0;
    int clicktime=1;
    int Target_score=10;
private slots:
    void on_lineEdit_returnPressed();

    void on_startbot_2_clicked();

    void on_help_clicked();

private:
};
#endif // WIDGET_H
