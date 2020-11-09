#ifndef Derived_N3_H
#define Derived_N3_H
#include "Base_N1.h"

class Derived_N3 : public Base_N1
{
public:
	Derived_N3(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};
#endif