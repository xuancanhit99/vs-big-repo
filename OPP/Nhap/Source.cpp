#include "PhanSo.h"

int main() {
	PhanSo ps1, ps2, psKQ1, psKQ2, psKQ3, psKQ4;
	ps1.Nhap();
	ps2.Nhap();
	psKQ1 = ps1.Cong(ps2);
	psKQ1.Xuat();

	psKQ2 = ps1.Tru(ps2);
	psKQ2.Xuat();

	psKQ3 = ps1.Nhan(ps2);
	psKQ3.Xuat();

	psKQ4 = ps1.Chia(ps2);
	psKQ4.Xuat();
	return 0;
	system("pause");
}
