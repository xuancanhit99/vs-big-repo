#ifndef APPLICATION_H
#define APPLICATION_H
#include "Base_N1.h"

class Application
{
public:
	vector<Base_N1*> listParent;
	void runApp();

	~Application();
};
#endif