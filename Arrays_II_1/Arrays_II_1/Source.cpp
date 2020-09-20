#include <iostream>
#define MAX 100

using namespace std;

void Input(double a[], int &n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i+1 << "] = "; cin >> a[i];
	}
}

void Output(double a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void MaxMinSp1(double a[], int n) {
	double max = a[0], min;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			min = a[i];
			break;
		}
	}
	int imax = 0, imin = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0 && a[i] > max) {
			max = a[i];
			imax = i;
		}
		if (a[i] > 0 && a[i] < min) {
			min = a[i];
			imin = i;
		}
	}
	a[imax] = min;
	a[imin] = max;
}


void Check2(double a[], int n) {
	if (abs(a[4]) < 2)
		cout << "\n\n2. The fifth(a[5]) = " << a[4] << " is modulo less than 2( < 2)" << endl;
	else
		cout << "\n\n2. The fifth(a[5]) = " << a[4] << " is modulo greater than 2( > 2)" << endl;
}


void Bubblesort(double arr[], int n) {
 	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main() {
	int n;
	double a[MAX], b[MAX];
	cout << "Enter the number of elements in the array N = "; cin >> n;
	Input(a, n);
	copy(a, a+MAX, b);
	cout << "\nOriginal array: ";
	Output(a, n);
	MaxMinSp1(b, n);
	cout << "\n\n1. Swap the maximum element and the minimum positive element:" << endl;
	Output(b, n);
	Check2(a, n);
	Bubblesort(a, n);
	cout << "\n3. Rearrange all negative elements to the beginning of the array:" << endl;
	Output(a, n);
	cout << endl;
	return 0;
}