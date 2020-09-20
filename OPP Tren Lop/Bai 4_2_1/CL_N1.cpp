#include "CL_N1.h"


Cl_N1::Cl_N1(string name) {
	NAME = name;
}


void Cl_N1::SetStr() {
	cout << NAME << "_" << "1" << endl;
}
void Cl_N2::SetStr() {
	Cl_N1::SetStr();
	Cl_N1::SetStr();
	Cl_N1::SetStr();
	cout << NAME << "_" << "2" << endl;
}
void Cl_N3::SetStr() {
	cout << NAME << "_" << "3" << endl;
}
void Cl_N4::SetStr() {
	cout << NAME << "_" << "4" << endl;
}
void Cl_N5::SetStr() {
	cout << NAME << "_" << "5" << endl;
}

void Cl_N6::SetStr() {

	cout << NAME << "_" << "6" << endl;
}
void Cl_N7::SetStr() {

	cout << NAME << "_" << "7" << endl;
}

void Cl_N8::SetStr() {
	Cl_N2::SetStr();
	Cl_N3::SetStr();
	Cl_N4::SetStr();
	Cl_N5::SetStr();
	Cl_N6::SetStr();
	Cl_N7::SetStr();
	cout << NAME << "_" << "8";
}
