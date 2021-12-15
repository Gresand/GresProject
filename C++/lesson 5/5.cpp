#include <iostream>
#include <cstdlib>

using namespace std;

//Задание 5
/*Написать функцию, которой передается не пустой
одномерный целочисленный массив, она должна вернуть
истину если в массиве есть место, в котором сумма левой и
правой части массива равны. Примеры: checkBalance([1, 1,
1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница
показана символами ||, эти символы в массив не входят.*/

bool array1(int* arr, int size)
{
    int left = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        left += arr[i];
        int right = 0;
        for (size_t k = i+1; k < size; k++)
        {
            right += arr[k]; 
        }
        if (left == right)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    system("chcp 1251>nul");
    const int size = 5;
    int myarr[size] = {8,1,0,1,8};
    for (size_t i = 0; i < size; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;
    if (array1(myarr, size))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    (array1(myarr, size));
    system("pause>nul");
    return 0;
}
