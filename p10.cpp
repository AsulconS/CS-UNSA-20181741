#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

bool isPrime(ull num) {
    if(!(num & 1)) return false;;
    ull d = 3;
    while(d < num) {
        if(num % d == 0) return false;
        else d += 2;
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
