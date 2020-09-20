#include <iostream>
#define PI 3.14159
using namespace std;


int main() {
	double x, y, b, z;
	cout << "Input x y b: ";
	cin >> x >> y >> b;
	if (b > y && b >= x) {
		z = log(b - y) * sqrt(b - x);
		cout << "z = " << z << endl;
	}
	else
	{
		cout << "Does not exist the value z" << endl;
	}
	return 0;
}