#include <vector>
#include <iostream>

#define Array std::vector

void mult(Array<int>& v, int x)
{
    int carry = 0;
    int result;

    int size = v.size();
    for(size_t i = 0; i < size; ++i)
    {
        int result = carry + v[i] * x;

        v[i] = result % 10;
        carry = result / 10;
    }
    while(carry != 0)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }
}

int sumFac(int n)
{
    Array<int> v;
    v.push_back(1);

    for(size_t i = 1; i <= n; ++i)
        mult(v, i);
    
    int sum = 0;
    int size = v.size();
    for(size_t i = 0; i < size; ++i)
        sum += v[i];
    
    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << sumFac(n) << std::endl;
    return 0;
}
