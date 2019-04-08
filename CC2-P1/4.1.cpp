#include<iostream>
using namespace std;

long long accumulator = 1;

int main()
{
    short number;
    cout << "Enter a number: ";
    cin >> number;

    if(number < 0)
    {
        cout << "No negative numbers allowed!\n";
        return -1;
    }
    if(number > 20)
    {
        cout << "Program will not produce correct result!\n";
    }
    for(; number > 0; accumulator *= number--);
    cout << "The factorial of " << number << " is "; // The output is: 1, 1, 2, 362880, 3628800
    cout << accumulator << ".\n";

    return 0;
}
