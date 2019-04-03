#include <iostream>

int main()
{
    const char* hello = "Hello, World!";
    int n; int counter;
    std::cin >> n;

    std::cout << "For Loop:" << std::endl;
    for(size_t i = 0; i < n; ++i)
        std::cout << hello << std::endl;
    
    std::cout << "While Loop:" << std::endl;
    counter = n;
    while(counter--)
    {
        std::cout << hello << std::endl;
    }

    std::cout << "Do While Loop:" << std::endl;
    counter = n;
    do
    {
        std::cout << hello << std::endl;
    } while (--counter);
    
    return 0;
}
