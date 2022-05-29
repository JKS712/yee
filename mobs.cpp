#include "mobs.h"
#include <conio.h>
#include <iostream>
using namespace std;
#define BORDER_DOWN 28

Mobs::Mobs() {

}
bool Mobs::mobsGoOut() {
	if (y > BORDER_DOWN)
		return true;
	else
		return false;
}
int Mobs::mobsSummon() {
	srand(time(NULL));
	
	cout << "x = " << endl;
}

double Mobs::X() {
	return x; 
}
double Mobs::Y() {
	return y; 
}
void Mobs::mobsPrint() {
	gotoxy(x, y); 
	cout << "59";
}
void Mobs::erase() {
	gotoxy(x, y); 
	cout << "  ";
}
void Mobs::Move()
{
    Erase();
    mobsPrint(); 
}
