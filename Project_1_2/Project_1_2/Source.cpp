#include <iostream>

using namespace std;

int main()
{
	float a, b;
	cout << "Input a = ";
	cin >> a;
	cout << "Input b = ";
	cin >> b;
	if (b != 0) {
		cout << "a + b = " << a + b << endl;
		cout << "a - b = " << a - b << endl;
		cout << "a x b = " << a * b << endl;
		cout << "a : b = " << a / b << endl;
	}
	else {
		cout << "a + b = " << a + b << endl;
		cout << "a - b = " << a - b << endl;
		cout << "a x b = " << a * b << endl;
		cout << "a : b, Impossible to divide by 0" << endl;
	}


	return 0;
}
