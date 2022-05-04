#include<iostream>
#include"bossHP.h"
using namespace std;	

bossHP::bossHP(){
	int bossHP = 20;
}	
int getBossHurt(){
	return bossHP - hurt;
}
void setBossHP(int newBossHP){
	int bossHP = newBossHP;
}
void printBossHP(){
	gotoxy(x, y); cout << bossHP;
}
void eraseBossHP(){
	gotoxy(x, y); cout << "   ";
}
