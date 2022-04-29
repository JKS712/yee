
#include<iostream>
#include"enemyHP.h"
using namespace std;


enemyHP::enemyHP() {
	int enemyHP = 4;
}
int enemyHP::getHurt() {

}
void enemyHP::setHurt(int newHurt) {
	int hurt = newHurt;
}
int enemyHP::getEnemyHP() {
	return enemyHp - hurt;
}
void enemyHP::setEnemyHP(int newEnemyHp) {
	int enemyHp = newEnemyHp;
}


