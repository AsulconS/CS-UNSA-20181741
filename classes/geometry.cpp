#include "geometry.h"
#include "sorts.h"

PointArray::PointArray(Point* nData, int nSize)
{
    size = nSize;
    data = new Point[nSize];
    for(int i = 0; i < size; ++i)
        data[i] = nData[i];
}

void PointArray::sortByX(int (*comp)(double*, int, int))
{
    // quickSort(data, 0, size - 1, comp);
}

