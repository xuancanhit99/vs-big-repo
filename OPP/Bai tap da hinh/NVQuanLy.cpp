#include "NVQuanLy.h"

//cai dat ham khoi tao
NVQuanLy::NVQuanLy(string ten, string ngaysinh, float heso, float thuong) :NhanVien(ten, ngaysinh) {
	HeSo = heso;
	Thuong = thuong;
	check = QL;
}

void NVQuanLy::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\n He So: ";
		cin >> HeSo;
	} while (HeSo < 0);
	do {
		cout << "\n Thuong: ";
		cin >> Thuong;
	} while (Thuong < 0);

}

void NVQuanLy::Xuat() {
	NhanVien::Xuat();
	cout << "\n Day la class NHANVIEN QUAN LY";
	cout << "\n He So: " << HeSo;
	cout << "\n Thuong: " << Thuong << endl;
}

float NVQuanLy::TinhLuong() {
	Luong = LuongCoBan * HeSo + Thuong;
	return Luong;
}
