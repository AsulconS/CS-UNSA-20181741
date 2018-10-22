#include <iostream>
using namespace std;

void swapByPtr(int* d1, int* d2)
{
    int t = *d1;
    *d1 = *d2;
    *d2 = t;
}

int partitionPos(int* data, int low, int high)
{
    int pivot = *(data + high);
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

int partitionNeg(int* data, int low, int high)
{
    int pivot = *(data + high);
    int i = low - 1;
    for(int j = low; j <= high - 1; ++j)
    {
        if(*(data + j) >= pivot)
        {
            ++i;
            swapByPtr(data + j, data + i);
        }
    }
    swapByPtr(data + high, data + i + 1);
    return i + 1;
}

void quickSort(int* data, int low, int high, int (*comp)(int*, int, int))
{
    if(low < high)
    {
        int partI = comp(data, low, high);
        quickSort(data, low, partI - 1, comp);
        quickSort(data, partI + 1, high, comp);
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
    // Printing the arrays
    printArray<int>(a, na);
    // Sorting Arrays
    int (*comp)(int*, int, int);
    comp = &partitionPos;
    quickSort(a, 0, na - 1, comp);
    comp = &partitionNeg;
    quickSort(a, 0, na - 1, comp);
    // Printing the sorted arrays
    cout << "Sorted ";
    printArray<int>(a, na);
    delete[] a;
    return 0;
}
