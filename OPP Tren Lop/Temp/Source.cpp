#include <iostream> 
#include <string> 
#include <map>
#include <vector>

using namespace std;

class Base_N1
{
public:

	vector<Base_N1*> listChild;
	Base_N1(){}
	Base_N1(string _name, Base_N1* _parent, int _isReady);
	string getName();
	void setName(string _name);
	int getReady();
	void output();
	void TheFirstChild(string first, string second, int _isReady, int numclass);
	void FindObjAndAddTree(string first, string second, int _isReady, int numclass);
	~Base_N1();
protected:
	string name;
	Base_N1* parent;
	int isReady;
};


class Derived_N2 : public Base_N1
{
public:
	Derived_N2(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};

class Derived_N3 : public Base_N1
{
public:
	Derived_N3(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};


class Derived_N4 : public Base_N1
{
public:
	Derived_N4(string _name, Base_N1* _parent, int _isReady) : Base_N1(_name, _parent, _isReady) {}
};



Base_N1::Base_N1(string _name, Base_N1* _parent, int _isReady)
{
	name = _name;
	parent = _parent;
	isReady = _isReady;
}

string Base_N1::getName()
{
	return name;
}

void Base_N1::setName(string _name)
{
	name = _name;
}

int Base_N1::getReady()
{
	return isReady;
}

void Base_N1::output()
{
	for (int i = 0; i < listChild.size(); i++)
	{
		if (listChild[i]->getReady() > 0)
		{
			cout << endl << "The object " << listChild[i]->getName() << " is ready";
			listChild[i]->output();
		}
		else if (listChild[i]->getReady() <= 0)
		{
			cout << endl << "The object " << listChild[i]->getName() << " is not ready";
			listChild[i]->output();
		}
	}
}

Base_N1::~Base_N1()
{
	delete parent;
	listChild.clear();
}

void Base_N1::TheFirstChild(string first, string second, int _isReady, int numclass) {
	Base_N1* der;
	if (numclass == 2)
		der = new Derived_N2(second, this, _isReady);
	else if (numclass == 3)
		der = new Derived_N3(second, this, _isReady);
	else if (numclass == 4)
		der = new Derived_N4(second, this, _isReady);
	this->listChild.push_back(der);

}


void Base_N1::FindObjAndAddTree(string first, string second, int _isReady, int numclass) {
	Base_N1* der;
	for (int i = 0; i < listChild.size(); i++) {
		if (first == listChild[i]->getName()) {
			if (numclass == 2)
				der = new Derived_N2(second, listChild[i], _isReady);
			else if (numclass == 3)
				der = new Derived_N3(second, listChild[i], _isReady);
			else if (numclass == 4)
				der = new Derived_N4(second, listChild[i], _isReady);
			listChild[i]->listChild.push_back(der);
		}
		listChild[i]->FindObjAndAddTree(first, second, _isReady, numclass);
	}
}


int main()
{
	Base_N1 
	string first, second;
	string r; cin >> r;
	Base_N1* root = new Base_N1(r, 0, 1);
	int _isReady, numclass;
	while (1)
	{
	in:
		cin >> first;
		if (first == "endtree")
			break;
		cin >> second >> numclass >> _isReady;
		if (second == first) goto in;
		if (first == r)
			root->TheFirstChild(first, second, _isReady, numclass);
		else
			root->FindObjAndAddTree(first, second, _isReady, numclass);

	}
	cout << "Test result" << endl;
	cout << "The object " << root->getName() << " is ready";
	root->output();
	return 0;
}