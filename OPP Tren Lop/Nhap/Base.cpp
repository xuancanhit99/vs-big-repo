#include "Base.h"

Base::Base(string name, Base* parent) {
	NAME = name;
	PARENT = parent;
}

void Base::SetName(string name) {
	NAME = name;
}

string Base::GetName() {
	return NAME;
}

void Base::Output() {
	cout << GetName();
	for (int i = 0; i < ListObj.size(); i++) {
		cout << " " << ListObj[i]->GetName();
	}
}
