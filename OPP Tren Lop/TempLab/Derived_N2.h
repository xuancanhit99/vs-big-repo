#ifndef Derived_N2_H
#define Derived_N2_H
#include "Base_N1.h"

class Derived_N2 : public Base_N1
{
public:
	Derived_N2(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};
#endif