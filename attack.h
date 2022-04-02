#ifndef ATTACK_H
#define ATTACK_H

class attack{
public:
	int getSize();
	void setSize(int,int);
	int getDamage();
	void setDamage(int);
	int getAttackSpeed();
	void setAttackSpeed(int);
private:
	int Damage;
};

#endif