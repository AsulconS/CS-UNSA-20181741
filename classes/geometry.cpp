#include "geometry.h"
#include "sorts.h"

Point::Point(const Point& o)
    : x(o.x), y(o.y) {}

Point& Point::operator=(const Point& p)
{
    x = p.x;
    y = p.y;
    return *this;
}

std::ostream& operator<<(std::ostream& o, const Point& p)
{
    o << '(' << p.x << ',' << p.y << ')';
    return o;
}

PointArray::PointArray()
{
    data = new Point[0];
    size = 0;
}

PointArray::PointArray(const PointArray& o)
{
    data = new Point[o.size];
    size = o.size;
    for(int i = 0; i < size; ++i)
        data[i] = o.data[i];
}

PointArray::PointArray(const Point* nData, const int nSize)
{
    data = new Point[nSize];
    size = nSize;
    for(int i = 0; i < size; ++i)
        data[i] = nData[i];
}

void PointArray::push_back(const Point& p)
{
    resize(size + 1);
    data[size - 1] = p;
}

void PointArray::insert(const int pos, const Point& p)
{
    if(pos >= 0 && pos <= size)
    {
        resize(size + 1);
        for(int i = size - 1; i > pos; --i)
            data[i] = data[i - 1];
        data[pos] = p;
    }
    else
    {
        std::cerr << "Invalid insertion!" << std::endl;
    }
}

void PointArray::remove(const int pos)
{
    if(pos >= 0 && pos < size)
    {
        for(int i = pos; i < size - 1; ++i)
            data[i] = data[i + 1];
        resize(size - 1);
    }
    else
    {
        std::cerr << "Invalid remotion!" << std::endl;
    }
}

void PointArray::clear()
{
    resize(0);
}

void PointArray::sortByX(int (*comp)(double*, int, int))
{
    // quickSort(data, 0, size - 1, comp);
}

Point& PointArray::operator[](const int i)
{
    return data[i];
}

PointArray& PointArray::operator=(const PointArray& pa)
{
    if(size != pa.size)
    {
        std::cerr << "Invalid asignation between different sizes arrays!" << std::endl;
        return *this;
    }
    for(int i = 0; i < size; ++i)
        data[i] = pa.data[i];
    return *this;
}

void PointArray::resize(const int nSize)
{
    Point* nData = new Point[nSize];
    int minSize = (nSize > size) ? size : nSize;
    for(int i = 0; i < minSize; ++i)
        nData[i] = data[i];
    delete[] data;
    data = nData;
    size = nSize;
}

std::ostream& operator<<(std::ostream& o, const PointArray& pa)
{
    for(int i = 0; i < pa.size; ++i)
        o << pa.data[i] << ' ';
    return o;
}

int Polygon::instances = 0;

Polygon::Polygon(const Polygon& o)
    : data(o.data) { ++instances; }

Polygon::Polygon(const PointArray& pa)
    : data(pa) { ++instances; }

Polygon::Polygon(const Point* points, const int size)
    : data(points, size) { ++instances; }

Point constructorPoints[4];

Point* updateConstructorPoints(const Point& p1, const Point& p2, const Point& p3, const Point& p4 = Point(0, 0))
{
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

Rectangle::Rectangle(const Point& p1, const Point& p2)
    : Polygon(updateConstructorPoints(p1, Point(p1.getX(), p2.getY()), p2, Point(p2.getX(), p1.getY())), 4) {}

Rectangle::Rectangle(const int v0, const int v1, const int v2, const int v3)
    : Polygon(updateConstructorPoints(Point(v0, v1), Point(v0, v3), Point(v2, v3), Point(v2, v1)), 4) {}

double Rectangle::area() const
{
    int length  = data.get(1)->getY() - data.get(0)->getY();
    int width   = data.get(2)->getX() - data.get(1)->getX();
    return std::abs((double)length * width);
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
 : Polygon(updateConstructorPoints(p1, p2, p3), 3) {}

double Triangle::area() const
{
    int dx01 = data.get(0) ->getX() - data.get(1) ->getX(),
        dx12 = data.get(1) ->getX() - data.get(2) ->getX(),
        dx20 = data.get(2) ->getX() - data.get(0) ->getX();
    
    int dy01 = data.get(0) ->getY() - data.get(1) ->getY(),
        dy12 = data.get(1) ->getY() - data.get(2) ->getY(),
        dy20 = data.get(2) ->getY() - data.get(0) ->getY();

    double  a = std::sqrt(dx01 * dx01 + dy01 * dy01),
            b = std::sqrt(dx12 * dx12 + dy12 * dy12),
            c = std::sqrt(dx20 * dx20 + dy20 * dy20);

    double s = (a + b + c) / 2;

    return std::sqrt(s * (s -a) * (s -b) * (s -c));
}
