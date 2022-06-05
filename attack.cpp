#include"Attack.h"
#include<iostream>
#include<Windows.h>
#define SPEED_ATTACK 0.5
#define BORDER_UP 2
using namespace std;

Attack::Attack(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Attack::X()
{
    return x;
}
double Attack::Y()
{
    return y;
}
void Attack::AttackDraw()
{
    gotoxy(x, y); cout << "l"; //  while (y - 1) means a row above y

}

void Attack::AttackErase()
{
    gotoxy(x, y); cout << "  ";
}

void Attack::AttackMove()
{
    AttackErase();
    y -= SPEED_ATTACK; // move a SPEED_PASS unit upward
    AttackDraw();
}

bool Attack::AttackisOut()
{
    if (y < BORDER_UP)
        return true;
    else
        return false;
}

void gotoxy(double x, double y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; // start from 0
    dwPos.Y = y; // start from 0
    SetConsoleCursorPosition(hCon, dwPos);
}
