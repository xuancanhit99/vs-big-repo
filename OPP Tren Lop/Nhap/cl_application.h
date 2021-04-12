#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H
#include "cl_base.h"
#include "cl_1.h"
#include "cl_2.h"

using namespace std;
class cl_application : public cl_base
{
public:
	void build_tree_objects();
	int exec_app();
private:
	cl_base* first;
	cl_base* second;
};
#endif //CL_APPLICATION_H
