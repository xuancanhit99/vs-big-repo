#ifndef Derived2_h
#define Derived2_h
#include "Base.h"

class Derived2 :public Base {
	string NAME;
	Base* PARENT;
public:
	Derived2(string name, Base* parent) : Base(name, parent) {}
};
#endif