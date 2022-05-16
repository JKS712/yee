#ifndef ENEMY
#define ENEMY

class Enemy
{
public:
  Enemy(double x,double y);
  double getX();
  double getY();
  void Draw(); 
  void Erase(); 
  void Move(); 
  bool isOut();
private:
  double x;
  double y;
};
