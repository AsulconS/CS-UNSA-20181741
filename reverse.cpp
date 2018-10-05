#include <iostream>
using namespace std;

template<typename T>
void swapByPtr(T* d1, T* d2)
{
    T t = *d1;
    *d1 = *d2;
    *d2 = t;
}

template<typename T>
void reverse(T* data, int size)
{
    int m = (--size) / 2;
    int i = 0;
    while(i <= m)
    {
        swapByPtr<T>(data + i, data + size - i);
        ++i;
    }
}

template<typename T>
void printArray(T* data, int size)
{
    cout << "Elements are: ";
    for(int i = 0; i < size; ++i)
        cout << *(data + i) << ' ';
    cout << endl;
}

int main()
{
    // Taking the first Array
    cout << "Integer Array:\nSize: ";
    int na; cin >> na;
    int* a = new int[na];
    cout << "Data: ";
    for(int i = 0; i < na; ++i)
        cin >> *(a + i);
    cout << endl;
    // Taking the second Array
    cout << "Char Array\nSize: ";
    int nb; cin >> nb;
    char* b = new char[nb];
    cout << "Data: ";
    for(int i = 0; i < nb; ++i)
        cin >> *(b + i);
    cout << endl;
    // Printing the arrays
    printArray<int>(a, na);
    printArray<char>(b, nb);
    // Reversing Arrays
    reverse<int>(a, na);
    reverse<char>(b, nb);
    // Printing the reversed arrays
    cout << "Reversed ";
    printArray<int>(a, na);
    cout << "Reversed ";
    printArray<char>(b, nb);
    delete[] a;
    delete[] b;
    return 0;
}
