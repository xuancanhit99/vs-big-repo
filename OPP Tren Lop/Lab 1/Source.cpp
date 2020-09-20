
#include <iostream>
#include <vector>
using namespace std;

class Base_N1 {
protected:
	string NAME;
	Base_N1* PARENT;
	int ACT;
public:
	vector<Base_N1*> ListObj;
	Base_N1(string name, Base_N1* parent, int act);
	string GetName();
	int GetAct();
	void Output();
};


class Derived_N2 :public Base_N1 {
public:
	Derived_N2(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};

class Derived_N3 :public Base_N1 {
public:
	Derived_N3(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};

class Derived_N4 :public Base_N1 {
public:
	Derived_N4(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};


Base_N1::Base_N1(string name, Base_N1* parent, int act) {
	NAME = name;
	PARENT = parent;
	ACT = act;
}


string Base_N1::GetName() {
	return NAME;
}

int Base_N1::GetAct() {
	return ACT;
}

void Base_N1::Output() {
	for (int i = 0; i < ListObj.size(); i++) {
		if (GetAct() <= 0) {
			cout << endl << "The object " << ListObj[i]->GetName() << " is not ready";
			ListObj[i]->Output();
		}
		else if (ListObj[i]->GetAct() > 0) {
			cout << endl << "The object " << ListObj[i]->GetName() << " is ready";
			ListObj[i]->Output();
		}
		else if (ListObj[i]->GetAct() <= 0) {
			cout << endl << "The object " << ListObj[i]->GetName() << " is not ready";
			ListObj[i]->Output();
		}
	}
}

int main() {
	string nameP, nameD;
	cin >> nameP;
	Base_N1 root(nameP, 0, 1);
	vector<Base_N1*> listObj;
	listObj.push_back(&root);
	Derived_N2* der2;
	Derived_N3* der3;
	Derived_N4* der4;
	int act, numclass;
	while (1) {
		in:
		cin >> nameP;
		if (nameP == "endtree") break;
		cin >> nameD >> numclass >> act;
		if (nameD == nameP) goto in;
		for (int i = 0; i < listObj.size(); i++) {
			if (listObj[i]->GetName() == nameP) {
				if (numclass == 2) {
					der2 = new Derived_N2(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(der2);
					listObj.push_back(der2);
				}
				else if (numclass == 3) {
					der3 = new Derived_N3(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(der3);
					listObj.push_back(der3);
				}
				else if (numclass == 4) {
					der4 = new Derived_N4(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(der4);
					listObj.push_back(der4);
				}
			}
		}
	}
	cout << "Test result" << endl;
	cout << "The object " << listObj[0]->GetName() << " is ready";
	listObj[0]->Output();
	return 0;
}