#ifndef ENEMY_H
#define ENEMY_H
class Enemy
{
public:
    Enemy(double x, double y);
    double X();
    double Y();
    void EnemyDraw();
    void EnemyErase();
    void EnemyMove();
    bool EnemyisOut();
    static void setGameMode(bool level);
private:
    double x;
    double y;
    static bool gameMode;
};

#endif
