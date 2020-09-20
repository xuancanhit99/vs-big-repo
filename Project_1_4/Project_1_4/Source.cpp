#include <iostream>

using namespace std;

int main()
{
	double a, b, c, x, x1, x2, y;
	cout << "The quadratic equation 2: ax^2 + bx + c = 0" << endl << "Input a b c = ";
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				cout << "Innumerable roots" << endl;
			else {
				cout << "Non root" << endl;
			}
		}
		else {
			x = -c / b;
			cout << "One root: x =" << x << endl;
		}
	}
	else {
		y = b * b - 4 * a * c;
		if (y < 0)
			cout << "Non root" << endl;
		else if (y == 0) {
			x = -b / (2 * a);
			cout << "Double roots: x1 = x2 = " << x << endl;
		}
		else {
			x1 = (-b - sqrt(y)) / (2 * a);
			x2 = (-b + sqrt(y)) / (2 * a);
			cout << "Two roots:" << endl << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
	}
	return 0;
}
