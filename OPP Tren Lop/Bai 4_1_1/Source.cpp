#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class Base_N1 {
protected:
	string NAME;
	Base_N1* PARENT;
	int ACT;
public:
	vector<Base_N1*> ListObj;
	Base_N1(){}
	Base_N1(string name, Base_N1* parent, int act);
	string GetName();
	int GetAct();
	void Output();
	void Out(int a);
	//
	string readTree(string s);
	void proCesStr(string s, vector<string>& str, string root);
	//int CheckRoot(vector<Base_N1*> list, string str);
	void CheckTree(vector<string> str);
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




void Base_N1::proCesStr(string s, vector<string> &str, string root) {
	string temp;
	int check = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '/' && s[i + 1] == '/')
			str.push_back(root);
		if (s[i] != '/') {
			temp.push_back(s[i]);
		}
		else if(s[i]=='/' && i!=0 && i!=1) {
			str.push_back(temp);
			temp = "";
		}
	}
	str.push_back(temp);
}


//int Base_N1::CheckRoot(vector<Base_N1*> list, string str) {
//	for (int i = 0; i < list.size(); i++) {
//		if (str == list[i]->GetName()) {
//			return 1;
//		}
//	}
//	return 0;
//}



void outStr(vector<string> str) {
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;
}


int h = 0;
void Base_N1::CheckTree(vector<string> str) {
	for (int i = 1; i < str.size(); i++) {
		for (int j = 0; j < ListObj.size(); j++) {
			//cout << "i=" << i << <<"------j=" << j << endl;
			//if (str[i] == ListObj[j]->GetName()) {
				str.erase(str.begin() + 1);
				h = str.size();
				ListObj[j]->CheckTree(str);
			}
		}
	}
}


string Base_N1::readTree(string s) {
	string temp;
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == '/')
			break;
		temp.push_back(s[i]);
	}
	reverse(temp.begin(), temp.end());
	return temp;
}




int main() {
	Base_N1 ba;
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
		string temp;
		cin >> temp;

		if (temp == "endtree") break;

		nameP = ba.readTree(temp);
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
	//
	//Base_N1 ba;
	int check = 0;
	string coor;
	vector<string> strList; // danh sach toa do dau vao
	vector<string> str; // vecto khi cat cac toa do
	while (1) {
		cin >> coor;
		if (coor == "//") break;
		strList.push_back(coor);
	}
	for (int i = 0; i < strList.size(); i++) {
		ba.proCesStr(strList[i], str, listObj[0]->GetName()); // ngat toa do va dinh dang dau vao -  chuyen //a thanh /root/a
		//outStr(str);
		if (str.front() == listObj[0]->GetName()) {
			listObj[0]->CheckTree(str);
			//cout << check << endl;
			if (h==1) {
				cout << endl << strList[i] << "     " << "Object name: " << str.back();
			}
			else
			{
				cout << endl << strList[i] << "     " << "Object not found";
			}
		}
		else
		{
			cout << endl << strList[i] << "     " << "Object not found";
		}


		str.clear(); // reset lai lam viec voi phan toa do moi
	}



	//outStr(str);
	// them check node
	//if (str.front() == listObj[0]->GetName()) { // check root
		//ba.CheckTree(str.back);
		//listObj[0]->CheckTree()// Check tu dau den cuoi 
	//}
	//cout << check;





	//outStr(str);


	return 0;
}