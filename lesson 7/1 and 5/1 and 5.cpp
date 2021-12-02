/*1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp,
mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
для инициализации массива (типа float), печати его на экран и
подсчета количества отрицательных и положительных
элементов. Вызывайте эти 3-и функции из main для работы с
массивом.
5. Сделайте задание 1 добавив свой неймспейс во втором
модуле*/

#include <iostream>
#include "mylib.h"

#define SIZE 5

using namespace std;

int main()
{
    float arr1[SIZE];
    float arr2[SIZE];
    float arr3[SIZE];
    Mylib::initializationArray(arr1, SIZE);
    Mylib::printArray(arr1, SIZE);
    Mylib::ponArray(arr1, SIZE);
    Mylib::initializationArray(arr2, SIZE);
    Mylib::printArray(arr2, SIZE);
    Mylib::ponArray(arr2, SIZE);
    Mylib::initializationArray(arr3, SIZE);
    Mylib::printArray(arr3, SIZE);    
    Mylib::ponArray(arr3, SIZE);
    return 0;
}
