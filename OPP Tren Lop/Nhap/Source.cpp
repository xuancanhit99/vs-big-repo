#include "Base.h"
#include "cl_application.h"
#include "Derived1.h"
#include "Derived2.h"

int main() {
	cl_application ob_cl_application(nullptr);
	ob_cl_application.bild_tree_objects();
	return ob_cl_application.exec_app();
}