#include "Application.h"
#include "Base_N1.h"
#include "Derived_N2.h"
#include "Derived_N3.h"
#include "Derived_N4.h"

void Application::runApp()
{
	string nameP, nameD;
	string r;
	cin >> r;
	Base_N1 root(r, 0, 1);
	vector<Base_N1*> listParent;
	listParent.push_back(&root);
	Derived_N2* der2;
	Derived_N3* der3;
	Derived_N4* der4;
	int _isReady, numclass;
	while (1)
	{
	in:
		cin >> nameP;
		if (nameP == "endtree")
			break;
		cin >> nameD >> numclass >> _isReady;
		if (nameD == nameP) goto in;
		for (int i = 0; i < listParent.size(); i++)
		{
			if (listParent[i]->getName() == nameP)
			{
				if (numclass == 2)
				{
					der2 = new Derived_N2(nameD, listParent[i], _isReady);
					listParent[i]->listChild.push_back(der2);
					listParent.push_back(der2);
				}
				else if (numclass == 3)
				{
					der3 = new Derived_N3(nameD, listParent[i], _isReady);
					listParent[i]->listChild.push_back(der3);
					listParent.push_back(der3);
				}
				else if (numclass == 4)
				{
					der4 = new Derived_N4(nameD, listParent[i], _isReady);
					listParent[i]->listChild.push_back(der4);
					listParent.push_back(der4);
				}
			}
		}
	}
	cout << "Test result" << endl;
	cout << "The object " << listParent[0]->getName() << " is ready";
	listParent[0]->output();
}

Application::~Application()
{
	listParent.clear();
}
