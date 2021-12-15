#include <iostream>

/*Задайте массив типа int. Пусть его размер задается через
директиву препроцессора #define. Инициализируйте его через
ввод с клавиатуры. Напишите для него свою функцию
сортировки (например Пузырьком). Реализуйте перестановку
элементов как макрокоманду SwapINT(a, b). Вызывайте ее из
цикла сортировки.*/

#define ARRAY_SIZE 10
#define SwapINT(a,b) ((a)>(b)) ? (t=b,b=a,a=t) : (a,b)

using namespace std;

void my_array(int* arr, const size_t size)
{
	int t = 0;
	for (size_t i = 0; i < size; i++)
	{
		cout << "Element " << i + 1 << " = ";
		cin >> arr[i];
	}
	for (size_t i = 0; i < ARRAY_SIZE-1; i++)
	{
		for (size_t j = 0; j < ARRAY_SIZE - 1; j++)
		{
			SwapINT(arr[j], arr[j+1]);
		}
	}
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
    int arr[ARRAY_SIZE];
	my_array(arr, ARRAY_SIZE);
    return 0;
}
