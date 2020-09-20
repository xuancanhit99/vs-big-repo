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
void InsertArr(int a[], int b[], int n, int ins, int num_ins) {
	for (int i = 0; i < n; i++) {
		if (i >= ins) {
			if (i == ins)
				b[i] = num_ins;
			else
				b[i] = a[i - 1];
		}
		else
			b[i] = a[i];
	}
	b[n] = a[n - 1];
}

//1.4
void LinearS(int a[], int n, int skey) {
	int c[MAX], count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == skey) {
			count++;
			c[count] = i;
		}
	}
	if (count == 0)
		cout << "Value not found." << endl;
	else {
		cout << "Value " << skey << " repeat: " << count << " times, with location:" << endl;
		for (int j = 1; j <= count; j++)
			cout << "i = " << c[j] << endl;
	}
}

//1.5
void FindI(int a[], int n, int sfirst) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == sfirst) {
			count++;
			cout << "Index of the first occurrence i = " << i << endl;
			break;
		}
	}
	if (count == 0)
		cout << "Value not found." << endl;
}

//1.6
void NumOfOcc(int a[], int n, int stimes) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == stimes)
			count++;
	}
	if (count == 0)
		cout << "Value not found." << endl;
	else
		cout << "The number of occurrences: " << count << endl;
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
int DeAllArr(int a[], int c[], int n, int num_de) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != num_de) {
			c[j] = a[i];
			j++;
		}
	}
	return j;
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
