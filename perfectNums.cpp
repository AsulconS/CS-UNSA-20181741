#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect(int n)
{
    int divSum = 1;
    int s = sqrt(n);
    for(int i = 2; i <= s; ++i)
    {
        if(!(n % i))
            divSum += i + n / i;
    }
    return (n == divSum);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; n > 0; ++i)
    {
        if(isPerfect(i))
        {
            cout << i << endl;
            --n;
        }
    }
    return 0;
}
