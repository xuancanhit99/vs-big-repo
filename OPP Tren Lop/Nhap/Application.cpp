#include "Application.h"
#include "Derived1.h"
#include "Derived2.h"

void Application::AllInOne() {
	string nameP, nameD;
	cin >> nameP;
	Derived1 root(nameP, 0); // tao goc cay tro tren 0
	vector<Base*> listObj; // tao danh sach vecto chua dia chi cac nut
	listObj.push_back(&root); // them goc cay dau tien
	cin >> nameP >> nameD;
	Derived2* der;
	while (nameP != nameD) {
		for (int i = 0; i < listObj.size(); i++) {
			if (listObj[i]->GetName() == nameP) { // tao nhanh cay con moi tu nut ban dau
				der = new Derived2(nameD, listObj[i]); // tao nut con moi ten la (nut cha)nameD va danh sach chua cac nut con 
				listObj[i]->ListObj.push_back(der); // them nut cha vao dau vector doi tuong moi
				listObj.push_back(der);// them nut cha hien tai vao danh sach cac nut con
			}
		}
		cin >> nameP >> nameD;
	}
	cout << listObj[0]->GetName();
	for (int i = 0; i < listObj.size(); i++) {
		if (listObj[i]->ListObj.size() > 0) {
			cout << endl;
			listObj[i]->Output();
		}
	}
}