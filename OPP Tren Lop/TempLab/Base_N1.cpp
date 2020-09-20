#include "Base_N1.h"
#include "Derived_N2.h"
#include "Derived_N3.h"

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

void Base_N1::OutProcess(int times) {
	for (int j = 0; j < times; j++) {
		cout << "    ";
	}
}

int k = 1;
void Base_N1::PrintTree() {
	for (int i = 0; i < ListObj.size(); i++) {
		cout << endl;
		OutProcess(k);
		cout << ListObj[i]->GetName();
		k++;
		ListObj[i]->PrintTree();
	}
	k--;
}

void Base_N1::InOutTree(vector<Base_N1*>& listObj) {
	string nameD, nameP;
	Base_N1* bas1;
	Derived_N2* der2;
	Derived_N3* der3;
	int act, numclass;
	while (1) {
	in:
		cin >> nameP;
		if (nameP == "endtree") break;
		cin >> nameD >> numclass >> act;
		if (nameD == nameP) goto in;
		for (int i = 0; i < listObj.size(); i++) {
			if (listObj[i]->GetName() == nameP) {
				switch (numclass) {
				case 2: {
					der2 = new Derived_N2(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(der2);
					listObj.push_back(der2);
					break;
				}
				case 3: {
					der3 = new Derived_N3(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(der3);
					listObj.push_back(der3);
					break;
				}
				default: {
					bas1 = new Base_N1(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(bas1);
					listObj.push_back(bas1);
					break;
				}
				}
			}
		}
	}
	cout << "Object tree" << endl;
	cout << listObj[0]->GetName();
	listObj[0]->PrintTree();
}