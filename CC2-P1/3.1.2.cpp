#include <iostream>

int main()
{
    int arg1;
    arg1 = -1;
    {
        char arg1 = 'A';
        std::cout << arg1 << std::endl;
    }
    return 0;
}

// This code will compile because the inner scope is the relevant one inside that scope
