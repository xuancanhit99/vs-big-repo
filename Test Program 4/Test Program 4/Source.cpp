#include <iostream>

#define MAX 55

using namespace std;

int j = 1;

void AddTr1(int a[]) {

	for (int i = 0; i < 4; i++) {
		a[i] = j;
		j++;
	}
}

void AddTr2(int a[]) {

	for (int i = 4; i < 6; i++) {
		a[i] = j;
		j++;
	}
}

void Input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = "; cin >> a[i];
	}
}

void Output(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int Cp(int a[], int b[], int n) {
	int Ts = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j]) {
				Ts++;
			}
		}
	}
	//cout << Ts;
	if (Ts == 6)
		return 1;
	else
		return 0;
}


int main() {
	int a1[MAX], a2[MAX], a3[MAX], a4[MAX], a5[MAX],
		a6[MAX], a7[MAX], a8[MAX], a9[MAX];
	AddTr1(a1), AddTr1(a2), AddTr1(a3), AddTr1(a4), AddTr1(a5);
	AddTr1(a6), AddTr1(a7), AddTr1(a8), AddTr1(a9);
	AddTr2(a9), AddTr2(a8), AddTr2(a7), AddTr2(a6), AddTr2(a5);
	AddTr2(a4), AddTr2(a3), AddTr2(a2), AddTr2(a1);
	int n, a[MAX];
	cout << "Enter N: "; cin >> n;
	Input(a, n);
	int SumCp = 0;
	SumCp += Cp(a1, a, n);
	SumCp += Cp(a2, a, n);
	SumCp += Cp(a3, a, n);
	SumCp += Cp(a4, a, n);
	SumCp += Cp(a5, a, n);
	SumCp += Cp(a6, a, n);
	SumCp += Cp(a7, a, n);
	SumCp += Cp(a8, a, n);
	SumCp += Cp(a9, a, n);
	cout << "The train compartment is empty: " << SumCp << endl;
	return 0;
}