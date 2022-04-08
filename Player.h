#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    double x;
    double y;
public:
    Player(double x, double y);
    double X();
    double Y();
    void Draw();
    void Erase();
    void Move();
};

#endif
