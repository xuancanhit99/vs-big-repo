#include <iostream> 
#include <ctime>

#define MAX 100


using namespace std;


void InputA(int a[][MAX], int &m, int &n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "," << j << "] = "; cin >> a[i][j];
		}
	}
}

void Output(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void ProcessB(int b[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = i * j - (5 - i - j);
		}
	}
}

void ProcessC(int c[][MAX], int m, int n) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j]= -3 + rand() % (10);
		}
	}
}

void ProcessD(int a[][MAX], int b[][MAX], int c[][MAX], int d[][MAX], int e[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 6 * e[i][j] - c[i][j] - 2 * b[i][j] - 3 * a[i][j];
		}
	}
}

void ProcessE(int e[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			e[i][j] = 1;
		}
	}
}



int main() {
	int m, n, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], D[MAX][MAX], E[MAX][MAX];
	cout << "Enter the dimensions(M x N) of the two-dimensional array:" << endl;
	cout << "M N = "; cin >> m >> n;
	InputA(A, m, n);
	ProcessB(B, m, n);
	ProcessC(C, m, n);
	ProcessE(E, m, n);
	ProcessD(A, B, C, D, E, m, n);
	cout << "\n\nArray A: " << endl; Output(A, m, n);
	cout << "\n\nArray B: " << endl; Output(B, m, n);
	cout << "\n\nArray C: " << endl; Output(C, m, n);
	cout << "\n\nArray D: " << endl; Output(D, m, n);
	cout << "\n\nArray E: " << endl; Output(E, m, n);

	return 0;
}