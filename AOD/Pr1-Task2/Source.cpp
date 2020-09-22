#include <iostream>
using namespace std;

void coutp(unsigned int x)
{
    int n = sizeof(int) * 8;
    unsigned maska = (1 << n - 1);
    for (int i = 1; i <= n; i++)
    {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
}

long long Dec2Bin(int X)
{
    long long binaryNumber = 0;
    int p = 0;
    while (X > 0)
    {
        binaryNumber += (X % 2) * pow(10, p);
        ++p;
        X /= 2;
    }
    return binaryNumber;
}

int main() {
    coutp(255);
    return 0;
}