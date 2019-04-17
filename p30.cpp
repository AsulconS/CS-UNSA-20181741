#include<iostream>
#include<cmath>
using namespace std;

int nDigits(int n)
{
    int digits = 1;
    int c = 10;
    while((n % c) != n)
    {
        c *= 10;
        ++digits;
    }
    return digits;
}

bool isPowerFive(int n)
{
    int accum = 0, coef;
    int digits = nDigits(n);
    while(digits--)
    {
        coef = pow(10, digits);
        accum += pow((n / coef) % 10, 5);
    }
    return n == accum;
}

int main()
{
    int accum = 0;
    int n = 2;
    while(1)
    {
        if(isPowerFive(n))
        {
            accum += n;
            cout << "Accum is: " << accum << endl;
        }
        ++n;
    }
    return 0;
}
