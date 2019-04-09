#include<iostream>

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    int a[x][y], b[y][z], c[x][y];
    std::cout << std::endl << "Input the A Matrix:" << std::endl;
    // For A Input
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; ++j)
            std::cin >> a[i][j];
    }
    std::cout << std::endl << "Input the B Matrix:" << std::endl;
    // For B Input
    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < z; ++j)
            std::cin >> b[i][j];
    }
    std::cout << std::endl << "Matrix A:" << std::endl;
    // Print A
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; ++j)
            std::cout << a[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl << "Matrix B:" << std::endl;
    // Print B
    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < z; ++j)
            std::cout << b[i][j] << ' ';
        std::cout << std::endl;
    }
    // Mult
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < z; ++j)
        {
            c[i][j] = 0;
            for(int k = 0; k < y; ++k)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    std::cout << std::endl << "Matrix C:" << std::endl;
    // Print C
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < z; ++j)
            std::cout << c[i][j] << ' ';
        std::cout << std::endl;
    }
    return 0;
}
