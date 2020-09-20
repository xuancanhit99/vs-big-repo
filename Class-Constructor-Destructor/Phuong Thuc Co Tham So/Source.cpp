#include <iostream>

using namespace std;

//Phương thức có đối tượng là tham số truyền vào
//YC: tính tổng của 2 giờ(số giờ, số phút)
//2h56p +1h4p = 4h
class ThoiGian {

private:
	int Gio, Phut;
public:
	void Nhap(int gio, int phut); // co 2 tham so truyen vao
	void Xuat();
	ThoiGian Tong(ThoiGian T1, ThoiGian T2);
};

void ThoiGian::Nhap(int gio, int phut) {
	Gio = gio;
	Phut = phut;
}

void ThoiGian::Xuat() {
	cout << Gio << "h" << Phut << "p";
}

ThoiGian ThoiGian::Tong(ThoiGian T1, ThoiGian T2) { // Doi tuong co the la tham so truyen vao
	Phut = T1.Phut + T2.Phut;
	Gio = Phut / 60;
	Phut = Phut % 60;
	Gio = Gio + T1.Gio + T2.Gio;
	return *this;
}

int main() {

	ThoiGian T1, T2, T3;
	T1.Nhap(2, 56);
	T2.Nhap(1, 4);
	T3.Tong(T1, T2);
	T3.Xuat();

	cout << endl;
	system("pause");
	return 0;
}