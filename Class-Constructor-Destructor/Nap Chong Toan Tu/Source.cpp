#include <iostream>

using namespace std;

//Cach 1: memberfunction
// 1. Toan tu so doi: Su dung member functiom
// 2. Toan tu so doi: Su dung non-member functiom
class PhanSo {
private:
	int TuSo, MauSo;
public:
	//Getter lay ra tri ra ngoai
	int LayTu() {
		return TuSo;
	}
	int LayMau() {
		return MauSo;
	}
	//Setter cai dat gia tri
	void SetTu(int a) {
		TuSo = a;
	}
	void SetMau(int b) {
		MauSo = b;
	}
	void Xuat() {
		cout << TuSo << "/" << MauSo;
	}
	PhanSo() {};
	PhanSo(int a, int b) {
		TuSo = a;
		MauSo = b;
	}
	PhanSo operator+(PhanSo);
	PhanSo operator+(int); // A + int // chi truyen vao duoc 1 doi so
	//friend PhanSo operator+(int, PhanSo);
	//void operator-();
	friend istream& operator>>(istream&, PhanSo&);
	friend ostream& operator<<(ostream&, PhanSo);

	//Tiento - Hau to
	PhanSo& operator++() {
		TuSo = MauSo + TuSo;
		return *this;
	}
};

// ham ban
istream& operator>>(istream& input, PhanSo& ps) {
	int a, b;
	cout << "\n Nhap tu = ";
	input >> a;
	cout << "\n Nhap mau = ";
	input >> b;
	ps = PhanSo(a, b);
	return input;
}

ostream& operator<<(ostream& output, PhanSo ps) {
	return output << ps.LayTu() << "/" << ps.LayMau();
}


//non-member function input/output

//istream& operator>>(istream& input, PhanSo& ps) {
//	int a, b;
//	cout << "\n Nhap tu = ";
//	input >> a;
//	cout << "\n Nhap mau = ";
//	input >> b;
//	ps = PhanSo(a, b);
//	return input;
//}

//ostream& operator<<(ostream& output, PhanSo ps) {
//	return output << ps.LayTu() << "/" << ps.LayMau();
//}


//Ham ban
//PhanSo operator+(int a, PhanSo ps) {
//	PhanSo temp;
//	temp.TuSo = ps.TuSo + a * ps.MauSo;
//	temp.MauSo = ps.MauSo;
//	return temp;
//}


//void PhanSo::operator-() {
//	TuSo = -TuSo;
//}

//member function
PhanSo PhanSo::operator+(int a) {
	PhanSo temp;
	temp.TuSo = TuSo + a * MauSo;
	temp.MauSo = MauSo;
	return temp;
}

//non Member functiom
PhanSo operator+(int a, PhanSo ps) {
	PhanSo temp;
	temp.SetTu(a*ps.LayMau()+ps.LayTu());
	temp.SetMau(ps.LayMau());
	return temp;
}


PhanSo PhanSo::operator+(PhanSo ps) {
	PhanSo temp;
	temp.TuSo = TuSo * ps.MauSo + ps.TuSo * MauSo;
	temp.MauSo = MauSo * ps.MauSo;
	return temp;
}


//Cach 2 toan tu so doi: Su dung non-member function
void operator-(PhanSo &h) {
	h.SetTu(-h.LayTu());
}
int main() {
	PhanSo A(1,1), B(1,2), C;
	++A;
	//cout << A;
	//C = 2 + A;
	//cin >> A;
	//cout << A;
	//C.Xuat();
	/*A.SetTu(3);
	A.SetMau(4);
	cout << A.LayTu() << endl;
	cout << A.LayMau() << endl;*/
	//-A;
	//A.Xuat();
	return 0;
}
