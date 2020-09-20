#include <iostream>

#define PI 3.14159

using namespace std;

int main() {
	//setlocale(LC_ALL, "Russian");
	int k;
	char h;
	while (1) {
		cout << "1.Area of Rectangle(Pryamougol-nik)" << endl << "2.Area of Triangle(Treugol-nik)" << endl << "3.Area of Circle(Krug)" << endl << "Please choose: ";
		cin >> k;
		switch (k)
		{
		case 1: {
			double a, b;
			cout << "Enter length a = ";
			cin >> a;
			cout << "Enter width b = ";
			cin >> b;
			if (a >= 0 && b >= 0) {
				cout << "Area of Rectangle: S = a . b = " << a * b << endl;
			}
			else
			{
				cout << "Input is false" << endl;
			}
			break;
		}
		case 2: {
			double a, b, c, d, s, x, y, z;
			cout << "Enter edge a = "; cin >> a;
			cout << "Enter edge b = "; cin >> b;
			cout << "Enter edge c = "; cin >> c;
			x = a + b - c;
			y = b + c - a;
			z = a + c - b;
			if (x > 0 && y > 0 && z > 0) {
				d = (a + b + c) / 2;
				s = sqrt(d * (d - a) * (d - b) * (d - c));
				cout << "Area of Triangle: S = sqrt(d*(d-a)*(d-b)*(d-c)) = " << s << endl;
			}
			else
			{
				cout << "Input is false" << endl;
			}
			break;
		}
		case 3: {
			double r;
			cout << "Enter radius r = "; cin >> r;
			if (r >= 0) {
				cout << "Area of Circle: S = PI . r^2 =  " << PI * r * r << endl;
			}
			else
			{
				cout << "Input is false" << endl;
			}
			break;
		}
		default:
			cout << "Input is false" << endl;
			break;
		}
		cout << "\nDo you want to continue(y/n): ";
		cin >> h;
		if (h == 'n')
			break;
	}
	return 0;
}