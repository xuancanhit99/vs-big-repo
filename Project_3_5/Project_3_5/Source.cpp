#include <iostream>
#include <cstring>
#include <stdlib.h>
#define MAX 100

using namespace std;

void sapxep (char a[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void in(char a[] ,int n) {
	int i;
	for (i = 0; i <= n-1; i++) {
		cout << a[i] << " ";
	}
}


void inn(double a[], int n) {
	int i;
	for (i = 0; i <= n - 1; i++) {
		cout << a[i] << " ";
	}
}

void chartodouble(char a[], double b[], int n) {
	int i;
	for (i = 0; i <= n-1; i++) {
		b[i] = (double)a[i];
	}
}

void doubletochar(double b[], char a[], int n) {
	int i;
	for (i = 0; i <= n - 1; i++) {
		a[i] = (char)b[i];
	}
}


void sx(double a[], int n) {
	int i;
	for (i = 0; i <= n - 1; i++) {
		if (a[i] >= 65 && a[i] <= 90) {
			a[i] += 31.5;
		}
	}
}

void xs(double a[], int n) {
	int i;
	for (i = 0; i <= n - 1; i++) {
		if (a[i]!=(int)a[i]) {
			a[i] -= 31.5;
		}
	}
}


void sapxepc(double a[], int n) {
	int i, j;
	double temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main() {
	char a[MAX];
	double b[MAX];
	int len;
	cout << "Enter string: ";
	cin.getline(a, 30);
	len=strlen(a);
	sapxep(a,len);
	chartodouble(a, b, len);
	sx(b, len);
	sapxepc(b, len);
	xs(b, len);
	doubletochar(b, a, len);
	in(a, len);
	return 0;
}



