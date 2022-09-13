#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(1000,600);

    ui->label->setFont(QFont("Sitka Heading Semibold", 20, QFont::Bold, false));
    ui->label_2->setFont(QFont("Sitka Heading Semibold", 24, QFont::Bold, false));
    ui->label_2->setText("SPEED : ");
    ui->horizontalSlider->setValue(200 >> 2);

    //속도 조절 바
    connect(ui->horizontalSlider,QSlider::valueChanged,[=]()
    {
        timerspeed = ui->horizontalSlider->value() << 2;

        if(timerspeed>=40&&timerspeed<=100)
        {
            ui->label_3->setFont(QFont("Sitka Heading Semibold",16));
            ui->label_3->setText("Level_3");
        }
        else if(timerspeed>100&&timerspeed<=200)
        {
            ui->label_3->setFont(QFont("Sitka Heading Semibold",16));
            ui->label_3->setText("Level_2");
        }
        else if(timerspeed>200&&timerspeed<=300)
        {
            ui->label_3->setFont(QFont("Sitka Heading Semibold",16));
            ui->label_3->setText("Level_1");
        }
        else
        {
            ui->label_3->setFont(QFont("Sitka Heading Semibold",16));
            ui->label_3->setText("Beginner mode");
        }
    });

    ui->resetbot->setFont(QFont("Sitka Heading Semibold",25));
    ui->resetbot->setText("RESTART");

    ui->startbot->setFont(QFont("Sitka Heading Semibold",25));
    ui->startbot->setText("START");

    ui->help->setFont(QFont("Sitka Heading Semibold",25));
    ui->help->setText("HELP");
    //reset
    connect(ui->resetbot,QPushButton::clicked,[=]()
    {
        clicktime=0;
        snake.Reset();
        timercount=0;
        score = 0;
        key = 'd';
        timerspeed = 200 << 2;
        timer->start(timerspeed);
        ui->horizontalSlider->setValue(200 >> 2);
        gameflag= false;
        gamewin = false;
    });

    //start
    connect(ui->startbot,QPushButton::clicked,[=]()
    {
        clicktime=0;
        timer->start(timerspeed);
        connect(timer,&QTimer::timeout,[=]()
        {
            //버그 예외처리
            if(food.getMinusX() == snake.snakevec.at(0).x && food.getMinusY() == snake.snakevec.at(0).y)
            {
                timercount=0;
                score--;
                snake.snakevec.pop_back();
                food.randminus();
                if((food.getfoodX()==food.getMinusX())&&(food.getfoodY()==food.getMinusY()))
                {
                food.randfood();
                }
            }
            //게임 시작 모드
            if(clicktime==0)
            {
            timercount++;
            ui->countnumber->setFont(QFont("Artifakt Element Black",16));
            ui->countnumber->setNum(timercount);
            timer->start(timerspeed);
            snake.Move(key);
            (food.getfoodX() == snake.snakevec.at(0).x && food.getfoodY() == snake.snakevec.at(0).y) ? score++, food.randfood(): snake.snakevec.pop_back();
            GameOver();
            update();
            ui->label->setText(QString("SCORE : %1").arg(score));
            }
            //timercount
            if(timercount==100)
            {
                food.randminus();
                timercount=0;
            }
            if(score==Target_score)
            {
               gamewin = true,
               timer->stop();
            }
            if(score<0)
            {
                gameflag = true;
                timer->stop();
            }
        });
    });
   ui->label->setText(QString("SCORE : %1").arg(score));
}

void Widget::GameOver()
{
    //벽에 닿았을 때
  if(snake.snakevec.at(0).x >= 24 * 25 || snake.snakevec.at(0).x < 0 || snake.snakevec.at(0).y < 0 || snake.snakevec.at(0).y >= 24 * 25)
  {
      gameflag = true;
      timer->stop();
      return;
  }
  //스네이크가 스스로 몸에 닿았을 때
  for(int i = 1; i < snake.snakevec.size(); i++)
  {
      if(snake.snakevec.at(0).x == snake.snakevec.at(i).x && snake.snakevec.at(0).y == snake.snakevec.at(i).y)
          gameflag = true, timer->stop();
  }
}
void Widget::paintEvent(QPaintEvent *)
{
  //bonus 출력
  QPainter painter(this);

  QBrush brush1(Qt::red);

  painter.setBrush(brush1);

  painter.drawRect(QRect(food.getfoodX(),food.getfoodY(),25,25));
  //minus bonus 출력
  QBrush minus(Qt::green);

  painter.setBrush(minus);

  painter.drawEllipse(QRect(food.getMinusX(),food.getMinusY(),25,25));
  //스네이크 몸출력
  QBrush brush2(Qt::blue);
  painter.setBrush(brush2);
  for(auto snakenodei : snake.snakevec)

      (snakenodei.x == snake.snakevec.at(0).x && snakenodei.y == snake.snakevec.at(0).y) ?

      painter.setRenderHint(QPainter::Antialiasing), painter.drawEllipse(QPoint(snakenodei.x + 12,snakenodei.y + 12),12,12):

      painter.drawRect(QRect(snakenodei.x,snakenodei.y,25,25));

  bugflag = false;
  //벽출력
  QBrush brush3(QColor(128, 125, 0));
  painter.setBrush(brush3);

  for(int i = 0; i < 24; i++)
        painter.drawRect(QRect(25 * 25, i * 25, 25, 25));

  //game이 종료되면 game over문구 출력
  if(gameflag)
  {
      QFont font("Sitka Heading Semibold", 80, QFont::Bold, false);
      painter.setFont(font);
      painter.drawText(QRect(240, 200, 1000, 500), "Game Over");
  }
  if(gamewin)
  {
      QFont font("Sitka Heading Semibold", 80, QFont::Bold, false);
      painter.setFont(font);
      painter.drawText(QRect(240, 200, 1000, 500), "You Win");
  }
}

void Widget::keyPressEvent(QKeyEvent *ev)
{
  if(bugflag)
      return;

  switch (ev->key())
  {
  case Qt::Key_W:
      if(key == 's') break;
      key = 'w';
      bugflag = true; break;
  case Qt::Key_S:
      if(key == 'w') break;
      key = 's';
      bugflag = true; break;
  case Qt::Key_A:
      if(key == 'd') break;
      key = 'a';
      bugflag = true; break;
  case Qt::Key_D:
      if(key == 'a') break;
      key = 'd';
      bugflag = true; break;
  default:
      timer->start(timerspeed);
  }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_returnPressed()
{
       Target_score=ui->lineEdit->text().toInt();
}

void Widget::on_help_clicked()
{
    QLabel*help=new QLabel();
    help->setFont(QFont("맑은 고딕",15));
    help->setText("                                                          < 도움말 >\n\n"
                  " 1. 뱀의 이동은 w-s-a-d 키로 조종을 하면 됩니다. \n"
                  "\n 2. start버튼을 누르면 게임이 시작됩니다. 게임이 종료되면 restart버튼을 통해 재시작을 할 수 있습니다.\n"
                  "\n 3. 게임이 종료되는 조건 : \n"
                  "   Ⅰ. 목표점수를 달성해 승리. \n"
                  "   Ⅱ. 벽 혹은 뱀의 몸을 부딪히면 패배.\n"
                  "   Ⅲ. 스코어가 0보다 작으면 패배.\n"
                  "\n 4. 빨간색 먹이은 보너스입니다, 먹으면 뱀의 길이가 길어져요.\n"
                  "\n 5. 초록색 먹이는 마이너스 먹이 입니다, 일전 시간이 지나면 위치를 바꾸게 됩니다.\n"
                  "    또한, 마이너스 먹이의 특성상 스코어와 뱀의 길이를 줄여줍니다, 하지만 상황에 \n    맞게 사용하는게 좋을 것입니다.\n"
                  "\n 6. 유저가 목표점수를 입력하기 전에는 목표점수의 초기값은 10 입니다.\n"
                  "\n 7. 속도는 총4단계로 이루어 집니다, level3 ,level2, level1 그리고 Beginner mode가 있습니다.\n\n"
                  "\n\n\n\n");
    help->show();
}

