#include <Player.h>

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
    cout << "船";
}
void Player::Erase()
{
    gotoxy(x, y);
    cout << "  ";
}
void Player::Move()
{

}
