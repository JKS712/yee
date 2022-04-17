#include <iostream>
#include "Debuff.h"
#include "HP.h"
#include "Player.h"
#include "Coordinate.h"
#include "Attack.h"
using namespace std;

int Debuff::getReduceAttackSpeed() {
    return Attackspeed - 1;
}
int Debuff::getReduceDamage() {
    return Damage - 1;
}
int Debuff::getReduceSize(){
    return Size - 1;
}
int Debuff::setReduceAttackSpeed() {

}
int Debuff::setReduceDamage() {
    
}
int Debuff::setReduceSize() {
    
}
void Debuff::printSizeDebuff()
{
    gotoxy(x, y); cout << "SS"; //  while (y - 1) means a row above y
    gotoxy(x, y + 1); cout << "::"; // (y + 1) means a row below y
}
void Debuff::printAttackSpeedDebuff()
{
    gotoxy(x, y); cout << "AA"; //  while (y - 1) means a row above y
    gotoxy(x, y + 1); cout << "::"; // (y + 1) means a row below y
}
void Debuff::printDamageDebuff()
{
    gotoxy(x, y); cout << "DD"; //  while (y - 1) means a row above y
    gotoxy(x, y + 1); cout << "::"; // (y + 1) means a row below y
}
void Pass::Erase()
{
    gotoxy(x, y); cout << "  ";
    gotoxy(x, y + 1); cout << "  ";
}
void Debuff::Erase()
{
    gotoxy(x, y); cout << "  ";
}
void Debuff::playerTouch() {
    
}