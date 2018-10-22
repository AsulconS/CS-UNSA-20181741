#ifndef GEOMETRY_H
#define GEOMETRY_H

class Point
{
private:
    double x;
    double y;

public:
    Point(double nx = 0, double ny = 0) : x(nx), y(ny) {}
    virtual ~Point() {}

    inline double getX() const { return x; }
    inline double getY() const { return y; }
};

class PointArray
{
private:
    Point* data;
    int size;

public:
    PointArray(Point* nData, int nSize);
    virtual ~PointArray() { delete[] data; }

    void sortByX(int (*comp)(double*, int, int));
};

#endif // GEOMETRY_H

