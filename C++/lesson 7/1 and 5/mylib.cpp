#include <iostream>

using namespace std;

namespace Mylib
{

	void initializationArray(float* array, int SIZE)
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "Elenemt: " << i+1 << " = ";
			cin >> array[i];
		}
	}

	void printArray(float* array, int SIZE)
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "Element massiv: " << i+1 << " = " << array[i] << endl;;
		}
	}

	void ponArray(float* array, int SIZE)
	{
		int p = 0, n = 0;
		for (int i = 0; i < SIZE; i++)
		{
			if (array[i] > 0)
			{
				p += 1;
			}
			else
			{
				n += 1;
			}
		}
		cout << "Positiv: " << p << endl;
		cout << "Negativ: " << n << endl;
		cout << endl;
	}
}