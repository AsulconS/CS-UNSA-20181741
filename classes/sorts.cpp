#include "sorts.h"

void swapByPtr(double* d1, double* d2)
{
    double t = *d1;
    *d1 = *d2;
    *d2 = t;
}

int partitionPos(double* data, int low, int high)
{
    double pivot = *(data + high);
    int i = low - 1;
    for(int j = low; j <= high - 1; ++j)
    {
        if(*(data + j) <= pivot)
        {
            ++i;
            swapByPtr(data + j, data + i);
        }
    }
    swapByPtr(data + high, data + i + 1);
    return i + 1;
}

int partitionNeg(double* data, int low, int high)
{
    double pivot = *(data + high);
    int i = low - 1;
    for(int j = low; j <= high - 1; ++j)
    {
        if(*(data + j) >= pivot)
        {
            ++i;
            swapByPtr(data + j, data + i);
        }
    }
    swapByPtr(data + high, data + i + 1);
    return i + 1;
}

void quickSort(double* data, int low, int high, int (*comp)(double*, int, int))
{
    if(low < high)
    {
        int partI = comp(data, low, high);
        quickSort(data, low, partI - 1, comp);
        quickSort(data, partI + 1, high, comp);
    }
}
