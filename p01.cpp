#include<iostream>
using namespace std;

int main()
{
    int n, accum = 0;
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        if((i % 3 == 0) || (i % 5 == 0))
            accum += i;
    }
    cout << accum << endl;
    return 0;
}
