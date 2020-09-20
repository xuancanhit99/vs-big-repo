#include "Base_N1.h"
#include "Derived_N2.h"
#include "Derived_N3.h"
#include "Application_N4.h"

int main() {
	string r;
	cin >> r;
	Base_N1 ba;
	Base_N1 root(r, 0, 1);
	vector<Base_N1*> listObj;
	listObj.push_back(&root);
	ba.InOutTree(listObj);
	//
	Application_N4 ppa;
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
	return 0;
}