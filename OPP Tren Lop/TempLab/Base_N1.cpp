#include "Base_N1.h"

Base_N1::Base_N1(string _name, Base_N1* _parent, int _isReady)
{
	name = _name;
	parent = _parent;
	isReady = _isReady;
}

string Base_N1::getName()
{
	return name;
}

void Base_N1::setName(string _name)
{
	name = _name;
}

int Base_N1::getReady()
{
	return isReady;
}

void Base_N1::output()
{
	for (int i = 0; i < listChild.size(); i++)
	{
		if (listChild[i]->getReady() > 0)
		{
			cout << endl << "The object " << listChild[i]->getName() << " is ready";
			listChild[i]->output();
		}
		else if (listChild[i]->getReady() <= 0)
		{
			cout << endl << "The object " << listChild[i]->getName() << " is not ready";
			listChild[i]->output();
		}
	}
}

Base_N1::~Base_N1()
{
	delete parent;
	listChild.clear();
}