#include <iostream>
#define MAX 100
using namespace std;

void Output(int a[], int& n) {
	for (int i = 1; i <= n; i++) {
		if (i == n)
			cout << a[i];
		else
			cout << a[i] << " ";
	}
}

void Input(int a[], int& n) {
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		Output(a, i);
		if (i != n)
			cout << endl;
	}
}

int main()
{
	int n;
	int a[MAX];
	cin >> n;
	if (n > 0 && n < 10) {
		Input(a, n);
	}
	else
		cout << "N is wrong: " << n;
	return(0);
}
