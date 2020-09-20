#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Cl_N1 {
protected:
	string NAME;
	int NUMBER;
public:
	Cl_N1(string, int);
	int Exp(int numclass) {
		return pow(NUMBER, numclass);
	};
	void Output() {
		for (int i = 1; i <= 4; i++) {
			if (i == 4)
				cout << NAME << "_" << i << " " << Exp(i);
			else
				cout << NAME << "_" << i << " " << Exp(i) << endl;
		}
	}
};

class Cl_N2 : public Cl_N1 {
protected:
	string NAME;
	int NUMBER;
public:
	Cl_N2(string name, int number) : Cl_N1(name, number) {}
};

class Cl_N3 : public Cl_N2 {
protected:
	string NAME;
	int NUMBER;
public:
	Cl_N3(string name, int number) : Cl_N2(name, number) {}
};

class Cl_N4 : public Cl_N3 {
protected:
	string NAME;
	int NUMBER;
public:
	Cl_N4(string name, int number) : Cl_N3(name, number) {}
};



Cl_N1::Cl_N1(string name, int number) {
	NAME = name;
	NUMBER = number;
}

int main() {
	string name;
	int a;
	cin >> name >> a;
	Cl_N4 cl4(name, a);
	cl4.Output();
	return 0;
}