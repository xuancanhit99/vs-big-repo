#include <iostream>
using namespace std;
class PhanSo
{
private:
	int TuSo, MauSo;
public:
	//ket qua la mot phan so, tham so truyen vao la mot phan so
	PhanSo Cong(PhanSo);
	PhanSo Tru(PhanSo);
	PhanSo Nhan(PhanSo);
	PhanSo Chia(PhanSo);
	void Nhap();
	void Xuat();
	PhanSo();
	~PhanSo();
};

