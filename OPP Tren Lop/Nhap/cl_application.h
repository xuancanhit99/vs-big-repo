#ifndef pp
#define pp
#include "Base.h"
class cl_application : public Base {
public:
	vector<Base*> listObj; // tao danh sach vecto chua dia chi cac nut
	cl_application() : Base() {}
	cl_application(cl_application* app){}
	void bild_tree_objects();
	int exec_app();
};

#endif