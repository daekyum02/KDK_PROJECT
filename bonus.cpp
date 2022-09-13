#include "bonus.h"

Bonus::Bonus(QWidget *parent) : QWidget(parent)
{
   randfood();
   randminus();
}
//보너스의 좌표값 랜덤으로 출력
void Bonus::randfood()
{
  srand((unsigned)time(NULL));
  food_x = (rand() % 24) * 25;
  food_y = (rand() % 24 )* 25;

}

void Bonus::randminus()
{
    //범위를 randfood와 같이 설정하면 겹치는 경우가 발생함으로 rand범위를 다르게 설정
    srand((unsigned)time(NULL));
    minus_x = (rand() % 23) * 25;
    minus_y = (rand() % 23 )* 25;
}
//보너스의 xy좌표값 반환
int Bonus::getfoodX()
{
  return food_x;
}

int Bonus::getfoodY()
{
  return food_y;
}

//minus의 xy좌표값 반환
int Bonus::getMinusX()
{
  return minus_x;
}

int Bonus::getMinusY()
{
  return minus_y;
}
