#include<iostream>
using namespace std;

bool isPow2(int n)
{
    return ((n & (n - 1)) == 0);
}

int main()
{
    int n; cin >> n;
    cout << ((isPow2(n)) ? "YES" : "NO") << endl;
    return 0;
}
