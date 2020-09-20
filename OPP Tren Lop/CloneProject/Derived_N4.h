#ifndef Derived_N4_h
#define Derived_N4_h
#include "Base_N1.h"
class Derived_N4 : public Base_N1 {
public:
	Derived_N4(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};
#endif