#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "common.hpp"

template <typename T>
void bubbleSort(T* data, int size, criteria<T> crit)
{
    int j = size - 1;
    while(j)
    {
        for(size_t i = 0; i < j; ++i)
        {
            if(crit(data[i], data[i + 1]))
                swap<T>(data[i], data[i + 1]);
        }
        --j;
    }
}

#endif // BUBBLE_SORT_H
