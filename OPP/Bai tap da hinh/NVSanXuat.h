#ifndef NVSanXuat_h
#define NVSanXuat_h
#include "NhanVien.h"

class NVSanXuat : public NhanVien {
private:
	int SoSanPham;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
	NVSanXuat(string, string, int);
};
#endif