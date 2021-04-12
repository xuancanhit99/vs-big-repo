#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <string>
#include <list>
using namespace std;
class cl_base
{
public:
	cl_base(cl_base* obj_parent = 0);
	cl_base(cl_base* obj_parent, string obj_name);
	void setName(string name);
	string getName();
	void show_tree();
protected:
	string obj_name;
	cl_base* obj_parent;
	list <cl_base*> children;
	list <cl_base*>::iterator it;
};
#endif //CL_BASE_H