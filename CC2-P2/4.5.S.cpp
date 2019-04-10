#include<iostream>

int sum(const int* nums, const int len)
{
    return len == 0 ? 0 : nums[0] + sum(nums + 1, len - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    std::cout << sum(arr, 4);
    return 0;
}
