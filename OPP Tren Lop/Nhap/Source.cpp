#include "cl_application.h"
int main()
{
	cl_application ob_application;
	ob_application.build_tree_objects();
	return ob_application.exec_app();
}
