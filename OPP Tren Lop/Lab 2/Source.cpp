#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Base_N1 {
protected:
	string NAME;
	Base_N1* PARENT;
	int ACT;
public:
	Base_N1() {}
	vector<Base_N1*> ListObj;
	Base_N1(string name, Base_N1* parent, int act);
	string GetName();
	int GetAct();
	void Output();
	void Out(int a);
};

class Application : public Base_N1 {
public:
	Application() : Base_N1() {}
	void AllInOne();
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

class Derived_N5 :public Base_N1 {
public:
	Derived_N5(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};

class Derived_N6 :public Base_N1 {
public:
	Derived_N6(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
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

void Base_N1::Out(int a) {
	for (int j = 0; j < a; j++) {
		cout << "    ";
	}
}

int k = 1;
void Base_N1::Output() {
	for (int i = 0; i < ListObj.size(); i++) {
		cout << endl;
		Out(k);
		cout << ListObj[i]->GetName();
		k++;
		ListObj[i]->Output();
	}
	k--;
}

void Application::AllInOne() {
	string nameP, nameD;
	cin >> nameP;
	Base_N1 root(nameP, 0, 1);
	vector<Base_N1*> listObj;
	listObj.push_back(&root);
	Derived_N2* der2;
	Derived_N3* der3;
	Derived_N4* der4;
	Derived_N5* der5;
	Derived_N6* der6;
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
				else if (numclass == 5) {
					der5 = new Derived_N5(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(der5);
					listObj.push_back(der5);
				}
				else if (numclass == 6) {
					der6 = new Derived_N6(nameD, listObj[i], act);
					listObj[i]->ListObj.push_back(der6);
					listObj.push_back(der6);
				}
			}
		}
	}
	cout << "Object tree" << endl;
	cout << listObj[0]->GetName();
	listObj[0]->Output();
}

int main() {
	Application app;
	app.AllInOne();
	return 0;
}