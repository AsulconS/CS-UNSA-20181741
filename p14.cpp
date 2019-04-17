#include <iostream>

typedef unsigned long long ull;

ull chainLength(ull n)
{
    ull counter = 0;
    ull r = n;
    while(r != 1)
    {
        r = (r % 2) ? 3 * r + 1 : r / 2 ;
        ++counter;
    }
    return counter + 1;
}

int main()
{
    ull max = 1;
    for(size_t i = 1; i <= 1000000; ++i)
    {
        std::cout << i << std::endl;
        if(chainLength(i) > chainLength(max)) max = i;
    }
    std::cout << max << std::endl;
    return 0;
}
