#include <iostream>
#include <string>
using namespace std;
//Con tro this
//Con tro this tham chieu den doi tuong dang goi ham thanh phan

class PhanSo {
private:
	int TuSo, MauSo;
public:
	PhanSo RutGon();
	void Nhap();
	void Xuat();
};
//Cach dung thu 1 cua con tro this: "tro" den cac than phan cua class hien tai
void PhanSo::Nhap() {
	cout << endl << "Nhap tu so: "; 
	cin >> this->TuSo;       //giong voi cin >> TuSo; con tro this tham chieu to doi tuong thanh phan
	cout << endl << "Nhap mau so: "; 
	cin >> this->MauSo;      //giong voi cin >> MauSo
}

void PhanSo::Xuat() {
	cout << this->TuSo << "/" << this->MauSo;
}

//Ca dung thi 2: Tra ve Object hien tai
PhanSo PhanSo::RutGon() {
	int a, b;
	a = abs(this->TuSo);
	b = abs(this->MauSo);
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	this->TuSo /= a;
	this->MauSo /= a;
	//Gia tri cua TuSo, MauSo da thay doi
	return *this;
}

int main() {

	PhanSo ps;
	ps.Nhap();
	ps.RutGon();
	ps.Xuat();
	cout << endl;
	system("Pause");
	return 0;
}