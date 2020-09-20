#include "triangle.h"


triangle::triangle(int a, int b, int c) {
	A = a;
	B = b;
	C = c;
}

int triangle::Check() {
	if (A + B > C&& A + C > B&& B + C > A)
		return 1;
	return 0;
}

void triangle::P() {
	if (Check() == 1)
		cout << "P = " << A + B + C;
}

void triangle::S() {
	if (Check() == 1) {
		double p = (A + B + C) / 2.0;
		double s = sqrt(p * (p - A) * (p - B) * (p - C));
		cout << "S = " << s;
	}
}
