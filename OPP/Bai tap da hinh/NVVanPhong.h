#ifndef NVVanPhong_h
#define NVVanPhong_h
#include "NhanVien.h"


class NVVanPhong : public NhanVien {
private:
	int SoNgayLamViec;
	float TroCap;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
	NVVanPhong(string, string, int, float);
};
#endif