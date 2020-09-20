#include <iostream>
using namespace std;

class Base { // Abstract class - lop truu tuong
public:
	//huy bo thuong
	//huy bo ao
	/*virtual~Base() {
		cout << "Base Destructor\t";
	}*/

	//huy bo thuan ao 
	virtual ~Base() = 0;
};

Base::~Base() {
	cout << "\n Base Destructor";
}

class Derived1 : public Base {
	~Derived1() {
		cout << "Derived Destructor";
	}
};

int main() {
	Base* b = new Derived1;
	delete b;
	//Base test;
	system("pause");
	return 0;
}