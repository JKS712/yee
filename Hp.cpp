#include "HP.h"
#include <iostream>

Hp::Hp(int newheart) {
	newheart = 6;
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

}
