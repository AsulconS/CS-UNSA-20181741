#ifndef COMMON_H
#define COMMON_H

template <typename T>
using criteria = bool (*)(T&, T&);

template <typename T>
void swap(T& v1, T& v2)
{
    T t = v1;
    v1 = v2;
    v2 = t;
}

#endif // COMMON_H
