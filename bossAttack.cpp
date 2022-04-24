#include <iostream>
#include "bossAttack.h"
using namespace std;

void::BossAttack() {
	int attackPoint = 2;
}
void BossAttack::printBossAttack() {
	gotoxy(x, y); cout << "AAA";
	gotoxy(x, y + 1); cout << " A ";
}
void BossAttack::eraseBossAttack() {
	gotoxy(x, y); cout << "  ";
	gotoxy(x, y + 1); cout << "  ";
}
int BossAttack::BossAttackTouch() {

}