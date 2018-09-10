#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

bool isPrime(ull num) {
    ull d = 2;
    while(d < num) {
        if(num % d == 0) return false;
        else ++d;
    }
    return true;
}

int main() {
    ull num; cin >> num;
    ull accum = 0;
    for(ull i = 2; i < num; ++i) {
        if(isPrime(i)) accum += i;
    }
    cout << accum << endl;
    return 0;
}
