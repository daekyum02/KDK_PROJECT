#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui창 크기 고정
    setFixedSize(1000,600);
    //각 label에 필요한 내용 출력
    ui->label->setFont(QFont("Sitka Heading Semibold", 20, QFont::Bold, false));
    ui->label_2->setFont(QFont("Sitka Heading Semibold", 24, QFont::Bold, false));
    ui->label_2->setText("SPEED : ");
    //슬라이드바의 초기상태 설정
    //200이 슬라이드바의 중간
    ui->horizontalSlider->setValue(200 >> 2);

    //속도 조절 바
    //조절된 바의 value값에 따라 속도값(level) 설정
    connect(ui->horizontalSlider,QSlider::valueChanged,[=]()
    {
        //timerspeed는 timer의 진행 주비
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
            //minus food
            if(food.getMinusX() == snake.snakevec.at(0).x && food.getMinusY() == snake.snakevec.at(0).y)
            {
                timercount=0;
                score--;
                snake.snakevec.pop_back();
                food.randminus();
                //버그 예외처리
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
            //timercount의 값이100이 될 때 마다 0으로 초기화 및 minus food의 위치를 랜덤으로 위치시킨다
            if(timercount==100)
            {
                food.randminus();
                timercount=0;
            }
            //타겟 스코어의 값이 획득한 스코어의 값과 같으면 gamewin을 true로 전환, 그리고 타이머의 진행을 멈춘다
            if(score==Target_score)
            {
                //gamewin변수 bool형
               gamewin = true,
               timer->stop();
            }
            //스코어의 값이 0보다 작으면 gamefalg를  true로 전환, 그리고 타이머의 진행을 멈춘다
            if(score<0)
            {
                //gameover변수 bool형
                gameflag = true;
                timer->stop();
            }
        });
    });
    //초기 score ui label에 출력
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
      {
          gameflag = true, timer->stop();
      }
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
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setBrush(minus);
  painter.drawEllipse(QRect(food.getMinusX(),food.getMinusY(),25,25));
  //스네이크 몸출력
  QBrush brush2(Qt::blue);
  painter.setBrush(brush2);
  //auto타입을 사용하여 뒤에있는 snake.snakevec의 형식과 같게 만든다
  for(auto snakenodei : snake.snakevec)
      //삼항연산자를 통해 할당된 데이터 값을 기반으로 스네이크의 길이를 출력한다
      (snakenodei.x == snake.snakevec.at(0).x && snakenodei.y == snake.snakevec.at(0).y) ?
       painter.setRenderHint(QPainter::Antialiasing), painter.drawEllipse(QPoint(snakenodei.x + 12,snakenodei.y + 12),12,12):
       painter.drawRect(QRect(snakenodei.x,snakenodei.y,25,25));
  bugflag = false;
  //벽출력
  QBrush brush3(QColor(128, 125, 0));
  painter.setBrush(brush3);
  for(int i = 0; i < 24; i++)
        painter.drawRect(QRect(25 * 25, i * 25, 25, 25));

  //game에 패배하게되면 game over문구 출력
  if(gameflag)
  {
      QFont font("Sitka Heading Semibold", 80, QFont::Bold, false);
      painter.setFont(font);
      painter.drawText(QRect(240, 200, 1000, 500), "Game Over\n");
      QFont font1("Sitka Heading Semibold", 25, QFont::Bold, false);
      painter.setFont(font1);
      painter.drawText(QRect(240, 300, 500, 500),"User name : ");
      painter.drawText(QRect(450, 300, 500, 500),usernameoutput);
//      ui->namelabel->setText(usernameoutput);


  }
  //game에 승리하면 gamewin이라는 문구 출력
  if(gamewin)
  {
      QFont font("Sitka Heading Semibold", 80, QFont::Bold, false);
      painter.setFont(font);
      painter.drawText(QRect(240, 200, 1000, 500), "You Win");
  }
}
//키보드 입력값 받아서 스네아크 이동시키기
void Widget::keyPressEvent(QKeyEvent *ev)
{
  if(bugflag)
      return;
  //ev-->event약자
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
//타겟스코어 값을 line_edit을 통해 입력받는다
void Widget::on_lineEdit_returnPressed()
{
       Target_score=ui->lineEdit->text().toInt();
}
//help버튼을 클릭하면 도움말 출력창 띄우기
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

void Widget::on_name_returnPressed()
{
    std::string username=ui->name->text().toStdString();
    usernameinput=&username[0];
    qDebug()<<usernameinput;
    for(int i = 0; usernameinput[i]!='\0'; i++)
    {
        usernameoutput[i] = usernameinput[i];
    }
}

