#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

using namespace std;

int n;
int* pn;


enum Cell: char {
    EMPTY = '_',
    CROSS = 'X',
    ZERO = '0'
};

struct Coord {
    size_t y;
    size_t x;
};

enum Progress {
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

#pragma pack(push,1)
struct GAME {
    Cell** ppField = nullptr;   //Поле для игры
    const size_t SIZE = 3;      // Константа 3х3
    Cell Human;                 // Кто чем играет
    Cell AI;
    Progress progress = IN_PROGRESS;
    size_t turn{ 0 };           //четные человек, нечетные ПК
};
#pragma pack(pop)

void cleanScr()
{
    system("cls");
    //std::cout << "\x1B[2J\x1B[H";
}

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void InitGame(GAME& g)
{
    //Выделяем поле в RАМ
    g.ppField = new Cell * [g.SIZE];
    for (size_t i = 0; i < g.SIZE; i++)
    {
        g.ppField[i] = new Cell[g.SIZE];
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            g.ppField[y][x] = EMPTY;
        }
    }

    //Кто чем ходит?
    if (getRandomNum(0, 1000) > 500)
    {
        g.Human = CROSS;
        g.AI = ZERO;
        g.turn = 0;
    }
    else
    {
        g.Human = ZERO;
        g.AI = CROSS;
        g.turn = 1;
    }
}

void DeInitGame(GAME& g)
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
        delete[] g.ppField[i];
    }
    delete[] g.ppField;
}

void printGame(const GAME& g)
{
    cout << "     ";
    for (size_t x = 0; x < g.SIZE; x++)
    {
        cout << x+1 <<"   ";
    }
    cout << endl;

    for (size_t y = 0; y < g.SIZE; y++)
    {
        cout << " " << y + 1 << " | ";
        for (size_t x = 0; x < g.SIZE; x++)
        {
            cout << g.ppField[y][x] << " | ";
        }
        cout << endl;
    }
    cout << endl << "Human: " << g.Human << endl;
    cout << endl << "Computer: " << g.AI << endl << endl;
}

void congrats(const GAME& g)
{
    if (g.progress == WON_HUMAN)
    {
        cout << "Human WON!" << endl;
    }
    else if (g.progress == WON_AI)
    {
        cout << "Computer WON!" << endl;
    }
    else if (g.progress == DRAW)
    {
        cout << "DRAW =/ " << endl;
    }
}

Progress getWon(const GAME& g)
{
    //Строках
    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.Human)
                return WON_HUMAN;
            if (g.ppField[y][0] == g.AI)
                return WON_AI;
        }
    }
    //Столбец
    for (size_t x = 0; x < g.SIZE; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.Human)
                return WON_HUMAN;
            if (g.ppField[0][x] == g.AI)
                return WON_AI;
        }
    }
    //Диагональ
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[1][1] == g.Human)
            return WON_HUMAN;
        if (g.ppField[1][1] == g.AI)
            return WON_AI;
    }
    if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[0][2] == g.ppField[1][1])
    {
        if (g.ppField[1][1] == g.Human)
            return WON_HUMAN;
        if (g.ppField[1][1] == g.AI)
            return WON_AI;
    }
    //Ничья
    bool draw = true;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }
    if (draw)
    {
        return DRAW;
    }
    return IN_PROGRESS;
}

Coord getHumanCoord(const GAME& g)
{
    Coord c;
    do
    {
        cout << "Enter X(1...3): ";
        cin >> c.x;
        cout << "Enter Y(1...3): ";
        cin >> c.y;
        c.x--;
        c.y--;
        if (g.ppField[c.y][c.x] != EMPTY)
        {
            cout << "Error! This cell is busy!";
        }
    } while (c.x > g.SIZE || c.y > g.SIZE || g.ppField[c.y][c.x] != EMPTY);
    return c;
}

Coord getAICoord(GAME& g)
{
    //1. Компьютер должен заботиться о своём выйгрыше
    //PRE WIN SITUATION

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.AI;
                if (getWon(g) == WON_AI)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    // 2. Компьютер должен мешать человеку выйграть
    //PRE FAIL CITUATION

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.Human;
                if (getWon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    //3. Ход по приоритетам + Ранд
    
    // Анализируем центр
    if (g.ppField[1][1] == EMPTY)
        return { 1,1 };

    //2. Анализируем углы
    Coord buf[4];
    size_t n = 0 ;
    if (g.ppField[0][0] == EMPTY)
    {
        buf[n] = { 0,0 };
        n++;
    }
    if (g.ppField[2][2] == EMPTY)
    {
        buf[n] = { 2,2 };
        n++;
    }
    if (g.ppField[0][2] == EMPTY)
    {
        buf[n] = { 0,2 };
        n++;
    }
    if (g.ppField[2][0] == EMPTY)
    {
        buf[n] = { 2,0 };
        n++;
    }
    if (n > 0)
    {
        const size_t index = getRandomNum(0, 1000) % n; //Получаем случайный индекс свободного угла
        return buf[index];
    }
    //3. Анализируем не углы
    n = 0;
    if (g.ppField[1][0] == EMPTY)
    {
        buf[n] = { 1,0 };
        n++;
    }
    if (g.ppField[1][2] == EMPTY)
    {
        buf[n] = { 1,2 };
        n++;
    }
    if (g.ppField[0][1] == EMPTY)
    {
        buf[n] = { 0,1 };
        n++;
    }
    if (g.ppField[2][1] == EMPTY)
    {
        buf[n] = { 2,1 };
        n++;
    }
    if (n > 0)
    {
        const size_t index = getRandomNum(0, 3000) % n; //Получаем случайный индекс свободного угла
        return buf[index];
    }
}


int main()
{
    GAME g;
    InitGame(g);
    cleanScr();
    printGame(g);

    do
    {
        if (g.turn % 2 == 0)
        {
            //Ходит человек
            Coord c = getHumanCoord(g);
            g.ppField[c.y][c.x] = g.Human;
        }
        else
        {
            //Ходит ПК
            Coord c = getAICoord(g);
            g.ppField[c.y][c.x] = g.AI;
        }
        cleanScr();
        printGame(g);
        g.turn++;
        g.progress = getWon(g);
    } while (g.progress == IN_PROGRESS);

    congrats(g);
    
    DeInitGame(g);
    return 0;
}

