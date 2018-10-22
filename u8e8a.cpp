#include <iostream>
using namespace std;

int main()
{
    const unsigned int SIZE = 5;
    unsigned int values[SIZE];
    for(unsigned int i = 0; i < SIZE; ++i)
        values[i] = (i + 1) * 2;
    for(unsigned int i = 0; i < SIZE; ++i)
        cout << values[i] << endl;
    return 0;
}
