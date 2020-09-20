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
	int NUMCL;
public:
	vector<Base_N1*> ListObj;
	Base_N1() {}
	Base_N1(string name, Base_N1* parent, int numcl, int act);
	string GetName();
	void SetName(string name);
	int GetAct();
	int GetNumCl();
	void Output();
	void Out(int a);
	void FindObj(vector<string>& pathin);
	void proCesStr(string s, vector<string>& str);
	void CheckTree(vector<string> str);
};

class Derived_N2 : public Base_N1 {
public:
	Derived_N2(string name, Base_N1* parent, int numcl, int act) : Base_N1(name, parent, numcl, act) {}
};

class Derived_N3 : public Base_N1 {
public:
	Derived_N3(string name, Base_N1* parent, int numcl, int act) : Base_N1(name, parent, numcl, act) {}
};

class Derived_N4 : public Base_N1 {
public:
	Derived_N4(string name, Base_N1* parent, int numcl, int act) : Base_N1(name, parent, numcl, act) {}
};

class Derived_N5 : public Base_N1 {
public:
	Derived_N5(string name, Base_N1* parent, int numcl, int act) : Base_N1(name, parent, numcl, act) {}
};

class Derived_N6 : public Base_N1 {
public:
	Derived_N6(string name, Base_N1* parent, int numcl, int act) : Base_N1(name, parent, numcl, act) {}
};


class Application : public Base_N1 {
public:
	Application() : Base_N1() {}
	
	void CutVec(vector<string>& pathin, string s);
	void CreObj(vector<Base_N1*>&, string, Base_N1*, int, int);
	void PushTree(vector<Base_N1*>& listObj);
	void CheckObj(vector<Base_N1*> listObj, vector<string>& strList);

	void AllInOne();
};

Base_N1* bas = nullptr;
void Base_N1::FindObj(vector<string>& pathin) {
	for (int i = 0; i < ListObj.size(); i++) {
		if (pathin.size() == 1) {
			break;
		}
		if (ListObj[i]->GetName() == pathin[1]) {
			bas = ListObj[i];
			pathin.erase(pathin.begin() + 1);
			ListObj[i]->FindObj(pathin);
		}
	}
}



Base_N1::Base_N1(string name, Base_N1* parent, int numcl, int act) {
	NAME = name;
	PARENT = parent;
	ACT = act;
	NUMCL = numcl;
}

void Base_N1::SetName(string name) {
	NAME = name;
}

string Base_N1::GetName() {
	return NAME;
}

int Base_N1::GetAct() {
	return ACT;
}

int Base_N1::GetNumCl() {
	return NUMCL;
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

void Base_N1::proCesStr(string s, vector<string>& str) {
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '/' && s[i + 1] == '/')
			str.push_back("_node");
		if (s[i] != '/') {
			temp.push_back(s[i]);
		}
		else if (s[i] == '/' && i != 0 && i != 1) {
			str.push_back(temp);
			temp = "";
		}
	}
	str.push_back(temp);
}


int h = 0;
void Base_N1::CheckTree(vector<string> str) {
	for (int j = 0; j < ListObj.size(); j++) {
		if (str[1] == ListObj[j]->GetName()) {
			str.erase(str.begin() + 1);
			h = str.size();
			if (h == 1)
				break;
			ListObj[j]->CheckTree(str);
		}
	}
}

void Application::CreObj(vector<Base_N1*>& listObj, string nameD, Base_N1* obj, int numcl, int act) {
	Base_N1* base;
	Derived_N2* der2;
	Derived_N3* der3;
	Derived_N4* der4;
	Derived_N5* der5;
	Derived_N6* der6;
	switch (numcl) {
		case 2: {
			der2 = new Derived_N2(nameD, obj, numcl, act);
			obj->ListObj.push_back(der2);
			listObj.push_back(der2);
			break;
		}
		case 3: {
			der3 = new Derived_N3(nameD, obj, numcl, act);
			obj->ListObj.push_back(der3);
			listObj.push_back(der3);
			break;
		}
		case 4: {
			der4 = new Derived_N4(nameD, obj, numcl, act);
			obj->ListObj.push_back(der4);
			listObj.push_back(der4);
			break;
		}
		case 5: {
			der5 = new Derived_N5(nameD, obj, numcl, act);
			obj->ListObj.push_back(der5);
			listObj.push_back(der5);
			break;
		}
		case 6: {
			der6 = new Derived_N6(nameD, obj, numcl, act);
			obj->ListObj.push_back(der6);
			listObj.push_back(der6);
			break;
		}
		default: {
			base = new Base_N1(nameD, obj, numcl, act);
			obj->ListObj.push_back(base);
			listObj.push_back(base);
			break;
		}
	}
}

void Application::CheckObj(vector<Base_N1*> listObj, vector<string>& strList) {
	Base_N1 ba;
	vector<string> str;
	for (int i = 0; i < strList.size(); i++) {
		ba.proCesStr(strList[i], str);
		if (str[0] == "_node") {
			int c = 0;
			for (int k = 0; k < listObj.size(); k++) {
				if (str[1] == listObj[k]->GetName())
					c = 1;
			}
			if (c == 1)
				cout << endl << strList[i] << " " << "Object name: " << str.back();
			else
				cout << endl << strList[i] << " " << "Object not found";
		}
		else {
			if (str.front() == listObj[0]->GetName()) {
				if (str.size() == 1)
					cout << endl << strList[i] << " " << "Object name: " << str.back();
				else {
					listObj[0]->CheckTree(str);
					extern int h;
					if (h == 1) {
						cout << endl << strList[i] << " " << "Object name: " << str.back();
						h = 0;
					}
					else
						cout << endl << strList[i] << " " << "Object not found";
				}
			}
			else
				cout << endl << strList[i] << " " << "Object not found";
		}
		str.clear();
	}
}

void Application::PushTree(vector<Base_N1*>& listObj) {
	string nameP, nameD;
	int act, numcl;
	vector<string> pathin;
	while (1) {
		string s;
		cin >> s;
		if (s == "endtree") break;
		CutVec(pathin, s); // root obj2 obj5
		cin >> nameD >> numcl >> act;
		for (int j = 0; j < pathin.size(); j++) {
			for (int i = 0; i < listObj.size(); i++) {
				if (pathin.size()==1) {
					if (pathin[j] == listObj[i]->GetName()) {
						CreObj(listObj, nameD, listObj[i], numcl, act);
					}
				}
				else {
					listObj[0]->FindObj(pathin);
					CreObj(listObj, nameD, bas, numcl, act);
				}
			}
			pathin.clear();
		}
	}

}

void Application::CutVec(vector<string>& pathin, string s) {
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '/')
			temp.push_back(s[i]);
		else if (s[i] == '/' && i != 0) {
			pathin.push_back(temp);
			temp = "";
		}
	}
	pathin.push_back(temp);
}

void Application::AllInOne() {
	string r;
	cin >> r;
	Base_N1 root(r, 0, 1, 1);
	vector<Base_N1*> listObj;
	listObj.push_back(&root);
	Application app;
	app.PushTree(listObj);
	cout << "Object tree" << endl;
	cout << listObj[0]->GetName();
	listObj[0]->Output();
	//-------------
	int check = 0;
	string coor;
	vector<string> strList;
	while (1) {
		cin >> coor;
		if (coor == "//") break;
		strList.push_back(coor);
	}
	app.CheckObj(listObj, strList);
}

int main() {
	Application app;
	app.AllInOne();
	return 0;
}