/*1. Выделить в памяти динамический одномерный массив
типа int. Размер массива запросить у пользователя.
Инициализировать его числами степенями двойки: 1, 2, 4,
8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть
освободить память. =) Разбить программу на функции.*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void array1(int size)
{
	int* arr;
	if ((size > 0) && (size< 32))
	{
		arr = new (nothrow) int[size];
		if (arr != nullptr)
		{
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = pow(2, i);
				cout << arr[i] << endl;
			}
			delete[] arr;
			arr = nullptr;
		}
	}
	else
	{
		cout << "Введено некорректное значение";
	}
}

int main()
{
	system("chcp 1251> nul");;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	array1(n);
	system("pause>nul");
	return 0;
}
