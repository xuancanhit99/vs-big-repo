#include "Application_N4.h"

Base_N1* Application_N4::FindObjPointer OBJECT{
	for (int i = 0; i < listObj.size(); i++) {
		if (listObj[i]->GetName() == signal)
			return listObj[i];
	}
	return nullptr;
}

void Application_N4::AddSignal SIGNAL{
	signalTrans.push_back(signal_trans);
	signalRec.push_back(signal_rec);
}

void Application_N4::DeleteSignal() {
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

void Application_N4::AddHendler HENDLER{
	signaLing.push_back(signaling);
	contentTrans.push_back(content_trans);
}

void Application_N4::SetConnect(vector<int> s_num, vector<string> s_trans, vector<string> s_rec) {
	cout << endl << "Set connects";
	for (int i = 0; i < s_num.size(); i++) {
		cout << endl << s_num[i] << " " << s_trans[i] << " " << s_rec[i];
	}
	cout << endl;
}

void Application_N4::HandleSignal() {
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




