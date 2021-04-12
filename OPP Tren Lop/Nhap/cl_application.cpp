#include "cl_application.h"

void cl_application::build_tree_objects()
{
	cin >> obj_name;
	string parent_name = "";
	string child_name = "";
	first = this;
	second = first;
	while (1)
	{
		cin >> parent_name >> child_name;
		if (parent_name == child_name)
			break;
		if (parent_name == second->getName())
			first = new cl_1(second, child_name);
		else if (parent_name == first->getName())
		{
			second = first;
			first = new cl_2(first, child_name);
		}
	}
}
int cl_application::exec_app()
{
	this->show_tree();
	return 0;
}
