#include<iostream>

double sum(const double x, const double y)
{
    return x + y;
}

int sum(const int x, const int y, const int z = 0, const int w = 0)
{
    return x + y + z + w;
}

int main()
{
    std::cout << sum(1.0, 2.0) << std::endl;
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1, 2, 3) << std::endl;
    std::cout << sum(1, 2, 3, 4) << std::endl;
    return 0;
}
