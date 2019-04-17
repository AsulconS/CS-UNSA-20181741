#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#define Array  std::vector
#define String std::string

String sum(String& s1, String& s2)
{
    String res;

    int carry = 0;
    int sum;

    int s1Limit = s1.size() - 1;
    int s2Limit = s2.size() - 1;
    int minSize = std::min(s1Limit + 1, s2Limit + 1);
    for(size_t i = 0; i < minSize; ++i)
    {
        sum = carry + s1[s1Limit - i] - '0' + s2[s2Limit - i] - '0';
        res.push_back(static_cast<char>(sum % 10 + '0'));
        carry = sum / 10;
    }

    if(s1Limit > s2Limit)
        for(size_t i = s2.size(); i <= s1Limit; ++i)
        {
            sum = carry + s1[s1Limit - i] - '0';
            res.push_back(static_cast<char>(sum % 10 + '0'));
            carry = sum / 10;
        }
    else if(s2Limit > s1Limit)
        for(size_t i = s1.size(); i <= s2Limit; ++i)
        {
            sum = carry + s2[s2Limit - i] - '0';
            res.push_back(static_cast<char>(sum % 10 + '0'));
            carry = sum / 10;
        }
    else
        if(carry > 0) res.push_back(static_cast<char>(carry + '0'));
    
    std::reverse(res.begin(), res.end());
    
    return res;
}

String arraySum(Array<String>& v)
{
    String res = sum(v[0], v[1]);
    
    int size = v.size();
    for(size_t i = 2; i < size; ++i)
        res = sum(res, v[i]);
    
    return res;
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

    String res = arraySum(arr);

    std::cout << res << std::endl;
    return 0;
}