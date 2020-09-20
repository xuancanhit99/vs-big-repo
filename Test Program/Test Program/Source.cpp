#include <iostream>

using namespace std;

int main() {
	int a, b, c, n;
	cout << "Enter A: "; cin >> a;
	cout << "Enter B: "; cin >> b;
	cout << "Enter C: "; cin >> c;
	if (a <= c) {
		n = (c - a) / b;
		cout << "Maximum number of spinner blades: " << n;
	}
	else
		cout << "Input error! (a <= c)" << endl;
	return 0;
}