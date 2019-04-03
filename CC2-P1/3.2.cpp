#include <iostream>

int main()
{
    int n;
    int aux;

    int max, min;

    int sum = 0;
    double mean = 0.0;

    std::cin >> n;
    std::cin >> aux;
    max = aux; min = aux;
    sum += aux;

    int i = n - 1;
    while(i--)
    {
        std::cin >> aux;
        if(aux < min) min = aux;
        if(aux > max) max = aux;
        sum += aux;
        mean = sum / n;
    }

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Range: " << max - min << std::endl;

    return 0;
}
