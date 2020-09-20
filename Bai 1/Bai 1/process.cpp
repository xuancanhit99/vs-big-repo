#include"process.h"

int x = 5, y = 3;

//1.1
void InputArr(int a[], int& n) {
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "]= ";
		cin >> a[i];
	}
}

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

void RanArr(int a[], int n) {
	srand((int)time(0));
	for (int i = 0; i < n; i++)
		a[i] = random(1, 100);
}

//1.2
void OutPutArr(int a[], int n) {
	cout << endl << "Array:   ";
	for (int i = 0; i < n; i++) {
		cout << setw(x) << a[i];
	}
	cout << endl << "Index i =";
	for (int i = 0; i < n; i++) {
		cout << setw(y) << "[" << i << "]";
	}
	cout << endl << endl;
}

//1.3
void InsertArr(int a[], int n, int ins, int num_ins) {
	for (int i = n; i >= ins; i--) {
		a[i] = a[i - 1];
	}
	a[ins] = num_ins;
}

//1.4
int LinearS(int a[], int n, int skey) {
	for (int i = 0; i < n; i++) {
		if (a[i] == skey)
			return i;
	}
	return -1;
}

//1.5
int FindI(int a[], int n, int sfirst) {
	for (int i = 0; i < n; i++) {
		if (a[i] == sfirst)
			return i;
	}
	return -1;
}

//1.6
int NumOfOcc(int a[], int n, int stimes) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == stimes)
			count++;
	}
	if (count == 0)
		return -1;
	return count;
}

//1.7
int DeArr(int a[], int c[], int n, int de) {
	int j = 0, f = 0;
	if (de >= 0 && de < n) {
		for (int i = 0; i < n; i++) {
			if (i != de) {
				c[j] = a[i];
				j++;
			}
			else
				f++;
		}
		return j;
	}
	return -1;
}

//1.8
int DeAllArr(int a[], int& n, int num_de) {
	int i, j;
	int count = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == num_de) {
			for (j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			count++;
			n--;
			i--;
		}
	}
	if (count == 0)
		return -1;
}

//1.9 
int BeforeFNum(int a[], int b[], int n, int farr) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < farr) {
			b[j] = a[i];
			j++;
		}
	}
	b[j] = farr; j++;
	return j;
}

int AfterFNum(int a[], int m, int b[], int n, int farr) {
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] > farr) {
			b[n] = a[i];
			n++;
		}
	}
	return n;
}
