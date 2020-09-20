#include "NVSanXuat.h"

NVSanXuat::NVSanXuat(string hoten, string ngaysinh, int sosx) : NhanVien(hoten, ngaysinh) {
	SoSanPham = sosx;
	check = SX;
}

void NVSanXuat::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\n So san pham: ";
		cin >> SoSanPham;
	} while (SoSanPham < 0);
}

void NVSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "\n So San Pham: " << SoSanPham << endl;
}


float NVSanXuat::TinhLuong() {
	Luong = SoSanPham * 2000 + LuongCoBan;
	return Luong;
}
