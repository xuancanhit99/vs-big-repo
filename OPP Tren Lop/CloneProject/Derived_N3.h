#ifndef Derived_N3_h
#define Derived_N3_h
#include "Base_N1.h"
class Derived_N3 : public Base_N1 {
public:
	Derived_N3(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};
#endif