#include <iostream>
#include <string>
using namespace std;

//Nhap xuat thong tin cua 1 hoc sinh(ten, dia chia, diem toan va diem van)

class HocSinh {
private:
	string HoTen, DiaChi;
	float DiemToan, DiemVan;
	// Co 2 cach dinh nghia cho phuong thuc cua class
public:
	//Cach 1: Khai bao va dinh nghia trong class
	void Nhap() {
		//Thuc thi o day
		fflush(stdin);
		cout << "Nhap ten cua hoc sinh: ";
		getline(cin, HoTen);
		fflush(stdin);
		cout << endl << "Nhap dia chi: ";
		getline(cin, DiaChi);
		cout << endl << "Nhap diem toan: ";
		cin >> DiemToan;
		cout << endl << "Nhap diem van: ";
		cin >> DiemVan;
	}
	//Cach2 :Khai bao trong class va dinh nghoa ben ngoai
	void Xuat();
};

//Cach 2
//KieuTraVeCuaPhuongThuc TenClass::TenPhuongThuc() {//viet code o day}
void HocSinh::Xuat() {
	//Thuc thi o day
	cout << endl << "Ho ten: " << HoTen;
	cout << endl << "Dia Chi: " << DiaChi;
	cout << endl << "Diem toan: " << DiemToan;
	cout << endl << "Diem van: " << DiemVan;
}

int main() {

	HocSinh HS;
	HS.Nhap(); // Tinh dong goi
	HS.Xuat();

	system("Pause");
	return 0;
}