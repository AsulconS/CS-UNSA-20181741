#include<bits/stdc++.h>
using namespace std;

static const int MAX = 999;

int nDigits(int n) {
    int digits = 1;
    int c = 10;
    while((n % c) != n) {
        c *= 10;
        ++digits;
    }
    return digits;
}

bool isPalindrome(int n) {
    int digits = nDigits(n);
    list<int> n1, n2;
    int d = digits;
    while(d--) {
        n1.push_back((int)(n / pow(10, d)) % 10);
        n2.push_front((int)(n / pow(10, d)) % 10);
    }
    if(n1 == n2) return true;
    return false;
}

int main() {
    int n, may = 0;
    for(int i = MAX; i > 99; --i) {
        for(int j = MAX; j > 99; --j) {
            cout << i << " * " << j << " = " << i * j << endl;
            if(isPalindrome(i * j)) {
                n = i * j;
                if(n > may) may = n;
            }
        }
    }
    cout << "The gratest is: " << may << endl;
    return 0;
}
