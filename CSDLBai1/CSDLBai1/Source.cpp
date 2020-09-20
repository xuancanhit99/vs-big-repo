#include <iostream>


#define MAX 100

using namespace std;


void Output(int a[], int& n) {
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Input(int a[], int& n) {
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        Output(a, i);
    }
}

int main() {
	int n;
	int a[MAX];
    cin >> n;
    if (n > 0 && n < 10) {
        Input(a, n);
    }
    else
        cout << "Invalid value." << endl;
	return 0;
}



