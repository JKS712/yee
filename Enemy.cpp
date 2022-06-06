#include"Enemy.h"
#include<iostream>
#include<windows.h>

#define BORDER_DOWN 28
#define SPEED_ENEMY_EASY 0.1 
#define SPEED_ENEMY_HARD 0.5
#define SPEED_SUPER_HARD 1.0
using namespace std;

Enemy::Enemy(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Enemy::X()
{
    return x;
}
double Enemy::Y()
{
    return y;
}
void Enemy::EnemyDraw()
{
    gotoxy(x, y); 
    cout << "¤f";
}
void Enemy::EnemyErase()
{
    gotoxy(x, y); 
    cout << "  ";
}
void Enemy::EnemyMove()
{
    EnemyErase();

    if (gameMode == 2)
        y += SPEED_SUPER_HARD;
    else if (gameMode == 1)
        y += SPEED_ENEMY_EASY;
    else if (gameMode == 0)
        y += SPEED_ENEMY_HARD;
    

    EnemyDraw();
}
bool Enemy::EnemyisOut()
{
    if (y > BORDER_DOWN)
        return true;
    else
        return false;
}
int Enemy::gameMode = 1;

void Enemy::setGameMode(int level)
{
    gameMode = level;
}

int Enemy::getGameMode()
{
    return gameMode;
}
void Enemy::gotoxy(double x, double y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; 
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}