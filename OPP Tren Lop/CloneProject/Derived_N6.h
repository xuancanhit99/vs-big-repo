#ifndef Derived_N6_h
#define Derived_N6_h
#include "Base_N1.h"
class Derived_N6 : public Base_N1 {
public:
	Derived_N6(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};
#endif