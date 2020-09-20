#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

#define MAX 10001

int x = 5, y = 3;


void InputArr(int a[], int& n) {
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "]= ";
		cin >> a[i];
	}
}

void OutPutArr(int a[], int n) {
	cout << endl << "Array:   ";
	for (int i = 0; i < n; i++)
		cout << setw(x) << a[i];
	cout << endl << "Index i =";
	for (int i = 0; i < n; i++)
		cout << setw(y) << "[" << i << "]";
	cout << endl << endl;
}

void Descending(int a[], int n) { //Sorted in increasing order use selection sort
	int tg;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				// Hoan vi 2 so a[i] va a[j]
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}


void Ascending(int a[], int n) { //ascending use insertionSort
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		/* Di chuyển các phần tử có giá trị lớn hơn giá trị
		key về sau một vị trí so với vị trí ban đầu
		của nó */
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void ArrHandling(int a[], int n, int ix, int iy) {
	int tg;
	for (int i = ix; i < iy - 1; i++) {
		for (int j = i + 1; j < iy; j++) {
			if (a[i] > a[j]) {
				// Hoan vi 2 so a[i] va a[j]
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}

void Check3Num(int& a, int& b, int& c) {
	int temp;
	if (a == b || b == c) {
		if (a == b) {
			b = c;
			c = a;
		}
		if (b == c) {
			b = a;
			a = c;
		}
	}
	else {
		if ((a > b) && (b > c)) {
			temp = b;
			b = c;
			c = temp;
		}
		if ((a < b) && (b < c)) {
			temp = b;
			b = c;
			c = temp;
		}
	}
}

void NotPartially(int a[], int n) {
	int i = 0;
	while (i < n - 2) {
		Check3Num(a[i], a[i + 1], a[i + 2]);
		i++;
	}
}

int main() {
	//int a[] = {64, 25, 12, 22, 11};
	//int n = sizeof(a) / sizeof(a[0]);
	int n;
	int a[MAX];
	cout << "Enter n: "; cin >> n;
	int* ap = new int[n];
	if (n < 100) { // для массивом объема: небольшого (<100)
		InputArr(a, n); OutPutArr(a, n);
		while (1) {
			int ch;
			cout << endl << "1. Sorted in increasing order" << endl;
			cout << "2. Sorted in decreasing order" << endl;
			cout << "3. Partially ordered" << endl;
			cout << "4. Not ordered even partially" << endl;
			cout << "Please choose: "; cin >> ch;
			switch (ch) {
			case 1: {
				//1 Упорядоченный по возрастанию
				Ascending(a, n); OutPutArr(a, n);
				break;
			}
			case 2: {
				//2 Упорядоченный по убыванию
				Descending(a, n); OutPutArr(a, n);
				break;
			}
			case 3: {
				//3 Частично упорядоченный
				int ix, iy;
				cout << "Enter the range(i) you want to sort(a to b):" << endl;
				cout << "a = "; cin >> ix; cout << "b = "; cin >> iy;
				ArrHandling(a, n, ix, iy + 1);
				OutPutArr(a, n);
				break;
			}
			case 4: {
				//4 Не упорядоченный  даже частично
				NotPartially(a, n); OutPutArr(a, n);
				break;
			}
			default: {
				cout << "You choose wrong." << endl;
			}
			}
			char r;
			cout << "Do you want continue(y/n): "; cin >> r;
			if (r == 'n')
				break;
		}
	}
	if (n > 100) { // среднего (<10 000); очень большой (>10 000)
		InputArr(ap, n); OutPutArr(ap, n);
		while (1) {
			int ch;
			cout << endl << "1. Sorted in increasing order" << endl;
			cout << "2. Sorted in decreasing order" << endl;
			cout << "3. Partially ordered" << endl;
			cout << "4. Not ordered even partially" << endl;
			cout << "Please choose: "; cin >> ch;
			switch (ch) {
			case 1: {
				//1 Упорядоченный по возрастанию
				Ascending(ap, n); OutPutArr(ap, n);
				break;
			}
			case 2: {
				//2 Упорядоченный по убыванию
				Descending(ap, n); OutPutArr(ap, n);
				break;
			}
			case 3: {
				//3 Частично упорядоченный
				int ix, iy;
				cout << "Enter the range(i) you want to sort(a to b):" << endl;
				cout << "a = "; cin >> ix; cout << "b = "; cin >> iy;
				ArrHandling(ap, n, ix, iy + 1);
				OutPutArr(ap, n);
				break;
			}
			case 4: {
				//4 Не упорядоченный  даже частично
				NotPartially(ap, n); OutPutArr(ap, n);
				break;
			}
			default: {
				cout << "You choose wrong." << endl;
			}
			}
			char r;
			cout << "Do you want continue(y/n): "; cin >> r;
			if (r == 'n')
				break;
		}
	}

	delete[] ap;
	cout << endl; system("Pause");
	return 0;
}