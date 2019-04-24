#include <iostream>

#include "geometry.h"

int main()
{
    Point p[] = { Point(2.5, 3.2), Point(1.3, 5.2), Point(0.1, 5.9), Point(5.7, 6.2), Point(7.2, 0.2) };
    PointArray pa(p, sizeof(p) / sizeof(Point));
    PointArray pA(p, sizeof(p) / sizeof(Point));

    std::cout << pa.getSize() << std::endl;
    std::cout << pa << std::endl;

    pa.push_back(Point(1.0f, -1.0f));
    std::cout << pa.getSize() << std::endl;
    std::cout << pa << std::endl;

    pa.insert(2, Point(17.5f, 17.5f));
    std::cout << pa.getSize() << std::endl;
    std::cout << pa << std::endl;

    pa.remove(3);
    std::cout << pa.getSize() << std::endl;
    std::cout << pa << std::endl;

    pa[0] = Point(3.0f, 3.0f);
    std::cout << pa.getSize() << std::endl;
    std::cout << pa << std::endl;

    pa = pA;
    std::cout << pa.getSize() << std::endl;
    std::cout << pa << std::endl;

    pA.push_back(Point(0.0f, 0.0f));
    pa = pA;
    std::cout << pa.getSize() << std::endl;
    std::cout << pa << std::endl;

    return 0;
}

