#include<iostream>
#define MAX 100
using namespace std;

int n;
int Bool[MAX] = { 0 };	
int A[MAX];
int c = 0;

void Check() {
	for (int i = 1; i <= n; i++) {
		if (A[i] == i) {
			c++;
			break;
		}
	}
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		if (!Bool[i]) {
			A[k] = i;
			Bool[i] = 1;
			if (k == n)
				Check();
			else
				Try(k + 1);
			Bool[i] = 0;
		}
	}
}

int main() {
	cout << "Number of balls N = ";	cin >> n;
	Try(1);
	cout << "Total situations = " << c << endl;
}