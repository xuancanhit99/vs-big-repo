#ifndef cl_n_h
#define cl_n_h
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cl_N1 {
	string NAME;
public:
	Cl_N1(string name);
	virtual void SetStr();
};

class Cl_N2 : public  Cl_N1 {
	string NAME;
public:
	Cl_N2(string name) : Cl_N1(name) {
		NAME = name;
	}
	void SetStr();
};

class Cl_N3 : public Cl_N1 {
	string NAME;
public:
	Cl_N3(string name) : Cl_N1(name) {
		NAME = name;
	}
	void SetStr();
};

class Cl_N4 : public Cl_N1 {
	string NAME;
public:
	Cl_N4(string name) : Cl_N1(name) {
		NAME = name;
	}
	void SetStr();
};

class Cl_N5 : public Cl_N1 {
	string NAME;
public:
	Cl_N5(string name) : Cl_N1(name) {
		NAME = name;
	}
	void SetStr();
};

class Cl_N6 : public Cl_N2, public Cl_N3 {
	string NAME;
public:
	Cl_N6(string name) : Cl_N2(name), Cl_N3(name) {
		NAME = name;
	}
	void SetStr();
};

class Cl_N7 : public Cl_N4, public Cl_N5 {
	string NAME;
public:
	Cl_N7(string name) : Cl_N4(name), Cl_N5(name) {
		NAME = name;
	}
	void SetStr();
};

class Cl_N8 : Cl_N6, Cl_N7 {

public:
	string NAME;
	Cl_N8(string name) : Cl_N6(name), Cl_N7(name) {
		NAME = name;
	}
	void SetStr();
};
#endif