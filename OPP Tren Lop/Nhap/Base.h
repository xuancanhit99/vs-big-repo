#ifndef Base_h
#define Base_h
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Base {
	string NAME;
	Base* PARENT;
public:
	Base(){}
	vector<Base*> ListObj;
	Base(string name, Base* parent);
	void SetName(string name);
	string GetName();
	void Output();
};
#endif