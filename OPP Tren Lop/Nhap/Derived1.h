#ifndef Derived1_h
#define Derived1_h
#include "Base.h"

class Derived1 :public Base {
	string NAME;
	Base* PARENT;
public:
	Derived1(string name, Base* parent) : Base(name, parent) {}
};
#endif