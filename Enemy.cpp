include"Enemy.h"
include "main.cpp"
 
Enemy::Enemy(double x, double y) 
{ 
  this->x = x; this->y = y;
}
double Enemy::getX()
{
  return x;
} 
double Enemy::getY()
{ 
  return y; 
}
void Enemy::Draw()
{
    gotoxy(x, y); cout << "59"; 
}
void Enemy::Erase()
{
    gotoxy(x, y); cout << "  ";  
}
void Enemy::Move()
{
    Erase();
    y += SPEED_Enemy;
    Draw(); 
}
bool Enemy::isOut()
{
    if (y > BORDER_DOWN)
        return true;
    else
        return false;
}
