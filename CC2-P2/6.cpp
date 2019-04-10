#include<iostream>

const int LENGHT = 2;
const int WIDTH = 5;

template <typename T>
void swapByPtr(T* v1, T* v2)
{
    T t = *v1;
    *v1 = *v2;
    *v2 = t;
}

void printArray(const int* arr, const int n)
{
    for(size_t i = 0; i < n; ++i) std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

void reverseArray(int* arr, const int n)
{
    int* ptrB = arr;
    int* ptrE = arr + n - 1;
    while(ptrE - ptrB > 0)
        swapByPtr<int>(ptrB++, ptrE--);
}

void reverseArray02(int* arr, const int n)
{
    for(size_t i = 0; i < n / 2; ++i)
        swapByPtr<int>(arr + i, arr + (n - 1) - i);
}

void transpose(const int input[][LENGHT], int output[][WIDTH])
{
    for(int i = 0; i < WIDTH; ++i)
        for(int j = 0; j < LENGHT; ++j)
            output[j][i] = input[i][j];
}

int main()
{
    int arr01[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr02[] = {1, 2, 3, 4, 5, 6, 7};
    printArray(arr01, 8);
    reverseArray(arr01, 8);
    printArray(arr01, 8);

    printArray(arr02, 7);
    reverseArray(arr02, 7);
    printArray(arr02, 7);

    int arrM01[WIDTH][LENGHT] = {{1, 2}, {3, 4}};
    int arrM02[LENGHT][WIDTH];
    transpose(arrM01, arrM02);
    return 0;
}
