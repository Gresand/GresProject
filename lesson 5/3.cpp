#include <iostream>

using namespace std;

//Задание 3
/*Задать пустой целочисленный массив размером 8.
Написать функцию, которая с помощью цикла заполнит его
значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.*/

double Array(int* arr, int size)
{
    for (size_t i = 0; i < size-1; i++)
    {
        arr[i + 1] = arr[i]+3;
        cout << arr[i] << " ";
    }
    return true;
}

int main()
{
    const int a = 8;
    int myarr[a] = { 1 };
    if (Array(myarr, a))
    cout << myarr[7] << endl;
    return 0;
}

