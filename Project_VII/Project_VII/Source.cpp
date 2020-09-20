#include <iostream>
#define MAX 100
using namespace std;

void Input(int a[], int &n) {
	int i;
	cout << "Number of elements in the array: "; cin >> n;
	for (i = 0; i < n; i++) {
		cout << "[" << i << "] = "; cin >> a[i];
	}
}

void Output(int a[], int n) {
	int i;
	cout << "[ ";
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "]" << endl;
}

void bubblesort(int a[], int n) {
	int i, j, temp, count=1;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				cout << count << ": ";
				Output(a, n);
				count++;
			}
		}
	}
}

int main() {
	int a[MAX], n;
	Input(a, n);
	cout << "The original array is: ";
	Output(a, n);
	cout << "Array sorting process: " << endl;
	bubblesort(a, n);
	cout << "\nArray after arrangement: ";
	Output(a, n);
	return 0;
}