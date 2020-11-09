#include <iostream>
#include <vector>
using namespace std;

class Base_N1 {
protected:
	string name;
	Base_N1* parent;
	int isReady;
public:
	vector<Base_N1*> listChild;
	Base_N1(string _name, Base_N1* _parent, int _isReady);
	string getName();
	void setName(string _name);
	int getReady();
	void output();

	~Base_N1();
};

class Application {
public:
	vector<Base_N1*> listParent;
	void runApp();

	~Application();
};


class Derived_N2 :public Base_N1 {
public:
	Derived_N2(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};

class Derived_N3 :public Base_N1 {
public:
	Derived_N3(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};

class Derived_N4 :public Base_N1 {
public:
	Derived_N4(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};


Base_N1::Base_N1(string _name, Base_N1* _parent, int _isReady) {
	name = _name;
	parent = _parent;
	isReady = _isReady;
}


string Base_N1::getName() {
	return name;
}

void Base_N1::setName(string _name) {
	name = _name;
}

int Base_N1::getReady() {
	return isReady;
}

void Base_N1::output() {
	for (int i = 0; i < listChild.size(); i++) {
		/*if (getReady() <= 0) {
			cout << endl << "The object " << listChild[i]->getName() << " is not ready";
			listChild[i]->output();
		}*/
		//else 
		if (listChild[i]->getReady() > 0) {
			cout << endl << "The object " << listChild[i]->getName() << " is ready";
			listChild[i]->output();
		}
		else if (listChild[i]->getReady() <= 0) {
			cout << endl << "The object " << listChild[i]->getName() << " is not ready";
			listChild[i]->output();
		}
	}
}

Base_N1::~Base_N1() {
	delete parent;
	listChild.clear();
}
void Application::runApp() {
	string nameP, nameD;
	string r; cin >> r;
	Base_N1 root(r, 0, 1);
	vector<Base_N1*> listParent;
	listParent.push_back(&root);
	Derived_N2* der2;
	Derived_N3* der3;
	Derived_N4* der4;
	int _isReady, numclass;
	while (1) {
	in:
		cin >> nameP;
		if (nameP == "endtree") break;
		cin >> nameD >> numclass >> _isReady;
		if (nameD == nameP) goto in;
		for (int i = 0; i < listParent.size(); i++) {
			if (listParent[i]->getName() == nameP) {
				if (numclass == 2) {
					der2 = new Derived_N2(nameD, listParent[i], _isReady);
					listParent[i]->listChild.push_back(der2);
					listParent.push_back(der2);
				}
				else if (numclass == 3) {
					der3 = new Derived_N3(nameD, listParent[i], _isReady);
					listParent[i]->listChild.push_back(der3);
					listParent.push_back(der3);
				}
				else if (numclass == 4) {
					der4 = new Derived_N4(nameD, listParent[i], _isReady);
					listParent[i]->listChild.push_back(der4);
					listParent.push_back(der4);
				}
			}
		}
	}
	cout << "Test result" << endl;
	cout << "The object " << listParent[0]->getName() << " is ready";
	listParent[0]->output();
}

Application::~Application() {
	listParent.clear();
}

int main() {
	Application app;
	app.runApp();
	return 0;
}