#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

class Point
{
    friend std::ostream& operator<<(std::ostream& o, const Point& p);
public:
    Point(const Point& o);
    Point(const double nx = 0, const double ny = 0) : x(nx), y(ny) {}
    virtual ~Point() {}

    inline double getX() const { return x; }
    inline double getY() const { return y; }

    Point& operator=(const Point& p);

private:
    double x;
    double y;
};

class PointArray
{
    friend std::ostream& operator<<(std::ostream& o, const PointArray& pa);
public:
    PointArray();
    PointArray(const PointArray& o);
    PointArray(const Point* nData, const int nSize);
    virtual ~PointArray() { delete[] data; }

    void push_back(const Point& p);
    void insert(const int pos, const Point& p);
    void remove(const int pos);
    void clear();
    
    void sortByX(int (*comp)(double*, int, int));

    inline const int getSize() const { return size; }

    inline Point* get(const int pos) { return (pos >= 0 && pos < size) ? &data[pos] : NULL; }
    inline const Point* get(const int pos) const { return (pos >= 0 && pos < size) ? &data[pos] : NULL; }

    Point& operator[](const int i);
    PointArray& operator=(const PointArray& pa);

private:
    Point* data;
    int size;

    void resize(const int newSize);
};

class Polygon
{
public:
    Polygon(const Polygon& o);
    Polygon(const PointArray& pa);
    Polygon(const Point* points, const int size);
    virtual ~Polygon() { --instances; }

    virtual double area() const = 0;

    inline static const int getNumPolygons() { return instances; }
    inline const int getNumSides() { return data.getSize(); }
    inline const PointArray* getPoints() const { return &data; }

protected:
    static int instances;
    PointArray data;
};

class Rectangle : public Polygon
{
public:
    Rectangle(const Point& p1, const Point& p2);
    Rectangle(const int v0, const int v1, const int v2, const int v3);

    virtual double area() const;
};

class Triangle : public Polygon
{
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    
    virtual double area() const;
};

#endif // GEOMETRY_H
