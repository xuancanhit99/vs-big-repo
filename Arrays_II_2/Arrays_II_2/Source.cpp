#include <iostream>
#include <ctime>
#include <random>

#define MAX 100

using namespace std;

void InputA(double a[], int &n) {
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = "; cin >> a[i];
	}
}

void Output(double a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}


void ProcessB(double b[], int n) {
	for (int i = 0; i < n; i++) {
		b[i] = 1 / tan(1 + i * i);
	}
}

double Random(double a, double b) {
	srand(time(0));
	return a + (b - a) * rand() / RAND_MAX;
}

void ProcessC(double c[], int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		c[i] = -11 + (12) * rand() / RAND_MAX;
	}
}

void ProcessD(double a[], double b[], double c[], double d[], int n) {
	for (int i = 0; i < n; i++) {
		d[i] = a[i] - 5 * c[i] + 4 * b[i];
	}
}





int main() {
	double A[MAX], B[MAX], C[MAX], D[MAX];
	int n;
	cout << "Enter the number of elements: N = "; cin >> n;
	InputA(A, n);
	ProcessB(B, n);
	ProcessC(C, n);
	ProcessD(A, B, C, D, n);
	cout << "\n\nArray A: "; Output(A, n);
	cout << "\n\nArray B: "; Output(B, n);
	cout << "\n\nArray C: "; Output(C, n);
	cout << "\n\nArray D: "; Output(D, n);
	cout << endl;
	return 0;
}