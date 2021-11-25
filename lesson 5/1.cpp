#include <iostream>;

using namespace std;

//====================================
//Задание 2
/* Задать целочисленный массив, состоящий из элементов 0
и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию,
заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить
на экран массив до изменений и после.*/
//====================================
bool Array2(int arr2[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr2[i] == 0)
        {
            arr2[i] = 1;
        }
        else
        {
            arr2[i] = 0;
        }
        cout << arr2[i] << " ";   
    }
    return true;
}

int main ()
{
const int a = 10;
int myarr2[a] = { 1,1,0,0,1,0,1,1,0,0 };
cout << "Before: " << endl;
for (size_t i = 0; i < a; i++)
{
    cout << myarr2[i] << " ";
}
cout << endl;
cout << "After: " << endl;
if (Array2(myarr2,a))
return 0;
}
