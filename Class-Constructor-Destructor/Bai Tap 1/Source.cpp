//#include <iostream>
//
//using namespace std;
//
//class SoPhuc {
//private:
//	int PhanThuc, PhanAo;
//public:
//	SoPhuc() { // ham khoi tao mac dinh
//		PhanThuc = 0;
//		PhanAo = 0;
//	}
//	SoPhuc(int phanthuc, int phanao);
//};
//
//SoPhuc::SoPhuc(int phanthuc, int phanao) {
//	PhanThuc = phanthuc;
//	PhanAo = phanao;
//}
//
//class ThoiGian {
//private:
//	int Gio, Phut, Giay;
//public:
//	ThoiGian() {
//		Gio = 0;
//		Phut = 0;
//		Giay = 0;
//	}
//	ThoiGian(int gio, int phut, int giay) {
//		Gio = gio;
//		Phut = phut;
//		Giay = giay;
//	}
//	ThoiGian(int gio, int giay) {
//		Gio = gio;
//		Giay = giay;
//	}
//
//};
//
//
//
//class HocSinh {
//private:
//	int MSSV;
//	string HoTen;
//	string DiaChi;
//	int DiemToan;
//	int DiemVan;
//	int DiemAnh;
//public:
//	HocSinh() {
//		MSSV = 0;
//	};
//	HocSinh(string hoten, int mssv, string diachi, int diemtoan, int diemvan, int diemanh) {
//		HoTen = hoten;
//		MSSV = mssv;
//		DiaChi = diachi;
//		DiemToan = diemtoan;
//		DiemVan = diemvan;
//		DiemAnh = diemanh;
//	}
//	// Cu phap
//	//Truyen tham chieu
//	HocSinh(const HocSinh& hs) {
//		HoTen = hs.HoTen;
//		MSSV = hs.MSSV;
//		DiaChi = hs.DiaChi;
//		DiemToan = hs.DiemToan;
//		DiemVan = hs.DiemVan;
//		DiemAnh = hs.DiemAnh;
//	}
//	void Xuat() {
//		cout << "Ho Ten: " << HoTen << endl;
//		cout << "MSSV: " << MSSV << endl;
//		cout << "Dia Chi: " << DiaChi << endl;
//		cout << "Diem Toan Diem Van Diem Anh: " << DiemToan << " " << DiemVan << " " << DiemAnh << endl;
//	}
//};
//
//
//
//int main() {
//	SoPhuc sp;
//	SoPhuc sp1(1, 2);
//	ThoiGian time1(3, 2, 1);
//	ThoiGian time2(4, 4);
//	HocSinh hs;
//	HocSinh hs1("Vu Xuan Canh", 36, "Moscow", 10, 10 ,10);
//	HocSinh hs2(hs1);
//	hs2.Xuat();
//	return 0;
//}