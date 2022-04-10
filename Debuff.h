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
	void printSizeDebuff();
	void printAttackSpeedDebuff();
	void printDamageDebuff();

	Coordinate(double x, double y) { this->x = x; this->y = y; };
	double X() { return x; }
	double Y() { return y; } 
	void Erase();

private:
	int x; // x coordinate
	int y; // y coordinate 
};

#endif // !DEBUFF_H
