#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c = 1;
    while(c < 1000000) {
        a = 1; b = 1;
        while(b < c) {
            a = 1;
            while(a < b) {
                if((a * a + b * b) == (c * c)) {
                    cout << a * a << '+' << b * b << '=' << c * c << endl;
                    if((a + b + c) == 1000) {
                        cout << a << ' ' << b << ' ' << c << endl;
                        cout << "And: " << a << " * " << b << " * " << c << " = " << a * b * c << endl;
                        return 0;
                    }
                }
                ++a;
            }
            ++b;
        }
        ++c;
    }
}
