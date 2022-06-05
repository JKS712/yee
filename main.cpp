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

void WelcomeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 20;
    int y = 10;
    gotoxy(x, y + 3); cout << " 上 下 左 右 進 行 移 動 ";
    gotoxy(31, y + 12); cout << "按R開始遊戲 或是任意鍵開始";
}

void GuideMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 44;
    int y = 2;
    gotoxy(x, y); cout << " 遊戲指引  |  Game Guide ";
    y = 5;
    gotoxy(50, y); cout << "    前言    ";
    x = 35;
    gotoxy(x, y + 2); cout << "蘿莉控是一名勇者，正在面臨著沒有蘿莉的困擾。";
    gotoxy(x, y + 4); cout << "因為蘿莉們都被大魔王給帶走了。   ";
    gotoxy(x, y + 6); cout << "因此踏上打倒大魔王的旅程。   ";
    gotoxy(x, y + 8); cout << "讓我們一起幫助蘿莉控，然後大家一起為成為紳士努力吧 ! ";
    gotoxy(48, y + 10); cout << "    遊戲玩法    ";
    gotoxy(x, y + 12); cout << "你是勇者，面臨著大量敵人，你需要進行攻擊，將敵人擊敗";
    gotoxy(x, y + 14); cout << "發射方式 : 按下鍵盤的空白鍵    移動方式 : 按下鍵盤的方向鍵 ";
    gotoxy(x, y + 16); cout << "計分方式 : 每消滅一個敵人即得" << GET_GAME_POINT << "分，若被敵人打到，倒扣" << LOSE_GAME_POINT << "分";
    gotoxy(x, y + 18); cout << "遊戲時間共" << TIME_LIMIT << "秒，在時間內打到" << VICTORY_GATE << "分即可通關。";
    gotoxy(x, y + 20); cout << "按下任意鍵開始遊戲";
}

void GameModeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 40;
    int y = 10;
    gotoxy(x, y + 1); cout << " 請選擇遊戲難度:";
    gotoxy(x, y + 3); cout << " 簡單：按 E";
    gotoxy(x, y + 5); cout << " 困難：按 H";
}

void VictoryMessage()
{
    DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;

    gotoxy(x, y + 3); cout << " 恭喜你離救出蘿莉越來越接近了 ";

    gotoxy(x, y + 8); cout << " 請期待下部作品 ";
}

void DefeatMessage()
{
    DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;

    gotoxy(x, y + 3); cout << " 你失敗了 快點再次出發 ";

    gotoxy(x, y + 8); cout << " 就你這速度 蘿莉都長大了 ";
}

void PlayAgainMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT, BORDER_DOWN);
    int x = 10;
    int y = 10;

    gotoxy(x, y + 3); cout << " 再玩一次請按 Y 結束請按 N ";

}

void GoodbyeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 15;
    int y = 10;

    gotoxy(x, y + 3); cout << " 感謝你的遊玩 ";

    gotoxy(x, y + 6); cout << " Thanks for playing!";
}
