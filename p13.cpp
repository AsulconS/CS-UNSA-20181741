#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define Array  std::vector
#define String std::string

int carry42(Array<String>& arr, int index)
{
    int accum = 0;
    for(size_t i = 0; i < arr.size(); ++i)
        accum += static_cast<int>(arr[i][index] - '0');
    if(index == 8)
        return accum / 10;
    return carry42(arr, index - 1);
}

int result(Array<String>& arr, int index, int ci, String& c)
{
    int accum = ci;
    for(int i = index; i >= 0; --i)
    {
        for(size_t j = 0; j < arr.size(); ++j)
            accum += static_cast<int>(arr[i][index] - '0');
        c[i + 2] = accum % 10;
        accum /= 10;
    }
    return accum;
}

String suma(Array<String>& arr)
{
    int c42 = carry42(arr, arr[0].size() - 1);
    String sResult(10, '0');
    int carryFinal = result(arr, 7, c42, sResult);
    std::cout << sResult << std::endl;
    char c1 = static_cast<char>(carryFinal / 10) + '0';
    char c2 = static_cast<char>(carryFinal % 10) + '0';
    sResult[0] = c1;
    sResult[1] = c2;
    return sResult;
}

int main()
{
    std::ifstream input;
    input.open("p13i");

    Array<String> arr;

    String placeholder;
    while(!input.eof())
    {
        input >> placeholder;
        arr.push_back(placeholder);
    }
    std::cout << suma(arr) << std::endl;
    return 0;
}
