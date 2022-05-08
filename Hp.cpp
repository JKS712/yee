#include "HP.h"
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime> 
#include <chrono> 
#include <list> 
#include <conio.h> 
#include <windows.h> 
using namespace std;

Hp::Hp(int newheart) {
	setHeart(6);
}
int Hp::getHurt(){
	return hurt;
}
int Hp::getHeart() {
	return heart - hurt;
}
void Hp::setHeart(int newHeart) {
	heart = newHeart;
}
void Hp::setHurt(int newHurt) {
	hurt = newHurt;
}
void Hp::print() {
	for (int i = 0;i < heart;i++) {
		cout << "<3" << endl;
	}
}
int getHurt() {

}
