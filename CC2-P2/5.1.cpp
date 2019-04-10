#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

double randomizer()
{
    double r = rand() / (double)RAND_MAX;
    return r;
}

double piCalc(const double n)
{
    srand(time(NULL));
    double squareDarts = 0, circleDarts = 0;
    for(size_t i = 0; i < n; ++i)
    {
        double x = randomizer();
        double y = randomizer();
        if(sqrt(x * x + y * y) < 1)
        {   ++circleDarts; ++squareDarts;   }
        else
            ++squareDarts;
    }
    double circArea = 4.0 * circleDarts / squareDarts;
    return circArea;
}

int main()
{
    double x = piCalc(5000000);
    std::cout << x << std::endl;
    return 0;
}
