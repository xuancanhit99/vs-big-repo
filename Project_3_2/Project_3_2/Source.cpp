#include <iostream>

using namespace std;

int main() {
	double m, m0, s, n, a, p, r;
	int b, i;
	cout << "Input S m n : ";
	cin >> s >> m >> n;
	b = 1;
	for (i = 1; i <= 100000; i++) {
		p = (double)i / 1000;
		r = p / 100;
		a = 1 + r;
		m0 = (s * r * pow(a, n)) / (12 * (pow(a, n) - 1));
		if (m0 > m) {
			break;
		}
	}
	cout << "Percent-Protsent p = " << p << endl;
	return 0;
}