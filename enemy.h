#ifndef ENEMY_H
#define ENEMY_H

class enemy{
public:
	int getSize();
	void setSize(int,int);
	int getHurt();
	void setHurt(int);
	int getEnemyHP();
	void setEnemyHP(int);
private:
	int hurt;
	int enemyHP;
};

#endif