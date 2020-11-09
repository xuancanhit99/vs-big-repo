#ifndef Base_N1_H
#define Base_N1_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base_N1
{
public:
	vector<Base_N1*> listChild;
	Base_N1(string _name, Base_N1* _parent, int _isReady);
	string getName();
	void setName(string _name);
	int getReady();
	void output();

	~Base_N1();
protected:
	string name;
	Base_N1* parent;
	int isReady;
};
#endif