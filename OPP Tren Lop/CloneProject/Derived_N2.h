#ifndef Derived_N2_h
#define Derived_N2_h
#include "Base_N1.h"
class Derived_N2 : public Base_N1 {
public:
	Derived_N2(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};
#endif