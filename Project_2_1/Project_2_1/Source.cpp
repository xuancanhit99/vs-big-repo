#include <iostream>
#define PI 3.14159
using namespace std;


int main() {
	double h, r1, r2, l, v, s;
	cout << "Input h R r: ";
	cin >> h >> r1 >> r2;
	l = sqrt(pow(r1 - r2, 2) + h * h);
	v = (PI * h * (r1 * r1 + r1 * r2 + r2 * r2)) / 3;
	s = PI * (r1 * r1 + (r1 + r2) * l + r2 * r2);
	cout << "S = " << s << endl << "V = " << v << endl;
	return 0;
}