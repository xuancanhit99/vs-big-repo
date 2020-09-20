#include "Array.h"

void Array::Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << "N = " << N << endl;
}

void Array::Output() {
	for (int i = 0; i < N; i++)
		cout << setw(5) << A[i];
}

void Array::Reverse() {
	int j = 0;
	for (int i = N - 1; i >= 0; i--) {
		B[j] = A[i];
		j++;
	}
	for (int k = 0; k < j; k++)
		cout << setw(5) << B[k];
}