#ifndef Nhanvien_h
#define Nhanvien_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanVien {
protected:
	string HoTen, NgaySinh;
	float LuongCoBan, Luong;
public:
	enum LOAI {
		QL,
		SX,
		VP,
	};
	LOAI check;
	string GetName() {
		return HoTen;
	}
	void Nhap();
	void Xuat();
	void Show(); //xuat = vung chon kieu
	NhanVien(string, string);
	NhanVien() {
		LuongCoBan = 200000;
	}
	~NhanVien() {}
};
#endif