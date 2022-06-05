#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>
#include <chrono> 
#include <list>
#include <conio.h> 
#include <windows.h> 
using namespace std;

#define KEY_UP    72 
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define BORDER_UP 2 
#define BORDER_DOWN 28
#define BORDER_LEFT 43  
#define BORDER_LEFT_WIDE 2  
#define BORDER_RIGHT 73 
#define BORDER_RIGHT_WIDE 115 
#define STUDENT_INITIAL_X 58.5 
#define STUDENT_INITIAL_Y 25
#define EQUALITY_GAP_X 1.5 
#define EQUALITY_GAP_Y 1
#define CUR_SCORE_POS_X 50 
#define CUR_SCORE_POS_Y 0  
#define HIS_SCORE_POS_X 80
#define HIS_SCORE_POS_Y 0 
#define TIME_POS_X 20 
#define TIME_POS_Y 0 
#define SPEED_STUDENT 1.1 
#define SPEED_SCORE59_EASY 0.1
#define SPEED_SCORE59_HARD 0.5 
#define SPEED_PASS 0.5  
#define TIME_LIMIT 30 
#define INTERVAL_BETWEEN_EACH_LOOP 20 
#define SHOW_MSG_SHORT 100 
#define SHOW_MSG_LONG 1500
#define SCORE59_CNT 10 
#define GET_GAME_POINT 2
#define LOSE_GAME_POINT 5
#define VICTORY_GATE 60

void gotoxy(double x, double y); 
void DrawWhiteSpace(int a_x, int a_y, int b_x, int b_y); 
void Initialize(); 
void ChooseGameMode(); 
bool StartGame();
bool Collision(double x1, double y1, double x2, double y2); 
void UpdateInfoBar(int gameScore, std::chrono::seconds leftTime); 
bool PlayAgainOrNot(); 
void WelcomeMessage(); 
void GuideMessage();
void GameModeMessage();
void VictoryMessage();
void DefeatMessage();
void PlayAgainMessage();
void GoodbyeMessage();

int HISTORY_HIGH_SCORE = 0; 


int main()
{
    Initialize(); 

    WelcomeMessage();
    

    if (cin)
    {
        GuideMessage();
        _getch(); 
    }

    bool playAgain = true;

    while (playAgain)
    {
        ChooseGameMode();

        bool gameVictory = true;
        gameVictory = StartGame();

        if (gameVictory)
        {
            VictoryMessage();
            Sleep(SHOW_MSG_LONG); 
        }

        else
        {
            DefeatMessage();
            Sleep(SHOW_MSG_LONG);    
        }

        playAgain = PlayAgainOrNot();
    }

    GoodbyeMessage();
    Sleep(SHOW_MSG_LONG);
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);

    return 0;
}

void gotoxy(double x, double y) 
{   
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; 
    dwPos.Y = y; 
    SetConsoleCursorPosition(hCon, dwPos);
}

void DrawWhiteSpace(int ex1, int ey1, int ex2, int ey2) 
{
    for (int i = ex1; i <= ex2; i++)
    {
        for (int j = ey1; j <= ey2; j++)
        {
            gotoxy(i, j);
            cout << " ";
        }
    }
}

void Initialize() 
{
   
    LPCWSTR a = L"我操你媽";
    SetConsoleTitle(a);

    
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

void ChooseGameMode()
{
    GameModeMessage();

    char gameModeKey = '0';
    bool VaildKeyForGameMode = false;

    while (!VaildKeyForGameMode) 
    {
        gameModeKey = _getch();

        if (gameModeKey == 'e' || gameModeKey == 'E' || gameModeKey == 'h' || gameModeKey == 'H')
        {
            VaildKeyForGameMode = true;
        }
    }

    if (gameModeKey == 'e' || gameModeKey == 'E')
    {
        Enemy::setGameMode(1);                  
    }

    else
    {
        Enemy::setGameMode(0);            
    }
}

bool StartGame()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);

    std::chrono::seconds timeLimit(TIME_LIMIT); 
    std::chrono::seconds duration(0); 
    std::chrono::seconds leftTime(TIME_LIMIT); 
    auto start = chrono::steady_clock::now(); 
    int Score = 0; 

    Player std = Player(STUDENT_INITIAL_X, STUDENT_INITIAL_Y); 
    list<Enemy> enemys;
    list<Enemy>::iterator e; 
    list<Attack> attacks;
    list<Attack>::iterator a; 

    srand(time(nullptr)); 
    int worldWidth = BORDER_RIGHT - BORDER_LEFT + 1; 
    int worldLength = BORDER_DOWN - BORDER_UP + 1; 
    double nX = 0;
    double nY = 0;
    for (int i = 0; i < SCORE59_CNT; i++) 
    {
        nX = (rand() % worldWidth) + BORDER_LEFT;
        nY = (rand() % (worldLength / 2)) + (BORDER_UP); 
        enemys.push_back(Enemy(nX, nY));
    }

    while (duration < timeLimit)
    {
        for (a = attacks.begin(); a != attacks.end(); a++)
        {
            a->Move();
            if (a->isOut())
            {
                a->Erase();
                a = attacks.erase(a);
            }
        }

        for (e = enemys.begin(); e != enemys.end(); e++)
        {
            e->Move();
            if (e->isOut())
            {
                e->Erase();
                e = enemys.erase(e);

                nX = (rand() % worldWidth) + BORDER_LEFT;
                enemys.push_back(Enemy(nX, BORDER_UP));
            }
        }

        for (e = enemys.begin(); e != enemys.end(); e++)
        {

            for (a = attacks.begin(); a != attacks.end(); a++)
            {
                if (Collision(a->X(), a->Y(), a->X(), a->Y()))
                {
                    Score += GET_GAME_POINT;
                    a->Erase();
                    e->Erase();
                    a = attacks.erase(a);
                    e = enemys.erase(e);

                    nX = (rand() % worldWidth) + BORDER_LEFT;
                    enemys.push_back(Enemy(nX, BORDER_UP));
                }
            }
        }

        for (e = enemys.begin(); e != enemys.end(); e++)
        {

            if (Collision(e->X(), e->Y(), std.X(), std.Y()))
            {
                Score -= LOSE_GAME_POINT;
                std.Erase();
                e->Erase();
                Sleep(SHOW_MSG_SHORT);
                e = enemys.erase(e);

                nX = (rand() % worldWidth) + BORDER_LEFT;
                enemys.push_back(Enemy(nX, BORDER_UP));
            }
        }

        if (_kbhit())
        {
            char key = _getch();
            if (key == ' ') 
            {
                attacks.push_back(Attack(std.X(), std.Y() - 1));
            }
        }

        std.Move();

        auto t1 = chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::seconds>(t1 - start);
        leftTime = timeLimit - duration;

        UpdateInfoBar(Score, leftTime);

        Sleep(INTERVAL_BETWEEN_EACH_LOOP);
    }

    if (Score >= VICTORY_GATE)
        return true;
    else
        return false;
}

bool Collision(double x1, double y1, double x2, double y2)
{
    if (abs(x1 - x2) < EQUALITY_GAP_X)
    {
        if (abs(y1 - y2) < EQUALITY_GAP_Y)
            return true;
        else
            return false;
    }

    return false;
}

void UpdateInfoBar(int Score, std::chrono::seconds leftTime)
{
    gotoxy(TIME_POS_X, TIME_POS_Y); cout << "剩餘時間: " << leftTime.count() << "   ";
    gotoxy(CUR_SCORE_POS_X, CUR_SCORE_POS_Y); cout << "分數: " << Score << "  ";
    gotoxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y); cout << "歷史高分: " << HISTORY_HIGH_SCORE;
    if (Score >= HISTORY_HIGH_SCORE)
    {
        HISTORY_HIGH_SCORE = Score;
        gotoxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y); cout << "歷史高分: " << HISTORY_HIGH_SCORE;
    }
}

bool PlayAgainOrNot()
{
    PlayAgainMessage();

    char playAgainKey = '0';
    bool VaildKeyForPlayAgain = false;

    while (!VaildKeyForPlayAgain)
    {
        playAgainKey = _getch();

        if (playAgainKey == 'y' || playAgainKey == 'Y' || playAgainKey == 'n' || playAgainKey == 'N')
        {
            VaildKeyForPlayAgain = true;
        }
    }

    if (playAgainKey == 'n' || playAgainKey == 'N')
        return false;
    else
        return true;
}
