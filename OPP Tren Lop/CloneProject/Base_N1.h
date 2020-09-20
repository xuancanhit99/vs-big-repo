#ifndef Base_N1_h
#define Base_N1_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Base_N1 {
protected:
	string NAME;
	Base_N1* PARENT;
	int ACT;
public:
	vector<Base_N1*> ListObj;
	Base_N1() {}
	Base_N1(string name, Base_N1* parent, int act);
	string GetName();
	int GetAct();
	void Output();
	void Out(int a);
	//add
	string readTree(string s);
	void proCesStr(string s, vector<string>& str, string root);
	void CheckTree(vector<string> str);
};
#endif