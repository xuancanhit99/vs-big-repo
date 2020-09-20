#include <iostream>
#include <iomanip>
#define w1 14
#define w2 8

using namespace std;


int main() {
	double x, y, i;

	cout << setw(w2) << "x" << setw(w1) << "y" << endl;
	cout << "--------------------------" << endl;
	for (i = -4; i <= 4; i = i + 0.5) {
		x = i;
		y = (x * x - 2 * x + 2) / (x - 1);
		cout << setw(w2) << x << setw(w1) << y << endl;
	}
	return 0;
}