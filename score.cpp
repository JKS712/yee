#include<iostream>
#include"score.h"
using namespace std;

score::score(){

}
void score::setScore(int newScore){
	int score = newScore;
}
void score::printScore(){
	gotoxy(x, y); cout << "Score: "<< score ;

}
void score::eraseScore(){
	gotoxy(x, y); cout << "Score: "<< " " ;
}