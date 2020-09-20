#include "NVVanPhong.h"

NVVanPhong::NVVanPhong(string hoten, string ngaysinh, int songaylam, float trocap) : NhanVien(hoten, ngaysinh) {
	SoNgayLamViec = songaylam;
	TroCap = trocap;
	check = VP;
}

void NVVanPhong::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\n So ngay lam viec: ";
		cin >> SoNgayLamViec;
	} while (SoNgayLamViec < 0);
	do {
		cout << "\n Tro Cap: ";
		cin >> TroCap;
	} while (TroCap < 0);
}

void NVVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "\n So ngay lam viec: " << SoNgayLamViec;
	cout << "\n Tro Cap: " << (size_t)TroCap << endl;
}


float NVVanPhong::TinhLuong() {
	Luong = LuongCoBan + TroCap + SoNgayLamViec * 100000;
	return Luong;
}
