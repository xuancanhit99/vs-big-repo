#include "cl_base.h"

cl_base::cl_base(cl_base* obj_parent)
{
	this->obj_parent = obj_parent;
	if (obj_parent != 0) obj_parent->children.push_back(this);
}
cl_base::cl_base(cl_base* obj_parent, string obj_name)
{
	this->obj_parent = obj_parent;
	setName(obj_name);
	if (obj_parent != 0)
		obj_parent->children.push_back(this);
}
void cl_base::setName(string name)
{
	this->obj_name = name;
}
string cl_base::getName()
{
	return this->obj_name;
}
void cl_base::show_tree()
{
	if (obj_parent == 0)
		cout << obj_name << endl;
	cout << obj_name;
	for (it = children.begin(); it != children.end(); it++)
	{
		cout << " " << (*(it))->obj_name;
	}
	for (it = children.begin(); it != children.end(); it++)
	{
		if ((*(it))->children.size() != 0)
		{
			cout << endl;
			(*(it))->show_tree();
			break;
		}
	}
}