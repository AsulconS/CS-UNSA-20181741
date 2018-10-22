#include "geometry.h"
using namespace std;

int main()
{
    Point p[5] = { Point(2.5, 3.2), Point(1.3, 5.2), Point(0.1, 5.9), Point(5.7, 6.2), Point(7.2, 0.2) };
    PointArray pa(p, 5);
    return 0;
}

