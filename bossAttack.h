#ifndef BOSSATTACK
#define BOSSATTACK

class bossAttack
{
public:
	BossAttack();
	void printBossAttack();
	void eraseBossAttack();
	int BossAttackTouch();
	double X() { return x; }
	double Y() { return y; }

private:
	int x;
	int y;
};

#endif // !BOSSATTACK
