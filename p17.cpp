#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define Array std::vector
#define String std::string

typedef unsigned long long ull;

Array<int> baseNumbers;
Array<int> con1Numbers;
Array<int> con2Numbers;

int main()
{
    baseNumbers.push_back(0);
    con1Numbers.push_back(0);
    con1Numbers.push_back(0);

    std::ifstream input;
    input.open("numbers");

    String placeholder;
    for(size_t i = 1; i < 20; ++i)
    {
        input >> placeholder;
        baseNumbers.push_back(placeholder.size());
    }
    for(size_t i = 20; i < 28; ++i)
    {
        input >> placeholder;
        con1Numbers.push_back(placeholder.size());
    }
    for(size_t i = 28; i < 30; ++i)
    {
        input >> placeholder;
        con2Numbers.push_back(placeholder.size());
    }

    ull sum = 0;
    ull bnum = 0;
    ull cnum = 0;
    ull dnum = 0;

    // Base Numbers Sum from 1 to 20
    for(size_t i = 1; i < 20; ++i)
        bnum += baseNumbers[i];
    sum += bnum;

    for(size_t i = 20; i < 100; ++i)
        cnum += con1Numbers[i / 10] + baseNumbers[i % 10];
    sum += cnum;

    for(size_t i = 100; i < 1000; ++i)
    {
        if(!(i % 100))
        {
            dnum += (baseNumbers[i / 100] + con2Numbers[0]);
            dnum += 19 * (baseNumbers[i / 100] + con2Numbers[0]) + 19 * 3 + bnum;
            i += 19;
            continue;
        }
        dnum += (baseNumbers[i / 100] + con2Numbers[0]) + 3 + con1Numbers[(i / 10) % 10] + baseNumbers[i % 10];
    }
    sum += dnum;

    sum += baseNumbers[1] + con2Numbers[1];
    std::cout << sum << std::endl;
    return 0;
}
