#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int i = 1, aux = 2, d = 1;
    while(d < 500)
    {
        cout << i << ':' << d << endl;
        i += aux++;
        d = 1;
        for(int j = 2; j <= (int)sqrt(i); ++j)
        {
            if(!(i % j)) ++d;
        }
        d *= 2;
    }
    cout << i << endl;
    return 0;
}
