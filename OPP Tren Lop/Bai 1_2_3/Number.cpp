#include "Number.h"

void Number::Numdig() {
    cin >> n;
    cout << "n = " << n << endl;
    if (n < 0)
        n = n * -1;
    int count = 0;
    while (n >= 10) {
        n /= 10;
        count++;
    }
    cout << "N = " << count + 1;
}