#include <iostream>

using namespace std;


class Base { // Abstract class - lop truu tuong
public:
	//Pure virtual function
	virtual void Show() = 0 {
		cout << "\n This is base class";
	}
};

class Derived1 : public Base {
	void Show() {
		Base::Show();
		cout << "\n This is derived1 class";
	}
};


class Derived2 : public Base {
	void Show() {
		cout << "\n This is derived2 class";
	}
};

int main() {
	// ky thuat upcasting 
	Base* b;
	//khong the t?o object tu abstract class
	//Base a;
	Derived1 d1;
	b = &d1;
	b->Show();
	system("pause");
	return 0;
}