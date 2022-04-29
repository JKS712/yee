#ifndef ATTACK_H
#define ATTACK_H

class attack{
public:
	arrack(int);
	int getSize();
	void setSize(int,int);
	int getDamage();
	void setDamage(int);
	int getAttackSpeed();
	void setAttackSpeed(int);
	void printAttack();
	void eraseAttack();
private:
	int Damage;
	double x;
	double y;
};

#endif
