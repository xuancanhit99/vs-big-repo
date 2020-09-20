#include "triangle.h"
#include <iostream>
#include <string>
#define MAX 100
using namespace std;

void Triangle::Input() {
	cin >> this->a;
	cin >> this->b;
	cin >> this->c;
}

void Triangle::Output() {
	if (a + b > c&& a + c > b&& b + c > a) {
		double p, s;
		p = (this->a + this->b + this->c) / 2;
		s = sqrt(p * (p - this->a) * (p - this->b) * (this->c));
		cout << "P = " << 2 * p << endl;
		cout << "S = " << s << endl;
	}
	else {
		cout << a << ", " << b << ", " << c << " are not 3 sides of triangle";
	}
	
}


