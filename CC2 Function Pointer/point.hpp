#ifndef POINT_H
#define POINT_H

template <typename T>
class Point
{
public:
    T x;
    T y;
    char axis;

    Point() {}
    Point(T _x, T _y, char _axis) : x(_x), y(_y), axis(_axis) {}

    bool operator<(const Point& p)
    {
        if(axis == 'x')
            return this->x < p.x;
        else
            return this->y < p.y;
    }
    bool operator>(const Point& p)
    {
        if(axis == 'x')
            return this->x > p.x;
        else
            return this->y > p.y;
    }
};

#endif // POINT_H
