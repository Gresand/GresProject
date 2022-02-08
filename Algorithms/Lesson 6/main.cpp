#include <iostream>
#include <math.h>
//===============================================================
int** newarr(int** arr, const int col, const int rows)
{
    arr = new int*[col];
    arr[0] = new int[col*rows];
    for (int k = 0; k < col; ++k) {
        arr[k] = arr[0] + k*rows;
    }
    return arr;
}

void fillArray(int** arr,const int col, const int rows)
{
    for (int k = 0; k < col; ++k) {
        for (int i = 0; i < rows; ++i) {
            arr[k][i] = (rand()%10)+1;
        }
    }
}

void deletearr(int** arr)
{
    delete[] arr[0];
    delete[] arr;
    arr = nullptr;
}

void showarr(int**arr,const int col, const int rows)
{
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}
//===============================================================

//======================1==========================
void bubble(int** arr,const int col, const int rows)
{
    int x = col*rows;
    int temp = 0;
    for (int i = 0; i < (col*rows-1); ++i) {
        for (int j = 0; j < (x-1); ++j) {
            if (arr[j/col][j%col]>arr[j/col][(j%col)+1])
            {
                temp = arr[j/col][j%col];
                arr[j/col][j%col] = arr[j/col][(j%col)+1];
                arr[j/col][(j%col)+1] = temp;
            }
        }
        x--;
        std::cout << "Step: " << i+1 << std::endl;
        showarr(arr,col,rows);
    }
}

//========================2=========================
void TPK(float* arr, int numbs)
{
    for (int i = 0; i < numbs; ++i) {
        std::cout << "Enter number " << i + 1 << " :";
        std::cin >> arr[i];
    }

    float temp = 0;

    for (int i = 0; i < numbs/2; ++i) {
        temp = arr[i];
        arr[i] = arr[numbs-1-i];
        arr[numbs-1-i] = temp;
    }

    for (int i = 0; i < numbs; i++)
    {
        arr[i] = sqrt(abs(arr[i])) + 5 * pow(arr[i], 3);
        if (arr[i] > 400)
        {
            std::cout << "Number # " << numbs - i << " equal: " << arr[i] << std::endl;
        }
    }

}

int main()
{
//======================1==========================
    const int rows = 3;
    const int col =3;

    int ** array1 = nullptr;
    array1 = newarr(array1,col,rows);
    fillArray(array1, col,rows);

    std::cout << "Without  sort:\n";
    showarr(array1,col,rows);
    bubble(array1,col,rows);

    std::cout << "With sort:\n";
    showarr(array1,col,rows);

    deletearr(array1);

//========================2=========================
    const int numbs = 11;
    float array2[numbs] = {0};
    TPK(array2,numbs);

    return 0;
}