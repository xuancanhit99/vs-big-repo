#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base {
    string NAME;
    Base* PARENT;
public:
    vector<Base*> ListObj;
    Base(string name, Base* parent);
    Base(Base* parent);
    void SetName(string name); 
    string GetName();
    void Output();
};

class Derived1 :public Base {
    string NAME;
    Base* PARENT;
public:
    Derived1(string name, Base* parent) : Base(name, parent) {}
};

class Derived2 :public Base {
    string NAME;
    Base* PARENT;
public:
    Derived2(string name, Base* parent) : Base(name, parent) {}
};


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
    for (int i = 0; i < ListObj.size(); i++)
        cout << "  " << ListObj[i]->GetName();
}

Base::Base(Base* parent) {
    ListObj.push_back(parent);
}

int main() {
    string nameP, nameD; 
    cin >> nameP;
    Derived1 root(nameP, 0);
    vector<Base*> listObj;
    listObj.push_back(&root); 
    cin >> nameP >> nameD;
    Derived2* der;
    while (nameP != nameD) {
        for (int i = 0; i < listObj.size(); i++) {
            if (listObj[i]->GetName() == nameP) {
                der = new Derived2(nameD, listObj[i]);
                Base child(der);
               // listObj[i]->ListObj.push_back(der); 
                listObj.push_back(der);
            }
        }
        cin >> nameP >> nameD;
    }
    cout << listObj[0]->GetName(); for (int i = 0; i < listObj.size(); i++) {
        if (listObj[i]->ListObj.size() > 0) {
            cout << endl;
            listObj[i]->Output();
        }
    }
    return 0;
}



