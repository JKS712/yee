#include<iostream>
#include"attack.h"
	
attack::attack(){
	int attack = 1;
}

int attack::getSize(){
	return size;
}
void attack::setSize(int width,int height){
	size= width*height;
}
int attack::getDamage(){
	return damage;
}
void attack::setDamage(int newDamage){
	damage= newDamage;
}
int attack::getAttackSpeed(){
	return attackSpeed;
}
void attack::setAttackSpeed(int newAttackSpeed){
	attackSpeed=newAttackSpeed;
}

void attack::printAttack() {
	gotoxy(x, y); cout << "KKK";
	gotoxy(x, y + 1); cout << " K ";
}
void attack::eraseAttack() {
	gotoxy(x, y); cout << "  ";
	gotoxy(x, y + 1); cout << "  ";
}
