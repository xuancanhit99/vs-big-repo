#include <iostream> 
#include <string> 
#include <map>
#include <vector>

using namespace std;

class Base_N1 {
public:
	Base_N1(Base_N1* p_parent = 0, string s_object_name = "", int _is_ready = 1);
	void SetName(string object_name);
	string GetObjName();
	void SetParent(Base_N1* p_parent);
	void AddObj(Base_N1* p_obj);
	void SetState(int is_ready);
	void ShowObjState();

	~Base_N1();
protected:
	vector<Base_N1*> ListObj;
	vector<Base_N1*> ::iterator it;
	string object_name;
	Base_N1* p_parent;
	int is_ready;
	void ShowStateNext(Base_N1* ob_parent);
};

class Application : public Base_N1
{

public:
	Application(Base_N1* p_parent) {};
	void CreTree();
	int AllInOne();

	~Application();
};

class Derived_N2 : public Base_N1
{
public:
	Derived_N2(string c_name, int is_ready, map <string, Base_N1*>& parent_object_map);
};

class Derived_N3 : public Base_N1
{
public:
	Derived_N3(string c_name, int is_ready, map <string, Base_N1*>& parent_object_map);
};


class Derived_N4 : public Base_N1
{
public:
	Derived_N4(string c_name, int is_ready, map <string, Base_N1*>& parent_object_map);
};


Derived_N2::Derived_N2(string c_name, int is_ready, map <string, Base_N1*>& parent_object_map)
{
	this->object_name = c_name;
	parent_object_map.emplace(this->object_name, this);
	SetState(is_ready);
}

Derived_N3::Derived_N3(string c_name, int is_ready, map <string, Base_N1*>& parent_object_map)
{
	this->object_name = c_name;
	parent_object_map.emplace(this->object_name, this);
	SetState(is_ready);
}

Derived_N4::Derived_N4(string c_name, int is_ready, map <string, Base_N1*>& parent_object_map)
{
	this->object_name = c_name;
	parent_object_map.emplace(this->object_name, this);
	SetState(is_ready);
}


Base_N1::Base_N1(Base_N1* p_parent, string object_name, int _is_ready)
{
	this->object_name = object_name; if (p_parent)
	{
		this->p_parent = p_parent; p_parent->AddObj(this);
	}
	else
	{
		this->p_parent = 0;
	}
	SetState(_is_ready);
}

void Base_N1::SetName(string object_name)
{
	this->object_name = object_name;
}
string Base_N1::GetObjName()
{
	return object_name;
}
void Base_N1::SetParent(Base_N1* p_parent)
{
	if (p_parent)
	{
		this->p_parent = p_parent;
		p_parent->ListObj.push_back(this);
	}
}
void Base_N1::AddObj(Base_N1* p_obj)
{
	this->ListObj.push_back(p_obj);
}
void Base_N1::SetState(int is_ready)
{
	this->is_ready = is_ready;
}
void Base_N1::ShowObjState()
{
	ShowStateNext((Base_N1*)this);
}
void Base_N1::ShowStateNext(Base_N1* parent)
{
	if (parent->is_ready == 1)
	{
		cout << endl << "The object " << parent->GetObjName() << " is ready";
	}
	else
	{
		cout << endl << "The object " << parent->GetObjName() << " is not ready";
	}
	if (parent->ListObj.size() == 0) return;
	parent->it = parent->ListObj.begin();
	while (parent->it != parent->ListObj.end())
	{
		ShowStateNext((*(parent->it))); parent->it++;
	}
}

Base_N1::~Base_N1()
{
	for (it = ListObj.begin(); it != ListObj.end(); it++)
	{
		delete* (it);
	}
	ListObj.clear();
}

void Application::CreTree()
{
	map<string, Base_N1*> parent_object_map = {};
	cin >> object_name;
	string parent_name = this->object_name; string c_name = "";
	int is_ready = 0; int class_type = 0;
	cout << "Test result";
	while (parent_name != "endtree")
	{
		cin >> parent_name;
		parent_object_map.emplace(parent_name, this);
		if (parent_name == "endtree")
		{
			break;
		}
		cin >> c_name >> class_type >> is_ready;
		if (class_type == 2)
		{
			Base_N1* p_ob_2 = new Derived_N2(c_name, is_ready, parent_object_map);
			p_ob_2->SetParent(parent_object_map.find(parent_name)->second);
		}
		if (class_type == 3)
		{
			Base_N1* p_ob_3 = new Derived_N3(c_name, is_ready, parent_object_map);
			p_ob_3->SetParent(parent_object_map.find(parent_name)->second);
		}
		if (class_type == 4)
		{
			Base_N1* p_ob_4 = new Derived_N4(c_name, is_ready, parent_object_map);
			p_ob_4->SetParent(parent_object_map.find(parent_name)->second);
		}
	}
}

int Application::AllInOne()
{
	ShowObjState();
	return 0;
}

Application::~Application()
{
	for (it = ListObj.begin(); it != ListObj.end(); it++)
	{
		delete* (it);
	}
	ListObj.clear();
}

int main() {
	Application app(NULL);
	app.CreTree();
	return app.AllInOne();
}