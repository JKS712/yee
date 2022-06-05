#ifndef ATTACK_H
#define ATTACK_H
class Attack
{
public:
    Attack(double x, double y);
    double X();
    double Y();
    void AttackDraw();
    void AttackErase();
    void AttackMove();
    bool AttackisOut();
private:
    int x;
    int y; 
};
#endif

