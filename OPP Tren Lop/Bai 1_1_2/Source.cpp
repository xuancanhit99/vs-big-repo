#include <iostream>

using namespace std;

int Check(double n) {
	if (n < 0)
		return 0;
	if (n - (int)n == 0) {
		return 1;
	}
	return 0;
}

int Sum(double n) {
	double Sum_n = 0;
	for (int i = 1; i <= n; i++) {
		Sum_n += i;
	}
	return Sum_n;
}

int main()
{
	double n;
	cin >> n;
	if (Check(n) == 0 || n == 0) {
		cout << "n is wrong (" << n << ")";
	}
	else
		cout << "Sum_n = " << Sum(n);
	return(0);
}
