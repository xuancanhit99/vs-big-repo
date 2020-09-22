#include <iostream>
using namespace std;

int bit7To1(int x) {
	return x = x | 64; // 128
}

int bit5To0AndBit3To0(int x) {
	return x = x & (~((1 << 4) | (1 << 2)));
}

int reverseBit5(int x) {
	return x = x ^ (1 << 4);
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
    cout << "Task 1: " << endl;
goagain:
    cout << endl;
    while (1) {
        int c, x;
        cout << "1. Set bit 7 to 1." << endl;
        cout << "2. Set bits 5 and 3 to 0." << endl;
        cout << "3. Invert 5 bits of variable x." << endl;
        cout << "4. Print all bits of the value of variable x." << endl;
        cout << "Please choose: "; cin >> c; cout << endl;
        switch (c)
        {
        case 1: 
            cout << "Enter number: "; cin >> x;
            cout << endl << "The new number is: " << bit7To1(x) << endl;
            break;
        case 2:
            cout << "Enter number: "; cin >> x;
            cout << endl << "The new number is: " << bit5To0AndBit3To0(x) << endl;
            break;
        case 3:
            cout << "Enter number: "; cin >> x;
            cout << endl << "The new number is: " << reverseBit5(x) << endl;
            break;
        case 4:
            cout << "Enter number: "; cin >> x;
            cout << endl << "All bits of the value of variable x: " << Dec2Bin(x) << endl;
            break;
        default:
            cout << endl << "You choose wrong, please choose again" << endl;
            goto goagain;
        }
        char choose;
        cout << "Do you want continue(y/n): "; cin >> choose;
        if (choose == 'n' || choose == 'N')
            break;
    }
	return 0;
}