#include "NhanVien.h"
#include "NVQuanLy.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"

NhanVien::NhanVien(string ten, string ngaysinh) {
	HoTen = ten;
	NgaySinh = ngaysinh;
}

void NhanVien::Nhap() {
	cin.ignore();
	fflush(stdin);
	cout << "\n Nhap ho ten: ";
	getline(cin, HoTen);//lay nguyen dong
	fflush(stdin);
	cout << "\n Nhap vao ngay sinh ";
	getline(cin, NgaySinh);
}

void NhanVien::Show() {
	switch (check)
	{
	case NhanVien::QL:
		((NVQuanLy*)this)->Xuat();
		break;
	case NhanVien::SX:
		((NVSanXuat*)this)->Xuat();
		break;
	case NhanVien::VP:
		((NVVanPhong*)this)->Xuat();
		break;
	default:
		break;
	}
}

void NhanVien::Xuat() {
	cout << "\n Day la class cha NHANVIEN";
	cout << "\n Ho Ten: " << HoTen;
	cout << "\n Ngay Sinh: " << NgaySinh;
	cout << "\n Luong co ban: " << LuongCoBan;
}