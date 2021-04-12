#ifndef CL_1_H
#define CL_1_H
#include "cl_base.h"
class cl_1 : public cl_base
{
public:
	cl_1(cl_base* obj_parent) : cl_base(obj_parent) {};
	cl_1(cl_base* obj_parent, string obj_name) : cl_base
	(obj_parent, obj_name) {};
};
#endif //CL_1_H
