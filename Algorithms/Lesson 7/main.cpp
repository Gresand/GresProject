#include <iostream>
#include <iomanip>
#include <math.h>

#define SIZE 30

void printArr(int* arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(3) << arr[i];
    }
    std::cout << std::endl;
}

void fillRandom(int* arr, int size, size_t max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % max;
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//=======================1========================
void sortInserts(int* arr, int len)
{
    int temp, pos;
    for (int k = 1; k < len; k++)
    {
        temp = arr[k];
        pos = k - 1;

        while (pos >= 0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void quicksort(int* arr, int first, int last)
{
    if ((last - first) >= 10)
    {
        sortInserts(arr, last - first);
    }
    else
    {
        int i = first;
        int j = last;

        if (arr[first] > arr[(first + last) / 2])
        {
            if (arr[first] < arr[last])
            {
                swap(&arr[first], &arr[(first + last) / 2]);
            }
            else
            {
                swap(&arr[last], &arr[(first + last) / 2]);
            }
        }
        else if (arr[(first + last) / 2] > arr[last])
        {
            swap(&arr[last], &arr[(first + last) / 2]);
        }

        int x = arr[(first + last) / 2];

        do
        {
            while (arr[i] < x)
                i++;
            while (arr[j] > x)
                j--;

            if (i <= j)
            {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (i < last)
        {
            quicksort(arr, i, last);
        }
        if (first < j)
        {
            quicksort(arr, first, j);
        }
    }
}

//=======================2========================
void bucketSort(int* arr,const int len)
{
    int const max = len;
    const int b = 10;
    int buckets[b][max +1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }
    for (int digit = 1; digit < 1000000000; digit *= 10) {
        for (int i = 0; i < max; ++i) {
            int d = (arr[i] / digit) % b;
            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;
        }

        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {

                if (buckets[i][j] % 2 == 0) {
                    while (arr[idx] % 2 != 0) {
                        idx++;
                    }
                    arr[idx++] = buckets[i][j];
                }
            }
            buckets[i][max] = 0;
        }
    }
}

int main() {
//=======================1========================
    int arr1[SIZE];
    fillRandom(arr1,SIZE,100);
    printArr(arr1,SIZE);

    quicksort(arr1,0,SIZE-1);
    printArr(arr1,SIZE);

//=======================2========================

    std::cout << "\n   #2\n" << std::endl;

    int arr2[SIZE];
    fillRandom(arr2, SIZE, 100);
    printArr(arr2, SIZE);

    bucketSort(arr2, SIZE - 1);
    printArr(arr2, SIZE);

    return 0;
}
