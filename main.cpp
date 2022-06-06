#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <ctime>
#include <chrono> 
#include <list>
#include <conio.h> 
#include <windows.h> 
#include <vector>

#include "Attack.h"
#include "Enemy.h"
#include "Player.h"

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
#define PLAYER_INITIAL_X 58.5 
#define PLAYER_INITIAL_Y 25
#define EQUALITY_GAP_X 1.5
#define EQUALITY_GAP_Y 1
#define CUR_SCORE_POS_X 50 
#define CUR_SCORE_POS_Y 0  
#define GAMEMODE_POS_X 80
#define GAMEMODE_POS_Y 0 
#define TIME_POS_X 20 
#define TIME_POS_Y 0 
#define SPEED_PLAYER 1.1 
#define SPEED_ENEMY_EASY 0.1
#define SPEED_ENEMY_HARD 0.5 
#define SPEED_SUPER_HARD 0.9
#define SPEED_ATTACK 0.5  
#define TIME_LIMIT 30 
#define INTERVAL_BETWEEN_EACH_LOOP 20 
#define SHOW_MSG_SHORT 200 
#define SHOW_MSG_LONG 1500
#define ENEMY_CNT 10 
#define GET_GAME_POINT 2
#define LOSE_GAME_POINT 5
#define VICTORY_GATE 60

int HISTORY_HIGH_SCORE = 0;

void gotoxy(double x, double y);
void DrawWhiteSpace(int ex1, int ey1, int ex2, int ey2);
bool Collision(double x1, double y1, double x2, double y2);
void UpdateInfoBar(int Score, std::chrono::seconds leftTime);
void GameModeMessage();

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

    LPCWSTR a = L"�ڵ��藍�|�����m�J";
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

    char gameModeKey = 'g';
    int VaildKeyForGameMode = 0;

    while (!VaildKeyForGameMode)
    {
        gameModeKey = _getch();

        if (gameModeKey == 'e' || gameModeKey == 'E' || gameModeKey == 'h' || gameModeKey == 'H' || gameModeKey == 'g' || gameModeKey == 'G' )
        {
            VaildKeyForGameMode = 1;
        }
    }
    if (gameModeKey == 'g' || gameModeKey == 'G')
    {
        Enemy::setGameMode(2);
    }
    else if (gameModeKey == 'e' || gameModeKey == 'E')
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
    int Score = 100;

    Player player = Player(PLAYER_INITIAL_X, PLAYER_INITIAL_Y);
    vector<Enemy> enemys;
    vector<Enemy>::iterator e;
    vector<Attack> attacks;
    vector<Attack>::iterator a;

    srand(time(nullptr));
    int worldWidth = BORDER_RIGHT - BORDER_LEFT + 1;
    int worldLength = BORDER_DOWN - BORDER_UP + 1;
    double nX = 0;
    double nY = 0;
    for (int i = 0; i < ENEMY_CNT ; i++)
    {
        nX = (rand() % worldWidth) + BORDER_LEFT;
        nY = (rand() % (worldLength / 2)) + (BORDER_UP);
        enemys.push_back(Enemy(nX, nY));
    }

    while (duration < timeLimit)
    {
        for (a = attacks.begin(); a != attacks.end(); a++)
        {
            a->AttackMove();
            if (a->AttackisOut())
            {
                a->AttackErase();
                a = attacks.erase(a);
            }
        }

        for (e = enemys.begin(); e != enemys.end(); e++)
        {
            e->EnemyMove();
            if (e->EnemyisOut())
            {
                e->EnemyErase();
                e = enemys.erase(e);

                nX = (rand() % worldWidth) + BORDER_LEFT;
                enemys.push_back(Enemy(nX, BORDER_UP));
            }
        }

        if (Score <= 0)
            break;

        /*
        for (e = enemys.begin(); e != enemys.end(); e++)
        {
            for (a = attacks.begin(); a != attacks.end(); a++)
            {
                if (Collision(a->X(), a->Y(), e->X(), e->Y()))
                {
                    Score += GET_GAME_POINT;
                    a->AttackErase();
                    e->EnemyErase();
                    a = attacks.erase(a);
                    e = enemys.erase(e);

                    nX = (rand() % worldWidth) + BORDER_LEFT;
                    enemys.push_back(Enemy(nX, BORDER_UP));
                }
            }
        }
        */
        for (e = enemys.begin(); e != enemys.end(); e++)
        {

            if (Collision(e->X(), e->Y(), player.X(), player.Y()))
            {
                Score -= LOSE_GAME_POINT;
                player.PlayerErase();
                e->EnemyErase();
                Sleep(SHOW_MSG_SHORT);
                e = enemys.erase(e);

                nX = (rand() % worldWidth) + BORDER_LEFT;
                enemys.push_back(Enemy(nX, BORDER_UP));
            }
        }
        /*
        if (_kbhit())
        {
            char key = _getch();
            if (key == ' ')
            {
                attacks.push_back(Attack(player.X(), player.Y() - 1));
            }
        }
        */
        player.PlayerMove();

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
    gotoxy(TIME_POS_X, TIME_POS_Y); cout << "�Ѿl�ɶ�: " << leftTime.count() << "   ";
    gotoxy(CUR_SCORE_POS_X, CUR_SCORE_POS_Y); cout << "��q: " << Score << "  ";
    gotoxy(GAMEMODE_POS_X, GAMEMODE_POS_Y); cout << "�C������: ";
    if (Enemy::getGameMode() == 2) cout << "�ܺA";
    else if (Enemy::getGameMode() == 1) cout << "²��";
    else cout << "�x��";
}

void WelcomeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 20;
    int y = 10;
    gotoxy(x, y + 3); cout << "�W�ž�ĥ��V�t�z������פp��P�@���ڲ��j�@��!  ";
    gotoxy(x, y + 12); cout << "��R�[�ݹC���޾� �άO���N��}�l";
}

void GuideMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 50;
    int y = 2;
    gotoxy(x, y); cout << "  �C������  ";
    y = 5;
    gotoxy(50, y); cout << "    �e��    ";
    x = 35;
    gotoxy(x, y + 2); cout << "�ڲ����O�@�W�i�̡A���b���{�ۨS���ڲ����x�Z�C";
    gotoxy(x, y + 4); cout << "�]���ڲ��̳��Q�j�]�����a���F�C ��W���ˤj�]�����ȵ{  ";
    gotoxy(x, y + 6); cout << "���O�L���Z���a�F�S��k�ϥΡA�{�b�n��t�@�ӬP�t�R�Z��   ";
    gotoxy(x, y + 8); cout << "���ڭ̤@�_���U�ڲ����A�M��j�a�@�_�������Ԥh�V�O�a ! ";
    gotoxy(48, y + 10); cout << "    �C�����k    ";
    gotoxy(x, y + 12); cout << "�A�O�i�̡A�A�{�b�ݭn��V�p��P�a�A�b���B���]������";
    gotoxy(x, y + 14); cout << "���U��L����V�A�ޱ��A����ĥ ";
    gotoxy(x, y + 16); cout << "�Y�Q�p��P�����A�N�|��" << LOSE_GAME_POINT << "��";
    gotoxy(x, y + 18); cout << "�C���ɶ��@" << TIME_LIMIT << "��A�b�ɶ�������" << VICTORY_GATE << "���Y�i�q���C";
    gotoxy(x, y + 20); cout << "���U���N��}�l�C��...";
}

void GameModeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 40;
    int y = 10;
    gotoxy(x, y + 1); 
    cout << " �п�ܹC������:";
    gotoxy(x, y + 3); 
    cout << " ²��G�� E";
    gotoxy(x, y + 5); 
    cout << " �x���G�� H" ;
    gotoxy(110, y + 20);
    cout << " �m�J��G ";
    gotoxy(0, 0);
    cout << " ";
    gotoxy(x + 15, y + 5);
    cout << " ";
}

void VictoryMessage()
{
    DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;

    gotoxy(x, y + 3); cout << " ���ߧA���ϥX�ڲ��V�ӶV����F ";

    gotoxy(x, y + 8); cout << " �д��ݤG���� ";
}

void DefeatMessage()
{
    DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;

    gotoxy(x, y + 3); cout << " �A���ѤF ���I�A���X�o ";

    gotoxy(x, y + 8); cout << " �N�A�o�t�� �ڲ������j�F ";
}

void PlayAgainMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT, BORDER_DOWN);
    int x = 10;
    int y = 10;

    gotoxy(x, y + 3); cout << " �A���@���Ы� Y �����Ы� N ";

}

void GoodbyeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 15;
    int y = 10;

    gotoxy(x, y + 3); cout << " �P�§A���C�� ";

    gotoxy(x, y + 6); cout << " Thanks for playing!";
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

int main()
{
    Initialize();

    WelcomeMessage();
    char guideKey = _getch();

    if (guideKey == 'r' || guideKey == 'R')
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