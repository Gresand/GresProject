#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

/*3. Написать программу, которая создаст два текстовых
файла (*.txt), примерно по 50-100 символов в каждом
(особого значения не имеет с каким именно содержимым).
Имена файлов запросить у пользователя.*/

using namespace std;

void file1(int a, int b, char name[255])
{
	int** arr1;
	arr1 = new int* [a];
	ofstream fout(name);
	for (size_t i = 0; i < a; i++)
	{
		arr1[i] = new int[b];
	}
	for (size_t i = 0; i < a; i++)
	{
		for (size_t j = 0; j < b; j++)
		{
			arr1[i][j] = rand() % 100;
			fout << arr1[i][j] << " ";
		}
		fout << endl;
	}
	for (size_t i = 0; i < a; i++)
	{
		delete[] arr1[i];
	}
	delete[] arr1;
	fout.close();
}


int main()
{
	system("chcp 1251>nul");
	int a = 10, b = 10, c=20, d=20;
	char name1[255] = { 0 };
	cout << "Name 1 file: ";
	cin >> name1;
	char name2[255] = { 0 };
	cout << "Name 2 file: ";
	cin >> name2;
	file1(a, b,name1);
	file1(c, d,name2);
	return 0;
}

