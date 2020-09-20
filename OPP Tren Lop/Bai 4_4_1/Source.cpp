#include <iostream>
#include <iomanip>
#define MAX 101
using namespace std;

class base {
protected:
	int A[MAX];
	int N;
public:
	void input(int n);
	virtual void in_out() {}
};

class derived1 : public base {
public:
	int func(int a[], int n);
};

void base::input(int n) {
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		N = n;
}

int derived1::func(int a[], int n) {
	int diff = a[0];
	for (int i = 1; i < n; i++) {
		diff = diff - a[i];
	}
	return diff;
}

class derived2 : public derived1 {
public:
	int func(int a[], int n);
};

int derived2::func(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}	
	return sum;
}

class derived3 : public derived2 {
public:
	void in_out();
};

void derived3::in_out() {
	cout << "Array dimension: " << N << endl;
	cout << "The original array:";
	for (int i = 0; i < N; i++) {
		cout << setw(5) << A[i];
	}
	cout << endl << "Min: " << derived1::func(A, N) << endl;
	cout << "Sum: " << derived2::func(A, N);
}

int main() {
	int n;
	base* de;
	de = new derived3;
	cin >> n;

	de->input(n);
	de->in_out();
	return 0;
}