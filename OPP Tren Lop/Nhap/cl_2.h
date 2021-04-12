#ifndef CL_2_H
#define CL_2_H
#include "cl_base.h"

class cl_2 : public cl_base
{
public:
	cl_2(cl_base* obj_parent) : cl_base(obj_parent) {};
	cl_2(cl_base* obj_parent, string obj_name) : cl_base
	(obj_parent, obj_name) {};
};
#endif //CL_2_H
