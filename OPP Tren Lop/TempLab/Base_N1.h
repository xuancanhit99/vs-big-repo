#ifndef base_n1_h
#define base_n1_h
#include <iostream>
#include <iomanip>
#include <vector>


#define SIGNAL (Base_N1* signal_trans, Base_N1* signal_rec)
#define HENDLER (Base_N1* signaling, string content_trans)
#define OBJECT (vector<Base_N1*> listObj, string signal)

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
	void InOutTree(vector<Base_N1*>& listObj);
	void OutProcess(int times);
	void PrintTree();
};
#endif