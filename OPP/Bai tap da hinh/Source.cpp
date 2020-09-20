#include "NhanVien.h"
#include "NVQuanLy.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"
#include <vector>

int main() {
	vector<NhanVien*> nv;
	NVQuanLy ql("Quan Ly 1", "31/01/2020", 2, 2);
	NVSanXuat sx("San Xuat 1", "10/02/2020", 200);
	NVVanPhong vp("Van Phong 1", "20/01/2020", 5, 4);
	//nv.push_back((NhanVien*)ql);
	NhanVien* temp;
	temp = new NVQuanLy("Quan Ly 1", "31/01/2020", 2, 2);
	nv.push_back(temp);
	temp = new NVSanXuat("San Xuat 1", "10/02/2020", 200);
	nv.push_back(temp);
	temp = new NVVanPhong("Van Phong 1", "20/01/2020", 5, 4);
	nv.push_back(temp);
	//kiem tra
	/*((NVQuanLy*)nv[0])->Xuat();
	((NVSanXuat*)nv[1])->Xuat();
	((NVVanPhong*)nv[2])->Xuat();*/

	//dung vong lap
	for (int i = 0; i < nv.size(); i++) {
		nv[i]->Show();
	}


	/*NhanVien *nv;
	NVQuanLy ql("Vu Xuan Canh", "14/09/1999", 2, 200000);
	nv = &ql;*/
	//nv->Xuat(); // Binh thuong con tro nv khong the truy cap dia chi cua NVQuanLy
	//((NVQuanLy *)nv)->Xuat(); // vung chon kieu (ep kieu)
	cout << endl;
	system("pause");
	return 0;
}


// bai 65