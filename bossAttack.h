#ifndef BOSSATTACK
#define BOSSATTACK

class BossAttack
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