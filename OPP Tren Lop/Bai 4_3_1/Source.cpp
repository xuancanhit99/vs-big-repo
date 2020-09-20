//#include "Base.h"
//#include "Derived1.h"
//#include "Derived2.h"
//#include "Derived3.h"

#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;

class Base {
protected:
	int N;
	int Arr[MAX];
};

class Derived1 :public Base {
public:
	int InN();
};

class Derived2 :public Base {
public:
	void Input(int n);
	void Sort(int n);
	void Output(int n);
};

class Derived3 :public Derived1, public Derived2 {
public:
	void InOut();
};

int Derived1::InN() {
	cin >> N;
	return N;
}


void Derived2::Input(int n) {
	for (int i = 0; i < n; i++) {
		cin >> Arr[i];
	}
}


void Derived2::Sort(int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (Arr[j] > Arr[j + 1]) {
				int temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
			}
		}
	}
}


void Derived2::Output(int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(5) << Arr[i];
	}
}


void Derived3::InOut() {
	int n = Derived1::InN();
	Derived2::Input(n);
	cout << "Array dimension: " << n << endl;
	cout << "The original array:";
	Derived2::Output(n); cout << endl;
	Derived2::Sort(n);
	cout << "An ordered array:";
	Derived2::Output(n);
}

int main() {
	Derived3 de;
	de.InOut();
	return 0;
}