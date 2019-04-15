#include <vector>
#include <iostream>

typedef unsigned long long ull;

std::vector<bool> naturals;

void showPrimes(ull n)
{
    ull limit = n * n;
    naturals.assign(limit + 1, 1);
    std::cout << 1 << std::endl;
    --n;
    for(ull i = 2; i <= limit, n > 0; ++i)
    {
        if(naturals[i])
        {
            std::cout << i << std::endl; n--;
            for(ull j = i * i; j <= limit; j += i)
                naturals[j] = 0;
        }
    }
}

int main()
{
    ull n; std::cin >> n;
    showPrimes(n);
    return 0;
}
