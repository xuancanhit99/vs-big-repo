#include <iostream>

using namespace std;


class Base {
public:
	virtual void Show();
};

class Derived : public Base {
	void Show() {
		cout << "This is derived class";
	}
};


class Derived2 : public Base {
	void Show() {
		cout << "\n This is derived2 class";
	}
};

void Base::Show() {
	cout << "\n This is base class";
}

int main() {
	Base* b;
	Derived d;
	Derived2 d2;
	b = &d2;
	b->Show();
	system("pause");
	return 0;
}