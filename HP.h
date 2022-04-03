#ifndef HP_H
#define HP_H

class Hp
{
public:
	Hp(int);
	int getHurt();
	int getHeart();
	void setHeart(int);
	void setHurt(int);
	void print();
private:
	int heart;
	int hurt;
};
#endif // !HP_H
