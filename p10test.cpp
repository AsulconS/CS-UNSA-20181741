#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<bool> naturals;
ull accum = 0;

void sumationPrimes(ull n)
{
    naturals.assign(n + 1, 1);
    for(ull i = 2; i <= n; ++i)
    {
        if(naturals[i])
        {
            accum += i;
            cout << accum << endl;
            for(ull j = i * i; j <= n; j += i)
                naturals[j] = 0;
        }
    }
}

int main()
{
    ull n; cin >> n;
    sumationPrimes(n);
    return 0;
}
