#ifndef Derived_N5_h
#define Derived_N5_h
#include "Base_N1.h"
class Derived_N5 : public Base_N1 {
public:
	Derived_N5(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};
#endif