#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
    Player(double x, double y);
    double X();
    double Y();
    void PlayerDraw();
    void PlayerErase();
    void PlayerMove();
    void gotoxy(double, double);
private:
    double x;
    double y;
};

#endif 