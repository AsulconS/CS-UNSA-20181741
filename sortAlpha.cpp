#include <iostream>
#include <string>
using namespace std;

template<typename T>
void swapByPtr(T* d1, T* d2)
{ 
    T t = *d1;
    *d1 = *d2;
    *d2 = t;
}

int partition(string* data, int low, int high, int it)
{
    char pivot = (*(data + high))[it];
    int i = low - 1;
    for(int j = low; j <= high - 1; ++j)
    {
        if((*(data + high))[it] <= pivot)
        {
            ++i;
            swapByPtr(data + j, data + i);
        }
    }
    swapByPtr(data + high, data + i + 1);
    return i + 1;
}

void quickSort(string* data, int low, int high, int it)
{
    if(low < high)
    {
        int partI = partition(data, low, high, it);
        quickSort(data, low, partI - 1, it);
        quickSort(data, partI + 1, high, it);
    }
}

template <typename T>
void printArray(const T* data,  const int len)
{
    for(size_t i = 0; i < len; ++i)
        cout << data[i] << endl;
}

void sortAlpha(string* cads, const int len)
{
    for(size_t i = 0; i < len; ++i)
        quickSort(cads, 0, len, i);
}

int main()
{
    int n; cin >> n;
    string* cads = new string[n];
    for(size_t i = 0; i < n; ++i)
        cin >> cads[i];
    sortAlpha(cads, n);
    printArray<string>(cads, n);
    delete[] cads;
    return 0;
}

