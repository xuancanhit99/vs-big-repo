#include <iostream>

using namespace std;

int main() {
	double s, p, n, m, r;
	cout << "Input S p n : ";
	cin >> s >> p >> n;
	r = p / 100;
	m = (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
	cout << "m = " << m << endl;
	return 0;
}