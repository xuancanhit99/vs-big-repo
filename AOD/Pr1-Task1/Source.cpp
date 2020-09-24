#include <iostream>
#include <vector>
using namespace std;

//1. Установить 7 бит в 1.
int bit7To1(int x) {
	return x = x | 128; 
}

//2. Установить 5 и 3 биты в 0.
int bit5To0AndBit3To0(int x) {
	return x = x & (~((1 << 5) | (1 << 3)));
}

//3. Инвертировать 5 бит переменной х.
int reverseBit5(int x) {
	return x = x ^ (1 << 5);
}

//4. Даны два целых положительных числа Х и Y одной разрядности.
//Написать выражение, которое вычисляет новое значение Х, где n битов,
//начиная с позиции р, установлены так, как n самых правых битов в Y, а остальные биты не изменились. 

// преобразовать из int в бит
void intToBit(int X, vector<int>& vecX) {
    while (X > 0) {
        vecX.push_back(X % 2);
        X /= 2;
    }
    reverse(vecX.begin(), vecX.end());
}


// преобразовать из бит в int
int BitToInt(vector<int> vecX) {
    reverse(vecX.begin(), vecX.end());
    long long binaryNumber = 0;
    int p = 0;
    for (int i = 0; i < vecX.size(); i++) {
        binaryNumber += vecX[i] * pow(10, p);
        ++p;
    }
    p = 0;
    int decNumber = 0;
    while (binaryNumber > 0) {
        decNumber += (binaryNumber % 10) * pow(2, p);
        ++p;
        binaryNumber /= 10;
    }
    return decNumber;
}

//Copy Bit
int bitProcessing(int X, int Y, int n, int p)
{
    vector<int> vecX, vecY;
    intToBit(X, vecX);
    intToBit(Y, vecY);
    int size = vecY.size();
    for (int i = 0; i < vecX.size(); i++) {
        if (i >= vecX.size() - n) {
            vecX[i] = vecY[size - p - 1];
            size++;
        }
    }
    return BitToInt(vecX);
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
        cout << "4. Given two positive integers X and Y of the same bit width. "<< endl <<
        "   Write an expression that computes the new value of X, where n bits," << endl <<
        "   starting at position p, are set to the rightmost n bits in Y, and the remaining bits are unchanged." << endl;
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
            int X, Y, n, p;
            cout << "Enter X: "; cin >> X;
            cout << "Enter Y: "; cin >> Y;
            cout << "Copy n bit, n: "; cin >> n;
            cout << "Starting at position p: "; cin >> p;
            cout << endl << "The new value of X: " << bitProcessing(X, Y, n, p) << endl;
            break;
        default:
            cout << endl << "You choose wrong, please choose again" << endl;
            goto goagain;
        }
        char choose;
        cout << endl << "Do you want continue(y/n): "; cin >> choose;
        if (choose == 'n' || choose == 'N')
            break;
    }
	return 0;
}