#include "Array.h"

Array::Array(int n) {
	N = n;
}
void Array::Creat() {
	for (int i = 0; i < N; i++) {
		a[i] = i * i;
	}
}

void Array::Output() {
	for (int i = N - 1; i >= 0; i--)
		cout << setw(5) << a[i];
	delete[] a;
}