#include <iostream>

using namespace std;

int main() {
	double x;
	cout << "Enter x = "; cin >> x;
	if (x < 0)
		cout << "y = " << abs(x) + 1 << endl;
	else if (x == 0)
		cout << "y = 1" << endl;
	else
		cout << "y = " << pow(sin(2 * x),2) << endl;
	return 0;
}