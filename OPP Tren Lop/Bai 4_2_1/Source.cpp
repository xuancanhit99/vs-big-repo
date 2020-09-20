

#include "CL_N1.h"

int main() {
	void* clx;
	string name; // 2
	cin >> name; // 3
	Cl_N8 cl8(name); //4
	clx = &cl8; // 5
	Cl_N8* cl = static_cast<Cl_N8*>(clx);
	cl->SetStr();
	return 0;
}     