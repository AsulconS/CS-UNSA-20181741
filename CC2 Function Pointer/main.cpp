#include <iostream>

#include "criteria.hpp"
#include "bubbleSort.hpp"
#include "insertionSort.hpp"
#include "quickSort.hpp"

template <typename T>
void printValues(T* data, int size)
{
    for(size_t i = 0; i < size; ++i)
        std::cout << data[i] << ' ';
    std::cout << std::endl;
}

template <>
void printValues<Point<int>>(Point<int>* data, int size)
{
    for(size_t i = 0; i < size; ++i)
        std::cout << '(' << data[i].x << ' ' << data[i].y << ')';
    std::cout << std::endl;
}

int main()
{
    int        dataInt[]   = { 5, 4, 2, 8, 9, 7, 15, 1 };
    Point<int> dataPointIntX[] = { {1, 2, 'x'}, {4, 5, 'x'}, {-1, -2, 'x'}, {4, -5, 'x'} };
    Point<int> dataPointIntY[] = { {1, 2, 'y'}, {4, 5, 'y'}, {-1, -2, 'y'}, {4, -5, 'y'} };

    printValues<int>(dataInt, 8);
    printValues<Point<int>>(dataPointIntY, 4);

    std::cout << std::endl;

    insertionSort<int>(dataInt, 8, increasing);
    printValues<int>(dataInt, 8);
    bubbleSort<int>(dataInt, 8, decreasing);
    printValues<int>(dataInt, 8);

    std::cout << std::endl;

    insertionSort<Point<int>>(dataPointIntY, 4, increasing);
    printValues<Point<int>>(dataPointIntY, 4);
    bubbleSort<Point<int>>(dataPointIntY, 4, decreasing);
    printValues<Point<int>>(dataPointIntY, 4);

    return 0;
}
