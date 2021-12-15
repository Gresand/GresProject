/*2. Динамически выделить матрицу 4х4 типа int.
Инициализировать ее псевдослучайными числами через
функцию rand. Вывести на экран. Разбейте вашу
программу на функции которые вызываются из main.*/

#include <iostream>
#include <cstdlib>

using namespace std;

void Array(const size_t a, const size_t b)
{
    int** arr;
    arr = new int* [a];

    for (size_t i = 0; i < a; i++)
    {
        arr[i] = new int[b];
    }

    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }

    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (size_t i = 0; i < a; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    arr = nullptr;
}

int main()
{
    system ("chcp 1251>nul");
    const size_t a = 4;
    const size_t b = 4;
    Array(a, b);
    system("pause > nul");
    return 0;
}
