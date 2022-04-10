#include<iostream>
#include"attack.h"
	


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

