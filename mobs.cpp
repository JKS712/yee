#include "mobs.h"
#include <conio.h>
#include <iostream>
#include "main.cpp"
using namespace std;
#define BORDER_DOWN 28

Mobs::Mobs() {
	this->x = x;
	this->y = y;
}
bool Mobs::mobsGoOut() {
	if (y > BORDER_DOWN)
		return true;
	else
		return false;
}
double Mobs::X() {
	return x;
}
double Mobs::Y() {
	return y;
}
void Mobs::mobsPrint() {
	gotoxy(x, y);
	cout << "XX";
}
void Mobs::erase() {
	gotoxy(x, y);
	cout << "  ";
}
void Mobs::move()
{
	erase();
	mobsPrint();
}
