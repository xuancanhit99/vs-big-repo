#include <iostream>

using namespace std;

bool IsPower2(int n)
{
	while ((0 == n % 2) && n)
		n /= 2;
	return n == 1;
}


int main() {

	int N;
	cout << "Enter N = "; cin >> N;
	if (N <= 0)
		cout << "1. " << N << " is a non-positive number(<=0) " << endl;
	if (N % 2 != 0)
		cout << "2. " << N << " is an odd number(%2 != 0)" << endl;
	if (N > -3)
		cout << "3. " << N << " is greater than -3(>-3)" << endl;
	if (IsPower2(N) == 1)
		cout << "4. " << N << " is a power of two(=2^x)" << endl;
	return 0;
}
