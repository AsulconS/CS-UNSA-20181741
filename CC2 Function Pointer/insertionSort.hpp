#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "common.hpp"

template <typename T>
void insertionSort(T* data, int size, criteria<T> crit)
{
    T key;
    int j;
    for(size_t i = 1; i < size; ++i)
    {
        key = data[i];
        j = i - 1;

        while(j >= 0 && crit(data[j], key))
        {
            data[j + 1] = data[j];
            --j;
        }

        data[j + 1] = key;
    }
}

#endif // INSERTION_SORT_H
