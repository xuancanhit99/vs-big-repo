#include <iostream>
#include <iomanip>
#define MAX 35
using namespace std;


void InputMatrix(double a[][MAX], int x, int y) {
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			cout << "[" << i + 1 << ","<< j + 1 << "] = "; cin >> a[i][j];
		}
	}
}


void OutputMatrix(double a[][MAX], int x, int y) {
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void NhanMatrix(double a[][MAX], double b[][MAX], double c[][MAX], int x, int y, int z) {
	int i, j, k;
	double sum;
	for (i = 0; i < x; i++) {
		for (j = 0; j < z; j++) {
			sum = 0;
			for (k = 0; k < y; k++) {
				sum = sum + a[i][k] * b[k][j];
			}
			c[i][j] = sum;
		}
	}
}

void MaxMinA(double a[][MAX], int x, int y) {
	double max = a[0][0];
	double min = a[0][0];
	int i, j, m=0, n=0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (j == 0) {
				if (a[i][j] > max) {
					max = a[i][j];
					m = i;
				}
				if (a[i][j] < min) {
					min = a[i][j];
					n = i;
				}
			}
		}
	}
	cout << "1." << endl;
	cout <<"The seller - prodavets " << m + 1 << " earned the most money = " << max << endl;
	cout << "The seller - prodavets " << n + 1 << " earned the least money = " << min << endl;
	cout << endl;
}

void MaxMinB(double a[][MAX], int x, int y) {
	double max = a[0][1];
	double min = a[0][1];
	int i, j, m=0, n=0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (j == 1) {
				if (a[i][j] > max) {
					max = a[i][j];
					m = i;
				}
				if (a[i][j] < min) {
					min = a[i][j];
					n = i;
				}
			}
		}
	}
	cout << "The seller - prodavets " << m + 1 << " gets the most commissions = " << max << endl;
	cout << "The seller - prodavets " << n + 1 << " gets the least commissions = " << min << endl;
}

void SumA(double a[][MAX], int x, int y) {
	double s = 0;
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (j == 0) {
				s += a[i][j];
			}
		}
	}
	cout << "Total money earned S1 = " << s << endl;
}


void SumB(double a[][MAX], int x, int y) {
	double s = 0;
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (j == 1) {
				s += a[i][j];
			}
		}
	}
	cout << "Total money commission S2 = " << s << endl;
}


void SumC(double a[][MAX], int x, int y) {
	double s = 0;
	int i, j;
	for (i = 0; i < x; i++) {
		double h = 2 * a[i][0];
		for (j = 0; j < y; j++) {
			h -= a[i][j];
		}
		s += h;
	}
	cout << "Total money passed through the hands of sellers S3 = " << s << endl;
}


int main() {
	double a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
	int m=3, n=4, p=2;
	/*cout << "Input m = "; cin >> m;
	cout << "Input n = "; cin >> n;
	cout << "Input p = "; cin >> p;*/
	cout << "Enter Matrix A:" << endl;
	InputMatrix(a, m, n);
	cout << "Enter Matrix B:" << endl;
	InputMatrix(b, n, p);
	NhanMatrix(a, b, c, m, n, p);
	cout << "Matrix A:" << endl;
	OutputMatrix(a, m, n);
	cout << "Matrix B:" << endl;
	OutputMatrix(b, n, p);
	cout << "C = A x B " << endl;
	OutputMatrix(c, m, p);
	MaxMinA(c, m, p);
	MaxMinB(c, m, p);
	SumA(c, m, p);
	SumB(c, m, p);
	SumC(c, m, p);
	return 0;
}