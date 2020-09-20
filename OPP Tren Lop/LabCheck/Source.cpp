#include <iostream>
#include <string>
#include <list>

using namespace std;

class Base{
public:       
    Base(Base* parent = 0);     
    Base(Base* parent, string name);       
    void SetName(string name);         
    string GetName();          
    void PrintTree();   
        
    string name;       
    Base* parent;      
    list <Base*> ListObj;       
    list <Base*>::iterator it;
    ~Base();
};

class Application : public Base
{
public:
    void CreObj();
    int AllInOne();
    ~Application();
private:
    Base* first; Base* second;
};

class Derived1 : public Base
{
public:
    Derived1(Base* parent) : Base(parent) {}; 
    Derived1(Base* parent, string name) : Base(parent, name) {};
};

class Derived2 : public Base
{
public:
    Derived2(Base* parent) : Base(parent) {};
    Derived2(Base* parent, string name) : Base(parent, name) {};
};

void Application::CreObj()
{
    cin >> name; 
    string nameP = ""; 
    string nameD = ""; 
    first = this; 
    second = first; 
    while (1)
    {
        cin >> nameP >> nameD;
        if (nameP == nameD)
            break;
        if (nameP == second->GetName())
            first = new Derived1(second, nameD);
        else if (nameP == first->GetName())
        {
            second = first;
            first = new Derived2(first, nameD);
        }
    }
}

int Application::AllInOne()
{
    this->PrintTree();
    return 0;
}

Base::Base(Base* parent)
{
    this->parent = parent;
    if (parent != 0)
        parent->ListObj.push_back(this);
}

Base::Base(Base* parent, string name)
{
    this->parent = parent; 
    SetName(name);
    if (parent != 0)
        parent->ListObj.push_back(this);
}

void Base::SetName(string name)
{
    this->name = name;
}
string Base::GetName()
{
    return this->name;
}

void Base::PrintTree()
{
    if (parent == 0)
        cout << name << endl; 
    cout << name;
    for (it = ListObj.begin(); it != ListObj.end(); it++)
    {
        cout << "  " << (*(it))->name;
    }
    for (it = ListObj.begin();  it != ListObj.end(); it++)
    {
        if ((*(it))->ListObj.size() != 0)
        {
            cout << endl;
            (*(it))->PrintTree(); 
            break;
        }
    }
}

Base::~Base() {
    for (it = ListObj.begin(); it != ListObj.end(); it++)
    {
        delete* (it);
    }
    ListObj.clear();
}

Application::~Application() {
    for (it = ListObj.begin(); it != ListObj.end(); it++)
    {
        delete *(it);
    }
    delete parent;
    ListObj.clear();
}

int main()
{
    Application app; 
    app.CreObj(); 
    app.AllInOne();
}

