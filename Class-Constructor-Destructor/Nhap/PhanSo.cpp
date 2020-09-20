#include "PhanSo.h"
void PhanSo::Nhap() {
	cout << "\n Nhap tu so: ";
	cin >> TuSo;
	cout << "\n Nhap mau so: ";
	cin >> MauSo;
}

void PhanSo::Xuat() {
	cout << TuSo << "/" << MauSo;
}

PhanSo::PhanSo(){}
PhanSo::~PhanSo() {}

PhanSo PhanSo::Cong(PhanSo ps) {
	//tra ve phan so
	PhanSo KQ;
	KQ.TuSo = this->TuSo * ps.MauSo + ps.TuSo * this->MauSo;
	KQ.MauSo = MauSo * ps.MauSo;
	//Ham rut gon phan so
	//RutGon(&KQ)
	return KQ;
}

PhanSo PhanSo::Tru(PhanSo ps) {
	//tra ve phan so
	PhanSo KQ;
	KQ.TuSo = this->TuSo * ps.MauSo - ps.TuSo * this->MauSo;
	KQ.MauSo = MauSo * ps.MauSo;
	//Ham rut gon phan so
	//RutGon(&KQ)
	return KQ;
}

PhanSo PhanSo::Nhan(PhanSo ps) {
	//tra ve phan so
	PhanSo KQ;
	KQ.TuSo = TuSo * ps.TuSo;
	KQ.MauSo = MauSo * ps.MauSo;
	//Ham rut gon phan so
	//RutGon(&KQ)
	return KQ;
}

PhanSo PhanSo::Chia(PhanSo ps) {
	//tra ve phan so
	PhanSo KQ;
	KQ.TuSo = TuSo * ps.MauSo;
	KQ.MauSo = MauSo * ps.TuSo;
	//Ham rut gon phan so
	//RutGon(&KQ)
	return KQ;
}
