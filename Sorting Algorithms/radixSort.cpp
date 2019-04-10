#include <iostream>

template <typename T>
int count(T* data, int size, T v, int base)
{
    size_t q = 1;
    for(size_t i = 0; i < base - 1; ++i)
        q *= 10;

    int accumulator = 0;
    for(size_t i = 0; i < size; ++i)
        if((data[i] / q) % 10 == v)
            ++accumulator;
    return accumulator;
}

void countingSort(int* data, int size, int base)
{
    size_t q = 1;
    for(size_t i = 0; i < base - 1; ++i)
        q *= 10;

    int* output = new int[size];
    int* index = new int[10] {0};

    for(size_t i = 0; i < 10; ++i) // Counts numbers
        index[i] = count<int>(data, size, i, base);
    for(size_t i = 1; i < 10; ++i) // Sums the Indices
        index[i] += index[i - 1];
    for(int i = size - 1; i >= 0; --i) // Assign the correct ones
        output[--index[(data[i] / q) % 10]] = data[i];

    for(size_t i = 0; i < size; ++i)
        data[i] = output[i];

    delete[] output;
    delete[] index;
}

void radixSort(int* data, int size, int base)
{
    for(size_t iBase = 1; iBase <= base; ++iBase)
        countingSort(data, size, iBase);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    for(size_t i = 0; i < 8; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    radixSort(arr, 8, 3);
    for(size_t i = 0; i < 8; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    return 0;
}
