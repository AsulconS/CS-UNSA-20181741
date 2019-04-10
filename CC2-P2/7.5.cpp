#include<iostream>

int main() {
    char* oddOrEven = "Never odd or even";
    char* nthCharPointer = &oddOrEven[5];
    nthCharPointer -= 2;
    std::cout << *nthCharPointer << std::endl;
    char** pointerPtr = &nthCharPointer;
    std::cout << pointerPtr << std::endl;
    std::cout << **pointerPtr << std::endl;
    ++nthCharPointer;
    std::cout << nthCharPointer - oddOrEven << std::endl;
    return 0;
}
