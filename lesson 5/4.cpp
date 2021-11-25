#include <iostream>
#include <cstdlib>

using namespace std;

//Задание 4
/*4. * Написать функцию, которой на вход подаётся
одномерный массив и число n (может быть положительным,
или отрицательным), при этом метод должен циклически
сместить все элементы массива на n позиций.*/

void movearr(int* array, int size)
{
    int n;
    cin >> n;
    if (n > 0)
    {
        cout << "Сдвиг влево на " << n << endl;
        while (n > 0)
        {
            int t = array[0];
            for (size_t i = 0; i < size - 1; i++)
            {
                array[i] = array[i + 1];
            }
            array[size - 1] = t;
            n--;
        }
    }
    else
    {
        cout << "Сдвиг вправо на " << abs(n) << endl;
        while (n < 0)
        {
            int t = array[4];
            for (size_t i = size-1; i > 0; i--)
            {
                array[i] = array[i-1];
            }
            array[0] = t;
            n++;
        }
    }
}

int main()
{
    system("chcp 1251>nul");
    const int a = 5;
    int myarr[a] = { 1,2,3,4,5 };
    cout << "До сдвига: " << endl;
    for (size_t i = 0; i < a; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;
    cout << "Введите сдвиг: " << endl;
    movearr(myarr, a);
    for (size_t i = 0; i < a; i++)
    {
        cout << myarr[i] << " ";
    }
    system("pause>nul");
    return 0;
}
