#include<iostream>

using namespace std;

bool isPrime(int x) {
    int divs = 1;
    for(int i = 2; i <= x; ++i) {
        if(x % i == 0) ++divs;
    }
    return divs == 2;
}

int main() {
    int n;
    cin >> n; --n;
    cout << 1 << endl;
    for(int i = 2; n > 0; ++i) {
        if(isPrime(i)) {
            cout << i << endl; --n;
        }
    }
    return 0;
}
