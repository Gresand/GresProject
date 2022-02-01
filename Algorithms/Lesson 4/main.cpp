#include <iostream>
#include <iomanip>

void show1(int **arr,int x, int y)
{
    for (size_t i = 0; i <= y; i++)
    {
        arr[i] = arr[0] + (x+1) * i;
    }
    for (size_t i = 0; i <= y; i++)
    {
        for (size_t j = 0; j <= x; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void show2(int**arr,int x,int y)
{
    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            std::cout << std::setw(4) << arr[i][j];
        }
        std::cout << std::endl;
    }
}



int theking(int** arr, int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }
    else if (arr[x][y] == 1)
    {
        return 0;
    }
    else if (x == 0) {
        if (theking(arr, x, y - 1) == 0 && y != 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (y == 0)
    {
        if (theking(arr, x - 1, y) == 0 && x != 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return theking(arr, x - 1, y) + theking(arr, x, y - 1);
}

void magic(int**arr,int x,int y)
{
    for (int i = 0; i<=y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            std::cout << std::setw(4) << theking(arr, i, j);
        }
        std::cout << std::endl;
    }

}

int main()
{

    int x = 5;
    int y = 5;

    int** array = new int*[y+1];
    array[0] = new int[((x+1)*(y+1))];

    show1(array,x,y);
    array[3][0] = 1;
    array[0][2] = 1;

    show2(array,x,y);

    std::cout << std::endl;

    magic(array,x,y);

    delete[] array[0];
    delete[] array;
    array = nullptr;

    return 0;
}