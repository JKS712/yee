#include "Player.h"
#include <conio.h>
#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define BORDER_UP 2
#define BORDER_DOWN 28
#define BORDER_LEFT 43 
#define BORDER_RIGHT 73
#define SPEED_PLAYER 1.1

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
void Player::Draw()
{
    gotoxy(x, y); 
    cout << "凸";
}
void Player::Erase()
{
    gotoxy(x, y);
    cout << "  ";
}
void Player::printAttack() {
    gotoxy(x, y); cout << "KKK";
    gotoxy(x, y + 1); cout << " K ";
}
void Player::eraseAttack() {
    gotoxy(x, y); cout << "  ";
    gotoxy(x, y + 1); cout << "  ";
}
void Player::Move()
{
    if(kbhit())
    {
        Erase();
        
        char key = getch();
        switch(key)
        {
            case KEY_LEFT: 
                if(x - SPEED_PLAYER > BORDER_LEFT)
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
    Draw();
}
