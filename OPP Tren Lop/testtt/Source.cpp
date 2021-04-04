#include <iostream> 
#include <time.h>
using namespace std;


void Input(int a[], int n) {
	cout << "Enter n: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]: "; cin >> a[i];
	}
}

void Output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int Process(int a[], int b[], int n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			b[j] = a[i];
			j++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			b[j] = a[i];
			j++;
		}
	}
	return j;
}

int main()
{
	int n;
	int a[11];
	int b[11];
	n = 10;
	cout << "Input "; Input(a, n);
	Process(a, b, n);
	cout << "Output "; Output(b, n);
	return 0;
}