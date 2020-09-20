#include <iostream>
#include <iomanip>
#include <vector>


#define signa_1 1
#define signa_2 0
#define SIGNAL (Base_N1* signal_trans, Base_N1* signal_rec)
#define HENDLER (Base_N1* signaling, string content_trans)
#define OBJECT (vector<Base_N1*> listObj, string signal)
#define MAX 10

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
	vector<Base_N1*> signalTrans; vector<Base_N1*> signalRec;
	vector<Base_N1*> signaLing; vector<string> contentTrans;

	Base_N1* FindObjPointer OBJECT;
	void AddSignal SIGNAL;
	void AddHendler HENDLER;
	void SetConnect(vector<int> s_num, vector<string> s_trans, vector<string> s_rec);
	void DeleteSignal();
	void HandleSignal();
	void AllInOneApp();

	
	void SplitStr(string num_str, int num_int[]);
	void PushMatrix(int num_int[], int i);

	void AddFullMatrix(int& a, int& b);
	void UpUnit(int i, int j);
	void DownUnit(int i, int j);
	void RightUnit(int i, int j);
	void NextStep(int i, int j);
	void OutMatrix();

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

int matrix[MAX][MAX];
void Application::SplitStr(string num_str, int num_int[]) {
	for (int i = 0; i < num_str.size(); i++) {
		if (num_str[i] == '0')
			num_int[i] = 0;
		else
			num_int[i] = 1;
	}
}

void Application::PushMatrix(int num_int[], int i) {
	for (int j = 0; j < 10; j++) {
		matrix[i][j] = num_int[j];
	}
}

void Application::AddFullMatrix(int& a, int& b) {
	int num_int[10];
	string num_str;
	for (int i = 0; i < 10; i++) {
		cin >> num_str;
		SplitStr(num_str, num_int);
		PushMatrix(num_int, i);
	}
	int out = 0;
	for (int k = 0; k < 10; k++) {
		for (int h = 0; h < 10; h++) {
			if (matrix[h][k] == 1) {
				a = h;
				b = k;
				out = 1;
				break;
			}
		}
		if (out == 1) break;
	}
}


void Application::UpUnit(int i, int j) {
	if (matrix[i - 1][j] == 1) {
		matrix[i - 1][j] = 70;
		NextStep(i - 1, j);
	}
}

void Application::DownUnit(int i, int j) {
	if (matrix[i + 1][j] == 1) {
		matrix[i + 1][j] = 70;
		NextStep(i + 1, j);
	}
}

void Application::RightUnit(int i, int j) {
	if (matrix[i][j + 1] == 1) {
		matrix[i][j + 1] = 70;
		NextStep(i, j + 1);
	}
}


void Application::NextStep(int i, int j) {
	if (i != 9)
		DownUnit(i, j);
	if (j != 9) {
		RightUnit(i, j);
	}
	if (i != 0)
		UpUnit(i, j);
}

void Application::OutMatrix() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matrix[i][j] == 70)
				cout << char(matrix[i][j]);
			else
				cout << matrix[i][j];
		}
		if (i < 9)
			cout << endl;
	}
}


int main() {
	int i, j;
	Application app1, app2, app3, app4, app5, app6;
	app1.AddFullMatrix(i, j);
	app2.DownUnit(i, j);
	app3.RightUnit(i, j);
	app4.UpUnit(i, j);
	app5.NextStep(i, j);
	app6.OutMatrix();
	return 0;
}