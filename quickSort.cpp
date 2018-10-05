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
int partition(T* data, int low, int high)
{
    T pivot = *(data + high);
    int i = low - 1;
    for(int j = low; j <= high - 1; ++j)
    {
        if(*(data + j) <= pivot)
        {
            ++i;
            swapByPtr(data + j, data + i);
        }
    }
    swapByPtr(data + high, data + i + 1);
    return i + 1;
}

template<typename T>
void quickSort(T* data, int low, int high)
{
    if(low < high)
    {
        int partI = partition<T>(data, low, high);
        quickSort<T>(data, low, partI - 1);
        quickSort<T>(data, partI + 1, high);
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
    // Sorting Arrays
    quickSort<int>(a, 0, na - 1);
    quickSort<char>(b, 0, nb - 1);
    // Printing the sorted arrays
    cout << "Sorted ";
    printArray<int>(a, na);
    cout << "Sorted ";
    printArray<char>(b, nb);
    delete[] a;
    delete[] b;
    return 0;
}
