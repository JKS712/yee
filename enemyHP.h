#ifndef ENEMYHP_H
#define ENEMYHP_H

class enemyHP{
public:
	enemyHP(int);
	int getHurt();
	void setHurt(int);
	int getEnemyHP();
	void setEnemyHP(int);
private:
	int hurt;
	int enemyHP;
};

#endif
