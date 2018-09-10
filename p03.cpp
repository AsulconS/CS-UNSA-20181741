#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull d = 2;
    ull num; cin >> num;
    ull gdiv = d;
    while(num != 1) {
        if(num % d == 0) {
            gdiv = d;
            num /= d;
        } else ++d;
    }
    cout << gdiv << endl;
    return 0;
}
