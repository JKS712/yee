#ifndef MOBS_H
#define MOBS_H

class Mobs
{
public:
	Mobs();
	bool mobsGoOut();
	int mobsSummon();
	double X() { return x; }
	double Y() { return y; }
	void mobsPrint();
	void erase(); 


private:
	double x;
	double y;
};

#endif // !SUMMON_H
