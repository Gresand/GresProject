// ДЗ ко второму уроку.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>

using namespace std;

//Задание 2

enum GameXO {
    X,
    O,
    StartX,
    StartO,
    MoveX,
    MoveO,
    WinO,
    WinX,
    Draw,
    ExitOfGame,
    Setting
};

//Задание 4

#define space ' '
struct FieldXO 
{
    char matrix[3][3]{
        {space, space, space},
        {space, space, space},
        {space, space, space}
    };                            //Игровое поле 3х3
    bool check = false;           //Проверка на победу
}; 

//Задание 5

union MyData {
        int whole;                //целое число
        float fraction;           //дробь
        char text;              //текст
};
struct MyVariant {
    MyData data;
    unsigned int FlagIsInt   : 1; //флаг на целое число
    unsigned int FlagIsFloat : 1; //флаг на дробь
    unsigned int FlagIsChar  : 1; //флаг на текст
};

int main()
{
    setlocale(LC_ALL, "Russian");

    //Задание 1

    cout << "Задание 1\n" << endl;
    bool flag = true;
    char txt = 'A';
    unsigned short int little = 255;
    int A = 256;
    long long UltraLong = 9'233'372'036'854'775'807;
    float Pi = 3.14;
    double E = 2.718281828459045;
    void;
    cout << flag << " \n"
        << txt << " \n"
        << little << " \n"
        << A << " \n"
        << UltraLong << " \n"
        << Pi << " \n"
        << E << " \n" << endl;

    //Задание 3

    cout << "Задание 3\n" << endl;
    char Gamer_1 = 'X';
    cout << "Выберете своего персонажа X или О" << endl;
    cin >> Gamer_1;
    if (Gamer_1 == 'X') {
        GameXO start[1] = { X };
        cout << "Вы играете " << Gamer_1 << endl;
    }
    else if (Gamer_1 == 'O') {
        GameXO start[1] = { O };
        cout << "Вы играете " << Gamer_1 << endl;
    }
    else
        cout << "Выбран не существующий персонаж" << endl;

    //Задание 5
  
    MyVariant FInt;
    FInt.data.whole           = 255;
    FInt.FlagIsInt            = 1;
    FInt.FlagIsFloat          = 0;
    FInt.FlagIsChar           = 0;
    cout << FInt.data.whole   << " "
        << FInt.FlagIsInt     << " "
        << FInt.FlagIsFloat   << " "
        << FInt.FlagIsChar    << endl;

    MyVariant FFloat;
    FFloat.data.fraction       = 1.01;
    FFloat.FlagIsInt           = 0;
    FFloat.FlagIsFloat         = 1;
    FFloat.FlagIsChar          = 0;
    cout << FInt.data.fraction << " "
        << FInt.FlagIsInt      << " "
        << FInt.FlagIsFloat    << " "
        << FInt.FlagIsChar     << endl;

    MyVariant FChar;
    FChar.data.text            = 'A';
    FChar.FlagIsInt            = 0;
    FChar.FlagIsFloat          = 0;
    FChar.FlagIsChar           = 1;
    cout << FInt.data.text     << " "
        << FInt.FlagIsInt      << " "
        << FInt.FlagIsFloat    << " "
        << FInt.FlagIsChar     << endl;
   
    return 0;

}


/*В одном main.cpp файле / проекте:
1. Создать и инициализировать переменные пройденных типов данных(short
    int, int, long long, char, bool, float, double).
    2. Создать перечисление(enum) с возможными вариантами символов для
    игры в крестики - нолики.
    3. Создать массив, способный содержать значения такого перечисления и
    инициализировать его.
    4. * Создать структуру(struct) данных «Поле для игры в крестики - нолики» и
    снабдить его всеми необходимыми свойствами(подумайте что может
        понадобиться).
    5. * *Создать структуру(struct MyVariant) объединяющую: union MyData(int,
        float, char) и 3 - и битовых поля(флага) указывающими какого типа значение в
    данный момент содержится в объединении(isInt, isFloat, isChar).
    Продемонстрировать пример использования в коде этой структуры.
    Для программирования используйте установленную среду программирования
    (IDE).Если задания 4 и 5 кажутся сложными постарайтесь сделать первые 3. */
