#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int sumSq = 0;
    int sqSum = 0;
    for(int i = 1; i < 101; ++i) {
        sumSq += i * i;
        sqSum += i;
    } sqSum *= sqSum;
    cout << abs(sqSum - sumSq) << endl;
    return 0;
}
