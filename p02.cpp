#include<iostream>
using namespace std;

int fibonacci(int n)
{
    --n;
    int x = 1;
    int y = 1;
    int z = 1;
    while(n--)
    {
        z = x + y;
        x = y;
        y = z;
    }
    return z;
}

int main()
{
    int n;
    cin >> n;
    int accum = 0, i = 1;
    while(fibonacci(i) < n)
    {
        if(!(fibonacci(i) & 1)) // Bitwise operation
            accum += fibonacci(i);
        ++i;
    }
    cout << accum << endl;
    return 0;
}
