#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int a[x][y], b[y][z], c[x][y];
    cout << endl << "Input the A Matrix:" << endl;
    // For A Input
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; ++j)
            cin >> a[i][j];
    }
    cout << endl << "Input the B Matrix:" << endl;
    // For B Input
    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < z; ++j)
            cin >> b[i][j];
    }
    cout << endl << "Matrix A:" << endl;
    // Print A
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl << "Matrix B:" << endl;
    // Print B
    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < z; ++j)
            cout << b[i][j] << ' ';
        cout << endl;
    }
    // Mult
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < z; ++j)
        {
            c[i][j] = 0;
            for(int k = 0; k < y; ++k)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    cout << endl << "Matrix C:" << endl;
    // Print C
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < z; ++j)
            cout << c[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
