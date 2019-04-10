#include<iostream>

int sum(int* arr, const int n)
{
    if(n == 1)
        return *arr;
    int half = (n + 1) / 2;
    return sum(arr, half) + sum(arr + half, n - half);
}

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];
    for(size_t i = 0; i < n; ++i)
        std::cin >> arr[i];
    std::cout << sum(arr, n) << std::endl;

    delete[] arr;
    return 0;
}
