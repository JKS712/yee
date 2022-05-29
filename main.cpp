#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime> 
#include <chrono> 
#include <list> 
#include <conio.h> 
#include <windows.h> 

#include "Attack.h"
#include "bossAttack.h"
#include "Debuff.h"
#include "HP.h"
#include "Player.h"
using namespace std;

void gotoxy(double x ,double y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; 
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void DrawWhiteSpace(int x1, int y1, int x2, int y2) 
{
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++){        
            gotoxy(i, j);
            cout << " ";
        }
    }
}
bool Start()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);


    srand(time(nullptr)); 
    int mapWidth = BORDER_RIGHT - BORDER_LEFT + 1; 
    int mapLength = BORDER_DOWN - BORDER_UP + 1; 
    double rnX = 0;
    double rnY = 0; 
    for (int i = 0; i < 10; i++) 
    {
        rnX = (rand() % mapWidth) + BORDER_LEFT;
        rnY = (rand() % (mapLength / 2)) + (BORDER_UP); 
        scores.push_back(Mobs(nX, nY));
    }

    while (duration < timeLimit) 
    {
        for (p = passes.begin(); p != passes.end(); p++) 
        {
            p->Move(); 
            if (p->isOut())
            {
                p->Erase(); 
                p = passes.erase(p); 
            }
        }
}
//Start未做完    
bool Collision(double x1, double y1, double x2, double y2) {
    if (abs(x1 - x2) < EQUALITY_GAP_X)   
    {
        if (abs(y1 - y2) < EQUALITY_GAP_Y)
            return true;
        else
            return false;
    }

    return false;
}

void Initialize() {
    SetConsoleTitle("¥´­¸¾÷");

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

int main() {
    Initialize();
}
