//#include <iostream>
//
//using namespace std;
//
//class PhanSo {
//private:
//	int TuSo, MauSo;
//public:
//	PhanSo() { // ham khoi tao mac dinh
//		TuSo = 0;
//		MauSo = 1;
//	}
//	PhanSo(int tu, int mau);
//	void Cong() {
//		MauSo++;
//	}
//};
//
//PhanSo::PhanSo(int tu, int mau) {
//	TuSo = tu;
//	MauSo = mau;
//}
//
//class HocSinh {
//private:
//	int MSSV;
//	string HoTen;
//public:
//	//HocSinh(){}
//	HocSinh(int ms, string ten) {
//		MSSV = ms;
//		HoTen = ten;
//	}
//	// Cu phap
//	//Truyen tham chieu
//	HocSinh(const HocSinh & hs) {
//		HoTen = hs.HoTen;
//	}
//};
//
//
//
//int main() {
//	HocSinh hs1(1, "khoa"), hs2;
//	hs2 = HocSinh(hs1);
//	cout << endl;
//	system("pause");
//	return 0;
//}