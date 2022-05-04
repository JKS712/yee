#ifndef BOSSHP_H
#define BOSSHP_H

class boss_HP{
public:
	bossHP(int);	
	int getBossHurt();
	void setBossHP(int);
	void printBossHP();
	void eraseBossHP();
	double X();
	double Y();

private:
	int HP;
	double X;
	double Y;

};

#endif