#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "common.hpp"

template <typename T>
int partition(T* data, int low, int high)
{
    T pivot = data[high];
    int i = low - 1;
    for(size_t j = low; j < high; ++j)
    {
        if(data[j] < pivot)
            swap<T>(data[j], data[++i]);
    }
    swap<T>(data[high], data[i + 1]);
    return i + 1;
}

template <typename T>
void quick(T* data, int low, int high)
{
    if(low >= high)
        return;
    int partI = partition<T>(data, low, high);
    quick<T>(data, low, partI - 1);
    quick<T>(data, partI + 1, high);
}

template <typename T>
void quickSort(T* data, int size)
{
    quick<T>(data, 0, size - 1);
}

#endif // QUICK_SORT_H
