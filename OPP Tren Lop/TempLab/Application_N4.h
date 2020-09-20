#ifndef appvn
#define appvn
#include "Base_N1.h"
class Application_N4 : public Base_N1 {
public:
	//vector<int> signalNum;
	vector<Base_N1*> signalTrans; vector<Base_N1*> signalRec;
	vector<Base_N1*> signaLing; vector<string> contentTrans;
	Base_N1* FindObjPointer OBJECT;
	void AddSignal SIGNAL;

	void AddHendler HENDLER;
	void SetConnect(vector<int> s_num, vector<string> s_trans, vector<string> s_rec);
	void DeleteSignal();
	void HandleSignal();
};

#endif