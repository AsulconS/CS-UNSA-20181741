// The Tortoise and the Hare
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void moveTortoise(int* tortoisePtr, int mt)
{
    if(mt <= 5)
        *tortoisePtr += 3;
    else if(mt <= 7)
        *tortoisePtr -= 6;
    else
        *tortoisePtr += 1;
    
    if(*tortoisePtr < 1)
        *tortoisePtr = 1;
}

void moveHare(int* harePtr, int mt)
{
    if(mt <= 2)
        *harePtr += 0;
    else if(mt <= 4)
        *harePtr += 9;
    else if(mt <= 5)
        *harePtr -= 12;
    else if(mt <= 8)
        *harePtr += 1;
    else
        *harePtr -= 2;
    
    if(*harePtr < 1)
        *harePtr = 1;
}
    
void printPositions(int* tortoisePtr, int* harePtr)
{
    if(*tortoisePtr == *harePtr)
        cout << "OUCH!!!    " << *tortoisePtr
        << "\t\t" << *harePtr << endl;
    else
        cout << "           " << *tortoisePtr
        << "\t\t" << *harePtr << endl;
}

int main()
{
    int tortoise = 1;
    int hare = 1;
    int rnd;
    srand(time(0));
    cout << "\n\t\tBANG!!!\n" << "            "
    << "AND THEY'RE OFF!!!\n" << endl;
    cout << "\tTortoise" << "\tHare" << endl;
    while(tortoise < 70 && hare < 70)
    {
        rnd = 1 + rand() % 10; 
        moveTortoise(&tortoise, rnd);
        moveHare(&hare, rnd);
        printPositions(&tortoise, &hare);
    } cout << endl;
    if(tortoise >= hare)
        cout << "\t TORTOISE WINS!!! YAY!!! " << endl;
    else
        cout << "\tLa Hare wins" << endl;

    return 0;
}
