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

class Application : public Base_N1 {
public:
	vector<Base_N1*> listObj;
	//vector<int> signalNum;
	vector<Base_N1*> signalTrans; vector<Base_N1*> signalRec;
	vector<Base_N1*> signaLing; vector<string> contentTrans;
	Base_N1* FindObjPointer OBJECT;
	void AddSignal SIGNAL;

	void AddHendler HENDLER;
	void SetConnect(vector<int> s_num, vector<string> s_trans, vector<string> s_rec);
	void DeleteSignal();
	void HandleSignal();

	void AllInOneApp();
};


class Derived_N2 :public Base_N1 {
public:
	Derived_N2(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
};

class Derived_N3 :public Base_N1 {
public:
	Derived_N3(string name, Base_N1* parent, int act) : Base_N1(name, parent, act) {}
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

Base_N1* Application::FindObjPointer OBJECT{
	for (int i = 0; i < listObj.size(); i++) {
		if (listObj[i]->GetName() == signal)
			return listObj[i];
	}
	return nullptr;
}

void Application::AddSignal SIGNAL{
	signalTrans.push_back(signal_trans);
	signalRec.push_back(signal_rec);
}

void Application::DeleteSignal() {
	for (int i = 0; i < signalTrans.size(); i++) {
		if (signalTrans[i] == nullptr || signalRec[i] == nullptr) {
			signalTrans.erase(signalTrans.begin() + i);
			signalRec.erase(signalRec.begin() + i);
		}
	}
	for (int i = 0; i < signaLing.size(); i++) {
		if (signaLing[i] == nullptr) {
			signaLing.erase(signaLing.begin() + i);
			contentTrans.erase(contentTrans.begin() + i);
		}
	}
}

void Application::AddHendler HENDLER{
	signaLing.push_back(signaling);
	contentTrans.push_back(content_trans);
}

void Application::SetConnect(vector<int> s_num, vector<string> s_trans, vector<string> s_rec) {
	cout << endl << "Set connects";
	for (int i = 0; i < s_num.size(); i++) {
		cout << endl << s_num[i] << " " << s_trans[i] << " " << s_rec[i];
	}
	cout << endl;
}

void Application::HandleSignal() {
	DeleteSignal();
	cout << "Emit signals";
	for (int i = 0; i < signaLing.size(); i++) {
		for (int j = 0; j < signalTrans.size(); j++) {
			if (signaLing[i] == signalTrans[j]) {
				cout << endl << "Signal to " << signalRec[j]->GetName() << " Text: " << signalTrans[j]->GetName() << " -> " << contentTrans[i];
			}
		}
	}
}

void Application::AllInOneApp() {
	string r;
	cin >> r;
	Base_N1 ba;
	Base_N1 root(r, 0, 1);
	listObj.push_back(&root);
	ba.InOutTree(listObj);
	////---------------------------
	Application ppa;
	vector<string> s_trans, s_rec;
	vector<int> s_num;
	while (1) {
		int signal_num;
		string signal_trans, signal_rec;
		cin >> signal_num;
		if (signal_num == 0) break;
		cin >> signal_trans >> signal_rec;
		s_num.push_back(signal_num); s_trans.push_back(signal_trans); s_rec.push_back(signal_rec);
		ppa.AddSignal(ppa.FindObjPointer(listObj, signal_trans), ppa.FindObjPointer(listObj, signal_rec));
	}
	while (1) {
		string signaling, content_trans;
		cin >> signaling;
		if (signaling == "endsignals") break;
		cin >> content_trans;
		ppa.AddHendler(ppa.FindObjPointer(listObj, signaling), content_trans);
	}
	ppa.SetConnect(s_num, s_trans, s_rec);
	ppa.HandleSignal();
}

int main() {
	Application appl;
	appl.AllInOneApp();
	return 0;
}