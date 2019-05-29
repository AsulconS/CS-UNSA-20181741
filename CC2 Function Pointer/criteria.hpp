#ifndef CRITERIA_H
#define CRITERIA_H

#include "point.hpp"

template <typename T>
bool increasing(T& v1, T& v2)
{
    return v1 > v2;
}

template <typename T>
bool decreasing(T& v1, T& v2)
{
    return v1 < v2;
}

#endif // CRITERIA_H
