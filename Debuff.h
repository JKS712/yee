#ifndef DEBUFF_H
#define DEBUFF_H
#include "Player.h"
#include "Coordinate.h"
class Debuff
{
public:
	int getReduceSize();
	int getReduceAttackSpeed();
	int getReduceDamage();
	void setReduceAttackSpeed();
	void setReduceDamage();
	void setReduceSize();
	void printSizeDebuff();
	void printAttackSpeedDebuff();
	void printDamageDebuff();
	Coordinate(double x, double y) { this->x = x; this->y = y; };
	double X() { return x; }
	double Y() { return y; } 
	void Erase();
	void playerTouch();

private:
	double x; // x coordinate
	double y; // y coordinate 
	bool touch;
};

#endif // !DEBUFF_H
