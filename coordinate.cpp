#include "coordinate.h"
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime> 
#include <chrono> 
#include <list> 
#include <conio.h> //  input from keyboard to terminal
#include <windows.h> // control terminal

void Coordinate::gotoxy() {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; // start from 0
    dwPos.Y = y; // start from 0
    SetConsoleCursorPosition(hCon, dwPos);
}