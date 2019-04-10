#include<iostream>

int lenOfString(const char *word)
{
    int len = 0;
    while(*(word + len) != '\0') ++len;
    return len;
}

void swapPointers(int** a, int** b)
{
    int* aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    const char* myStr = "Hola";
    std::cout << lenOfString(myStr) << std::endl;

    int x = 5, y = 6;
    int* ptr1 = &x;
    int* ptr2 = &y;
    std::cout << *ptr1 << ' ' << *ptr2 << std::endl;
    swapPointers(&ptr1, &ptr2);
    std::cout << *ptr1 << ' ' << *ptr2 << std::endl;
    return 0;
}
