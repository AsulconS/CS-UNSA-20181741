#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

bool isPrime(ull num) {
    ull d = 3;
    while(d <= sqrt(num)) {
        if(!(num % d)) return false;
        else d += 2;
    }
    return true;
}

int main() {
    ull num; cin >> num;
    ull accum = 2;
    for(ull i = 3; i < num; i += 2) {
        if(isPrime(i)) accum += i;
        cout << accum << endl;
    }
    cout << "Winner:" << accum << endl;
    return 0;
}
