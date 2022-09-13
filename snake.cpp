#include "snake.h"

//스네이크의 초기 상태
Snake::Snake(QWidget *parent) : QWidget(parent)
{
  Snakecoor snakenode;
  for (int i = 5; i >= 0; i--)
  {
      snakenode.x = 25 * 8 + i * 25;
      snakenode.y = 25 * 8;
      snakevec.push_back(snakenode);
  }
}
//방향키로 뱀의 이동 설정
inline void Snake::snakemove(char key, Snakecoor &nexthead)
{
  switch (key)
  {
  case 'w':
      nexthead.x = snakevec.front().x;
      nexthead.y = snakevec.front().y - 25;
      break;
  case 's':
      nexthead.x = snakevec.front().x;
      nexthead.y = snakevec.front().y + 25;
      break;
  case 'a':
      nexthead.x = snakevec.front().x - 25;
      nexthead.y = snakevec.front().y;
      break;
  case 'd':
      nexthead.x = snakevec.front().x + 25;
      nexthead.y = snakevec.front().y;
  }
}
//입력한 키에따라 움직인다
void Snake::Move(char key)
{
  Snakecoor nexthead;
  snakemove(key, nexthead);
  snakevec.insert(snakevec.begin(), nexthead);
}
//스네이크 길이 초기화와 게임의 초기화
void Snake::Reset()
{
  snakevec.clear();

  Snakecoor snakenode;
  for (int i = 5; i >= 0; i--)
  {
      snakenode.x = 25 * 8 + i * 25;
      snakenode.y = 25 * 8;
      snakevec.push_back(snakenode);
  }
}
