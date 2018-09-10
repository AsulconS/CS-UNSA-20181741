#include<iostream>
using namespace std;

bool isEvenlyDivide(int n, int d, int l) {
    --d;
    while(++d <= l) {
        if(n % d) return false;
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;
    int n = a - 1;
    while(!isEvenlyDivide(++n, a, b));
    cout << n << endl;
}
