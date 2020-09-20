#include <iostream>

using namespace std;

int main() {
	int i, a, b, oa, ob, r;
	
	cout << "Enter a = "; cin >> a;
	cout << "Enter b = "; cin >> b;
	oa = a;
	ob = b;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	cout << "(" << oa << "," << ob << ") = " << a;
	return 0;
}