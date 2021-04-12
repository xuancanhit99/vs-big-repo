#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class cl_base {
protected:
	string object_name;
	cl_base* p_parent;
	int p_act;
	int state;
public:
	vector<cl_base*> children;
	cl_base() {}
	cl_base(string name, cl_base* parent, int numcl, int act);
	string get_object_name();
	void set_object_name(string name);
	int get_act();
	int get_numcl();
	void show_object_state();
	void show_object(int a);
	void find(vector<string>& pathin);
	void process_str(string s, vector<string>& str);
	void check_tree(vector<string> str);

	void cut_vec(vector<string>& pathin, string s);
	void cre_obj(vector<cl_base*>&, string, cl_base*, int, int);
	void push_tree(vector<cl_base*>& p_children);
	void check_obj(vector<cl_base*> p_children, vector<string>& str_list);
};

class cl_2 : public cl_base {
public:
	cl_2(string name, cl_base* parent, int numcl, int act) : cl_base(name, parent, numcl, act) {}
};

class cl_3 : public cl_base {
public:
	cl_3(string name, cl_base* parent, int numcl, int act) : cl_base(name, parent, numcl, act) {}
};

class cl_4 : public cl_base {
public:
	cl_4(string name, cl_base* parent, int numcl, int act) : cl_base(name, parent, numcl, act) {}
};

class cl_5 : public cl_base {
public:
	cl_5(string name, cl_base* parent, int numcl, int act) : cl_base(name, parent, numcl, act) {}
};

class cl_6 : public cl_base {
public:
	cl_6(string name, cl_base* parent, int numcl, int act) : cl_base(name, parent, numcl, act) {}
};


class cl_application : public cl_base {
public:
	cl_application() : cl_base() {}
	void bild_tree_objects();
	int exec_app();
};

cl_base* bas = nullptr;
void cl_base::find(vector<string>& pathin) {
	for (int i = 0; i < children.size(); i++) {
		if (pathin.size() == 1) {
			break;
		}
		if (children[i]->get_object_name() == pathin[1]) {
			bas = children[i];
			pathin.erase(pathin.begin() + 1);
			children[i]->find(pathin);
		}
	}
}



cl_base::cl_base(string name, cl_base* parent, int numcl, int act) {
	object_name = name;
	p_parent = parent;
	p_act = act;
	state = numcl;
}

void cl_base::set_object_name(string name) {
	object_name = name;
}

string cl_base::get_object_name() {
	return object_name;
}

int cl_base::get_act() {
	return p_act;
}

int cl_base::get_numcl() {
	return state;
}

void cl_base::show_object(int a) {
	for (int j = 0; j < a; j++) {
		cout << "    ";
	}
}

int k = 1;
void cl_base::show_object_state() {
	for (int i = 0; i < children.size(); i++) {
		cout << endl;
		show_object(k);
		cout << children[i]->get_object_name();
		k++;
		children[i]->show_object_state();
	}
	k--;
}

void cl_base::process_str(string s, vector<string>& str) {
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '/' && s[i + 1] == '/')
			str.push_back("_node");
		if (s[i] != '/') {
			temp.push_back(s[i]);
		}
		else if (s[i] == '/' && i != 0 && i != 1) {
			str.push_back(temp);
			temp = "";
		}
	}
	str.push_back(temp);
}


int h = 0;
void cl_base::check_tree(vector<string> str) {
	for (int j = 0; j < children.size(); j++) {
		if (str[1] == children[j]->get_object_name()) {
			str.erase(str.begin() + 1);
			h = str.size();
			if (h == 1)
				break;
			children[j]->check_tree(str);
		}
	}
}

void cl_base::cre_obj(vector<cl_base*>& p_children, string nameD, cl_base* obj, int numcl, int act) {
	cl_base* base;
	cl_2* der2;
	cl_3* der3;
	cl_4* der4;
	cl_5* der5;
	cl_6* der6;
	switch (numcl) {
	case 2: {
		der2 = new cl_2(nameD, obj, numcl, act);
		obj->children.push_back(der2);
		p_children.push_back(der2);
		break;
	}
	case 3: {
		der3 = new cl_3(nameD, obj, numcl, act);
		obj->children.push_back(der3);
		p_children.push_back(der3);
		break;
	}
	case 4: {
		der4 = new cl_4(nameD, obj, numcl, act);
		obj->children.push_back(der4);
		p_children.push_back(der4);
		break;
	}
	case 5: {
		der5 = new cl_5(nameD, obj, numcl, act);
		obj->children.push_back(der5);
		p_children.push_back(der5);
		break;
	}
	case 6: {
		der6 = new cl_6(nameD, obj, numcl, act);
		obj->children.push_back(der6);
		p_children.push_back(der6);
		break;
	}
	default: {
		base = new cl_base(nameD, obj, numcl, act);
		obj->children.push_back(base);
		p_children.push_back(base);
		break;
	}
	}
}

void cl_base::check_obj(vector<cl_base*> p_children, vector<string>& str_list) {
	cl_base ba;
	vector<string> str;
	for (int i = 0; i < str_list.size(); i++) {
		ba.process_str(str_list[i], str);
		if (str[0] == "_node") {
			int c = 0;
			for (int k = 0; k < p_children.size(); k++) {
				if (str[1] == p_children[k]->get_object_name())
					c = 1;
			}
			if (c == 1)
				cout << endl << str_list[i] << " " << "Object name: " << str.back();
			else
				cout << endl << str_list[i] << " " << "Object not found";
		}
		else {
			if (str.front() == p_children[0]->get_object_name()) {
				if (str.size() == 1)
					cout << endl << str_list[i] << " " << "Object name: " << str.back();
				else {
					p_children[0]->check_tree(str);
					extern int h;
					if (h == 1) {
						cout << endl << str_list[i] << " " << "Object name: " << str.back();
						h = 0;
					}
					else
						cout << endl << str_list[i] << " " << "Object not found";
				}
			}
			else
				cout << endl << str_list[i] << " " << "Object not found";
		}
		str.clear();
	}
}



void cl_base::push_tree(vector<cl_base*>& p_children) {
	string nameP, nameD;
	int act, numcl;
	vector<string> pathin;
	while (1) {
		string s;
		cin >> s;
		if (s == "endtree") break;
		cut_vec(pathin, s); // root obj2 obj5
		cin >> nameD >> numcl >> act;
		for (int j = 0; j < pathin.size(); j++) {
			for (int i = 0; i < p_children.size(); i++) {
				if (pathin.size() == 1) {
					if (pathin[j] == p_children[i]->get_object_name()) {
						cre_obj(p_children, nameD, p_children[i], numcl, act);
					}
				}
				else {
					p_children[0]->find(pathin);
					cre_obj(p_children, nameD, bas, numcl, act);
				}
			}
			pathin.clear();
		}
	}

}

void cl_base::cut_vec(vector<string>& pathin, string s) {
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '/')
			temp.push_back(s[i]);
		else if (s[i] == '/' && i != 0) {
			pathin.push_back(temp);
			temp = "";
		}
	}
	pathin.push_back(temp);
}

int cl_application::exec_app() {
	return 1;
}

void cl_application::bild_tree_objects() {
	string r;
	cin >> r;
	cl_base root(r, 0, 1, 1);
	vector<cl_base*> p_children;
	p_children.push_back(&root);
	cl_application app;
	app.push_tree(p_children);
	cout << "Object tree" << endl;
	cout << p_children[0]->get_object_name();
	p_children[0]->show_object_state();
	//-------------
	int check = 0;
	string coor;
	vector<string> str_list;
	while (1) {
		cin >> coor;
		if (coor == "//") break;
		str_list.push_back(coor);
	}
	app.check_obj(p_children, str_list);
}



int main() {
	cl_application ob_application;
	ob_application.bild_tree_objects();
	return ob_application.exec_app();
}