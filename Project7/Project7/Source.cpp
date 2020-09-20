#include <iostream>
#include <cstring>
#include <stdlib.h>
#define MAX 100

using namespace std;




void Input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}



void Checkint(int a[], int n) {
	int temp = a[0];
	int phantu = 0;
	int sochuoi = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < temp) {
			
			phantu++;
			temp = a[i];
		}
		else
		{
			if (phantu >= 1)
				sochuoi += 1;
			temp = a[i];
		}
	}
	cout << sochuoi;
}

int main() {
	int a[MAX];
	int n;

	cout << "So luong phan tu: "; cin >> n;
	Input(a, n);

	Checkint(a, n);
	return 0;
}



