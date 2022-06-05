#include"Player.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
#define KEY_UP    72 
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define BORDER_UP 2 
#define BORDER_DOWN 28
#define BORDER_LEFT 43  
#define BORDER_LEFT_WIDE 2  
#define BORDER_RIGHT 73 
#define BORDER_RIGHT_WIDE 115 
#define SPEED_PLAYER 1.1
using namespace std;

Player::Player(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Player::X()
{
    return x;
}
double Player::Y()
{
    return y;
}
void Player::PlayerDraw()
{
    gotoxy(x, y);
    cout << "凸";
}
void Player::PlayerErase()
{
    gotoxy(x, y);
    cout << "  ";
}
void Player::PlayerMove()
{
    if (kbhit())
    {
        PlayerErase();

        char key = getch();
        switch (key)
        {
        case KEY_LEFT:
            if (x - SPEED_PLAYER > BORDER_LEFT)
            {
                x -= SPEED_PLAYER;
                break;
            }
        case KEY_RIGHT:
            if (x + SPEED_PLAYER < BORDER_RIGHT)
            {
                x += SPEED_PLAYER;
                break;
            }
        case KEY_UP:
            if (y - SPEED_PLAYER > BORDER_UP)
            {
                y -= SPEED_PLAYER;
                break;
            }
        case KEY_DOWN:
            if (y + SPEED_PLAYER < BORDER_DOWN)
            {
                y += SPEED_PLAYER;
                break;
            }
        }
    }
    PlayerDraw();
}
void gotoxy(double x, double y) 
{   
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; // start from 0
    dwPos.Y = y; // start from 0
    SetConsoleCursorPosition(hCon, dwPos);
}
