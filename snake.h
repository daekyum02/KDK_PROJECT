#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QVector>

class Snake : public QWidget
{
  Q_OBJECT
private:

  struct  Snakecoor
  {
      int x;
      int y;
  };

public:
  explicit Snake(QWidget *parent = nullptr);

  QVector<Snakecoor> snakevec;

  void Move(char key);

  void snakemove(char key, Snakecoor &nexthead);

  void Reset();

signals:

public slots:
};

#endif // SNAKE_H
