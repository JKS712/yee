#include"Enemy.h"
#include<iostream>
#include<windows.h>
#define BORDER_DOWN 28
#define SPEED_ENEMY_EASY 0.1 
#define SPEED_ENEMY_HARD 0.5
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
    gotoxy(x, y); cout << "口";
}
void Enemy::EnemyErase()
{
    gotoxy(x, y); cout << "  ";
}
void Enemy::EnemyMove()
{
    EnemyErase();

    if (gameMode == 1)
        y += SPEED_ENEMY_EASY; // move a SPEED_SCORE59 unit downward
    else
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
bool Enemy::gameMode = 1; // the user play the game in easy mode by default

void Enemy::setGameMode(bool level)
{
    gameMode = level;
}

void gotoxy(double x, double y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; // start from 0
    dwPos.Y = y; // start from 0
    SetConsoleCursorPosition(hCon, dwPos);
}
