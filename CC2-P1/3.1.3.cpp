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

// This code will use the CHAR arg1 (A)
