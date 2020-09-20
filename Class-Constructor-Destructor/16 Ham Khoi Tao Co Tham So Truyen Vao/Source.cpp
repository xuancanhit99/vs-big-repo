#include <iostream>
using namespace std;
class PhanSo {
private:
	int TuSo, MauSo;
public:
	PhanSo() { // ham khoi tao mac dinh
		TuSo = 0;
		MauSo = 1;
	}
	PhanSo(int tu, int mau);
	PhanSo(int tu) {
		TuSo = tu;
		MauSo = 1;
	}
};

PhanSo::PhanSo(int tu, int mau) {
	TuSo = tu;
	MauSo = mau;
}

int main() {
	//Cach 1: Truc Tiep
	PhanSo ps(1, 4);
	//Cach 2: Gian Tiep
	PhanSo ps2 = PhanSo(2, 5);
	PhanSo ps3(5);
	cout << endl;
	system("pause");
	return 0;
}