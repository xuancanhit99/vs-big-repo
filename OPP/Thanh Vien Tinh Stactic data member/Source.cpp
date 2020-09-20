#include <iostream>

using namespace std;

class PhanSo {
private:
	//Khai bao thanh phan stactic
	static int dem; // bien dem dung chung
	int TuSo, MauSo;
public:
	PhanSo() { // ham khoi tao mac dinh
		TuSo = 0;
		MauSo = 1;
		
	}
	PhanSo(int tu, int mau);
	int XemGiaTri() {
		//cout << "\n Dem = " << dem;
		return dem;
	}
	~PhanSo() {}
};

PhanSo::PhanSo(int tu, int mau) {
	TuSo = tu;
	MauSo = mau;
	dem++;
}
//cai dat
//int PhanSo::dem;//khong gan gia tri=> mac dinh dem = 0
int PhanSo::dem = 12;


int main() {
	//neu khong phai ban duy nhat: ps1(dem1), ps(dem2)
	PhanSo ps1(2, 3), ps2(3, 4), ps3(5,6);
	cout << "So luong phan so dang co la: " << ps3.XemGiaTri();
	//ps2.XemGiaTri();
	cout << endl;
	system("pause");
	return 0;
}