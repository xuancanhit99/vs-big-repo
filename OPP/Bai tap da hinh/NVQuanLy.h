#ifndef NVQuanLy_h
#define NVQuanLy_h
#include "NhanVien.h"

class NVQuanLy : public NhanVien {
private:
	float HeSo, Thuong;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
	NVQuanLy(string, string, float, float);
};
#endif