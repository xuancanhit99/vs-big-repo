//#include "NhanVien.h"
//#include "NVVanPhong.h"
//#include "NVSanXuat.h"
//#include "NVQuanLy.h"


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanVien {
protected:
	string HoTen, NgaySinh;
	float LuongCoBan, Luong;
public:
	string GetName() {
		return HoTen;
	}
	void Nhap();
	void Xuat();
	NhanVien() {
		LuongCoBan = 200000;
	}
	~NhanVien() {}
};


class NVQuanLy : public NhanVien {
private:
	float HeSo, Thuong;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};


class NVSanXuat : public NhanVien {
private:
	int SoSanPham;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};

class NVVanPhong : public NhanVien {
private:
	int SoNgayLamViec;
	float TroCap;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};


class CongTy
{
private:
	vector<NVQuanLy> NhanVienQuanLy;
	vector<NVSanXuat> NhanVienSanXuat;
	vector<NVVanPhong> NhanVienVanPhong;
public:
	void Nhap();
	void Xuat();
	float TinhTongLuong();
	void TimKiemNV(string name);
};


void NhanVien::Nhap() {
	cin.ignore();
	fflush(stdin);
	//int a;
	cout << "\n Nhap ho ten: ";
	getline(cin, HoTen);//lay nguyen dong
	fflush(stdin);
	cout << "\n Nhap vao ngay sinh ";
	getline(cin, NgaySinh);
}

void NhanVien::Xuat() {
	cout << "\n Ho Ten: " << HoTen;
	cout << "\n Ngay Sinh: " << NgaySinh;
	cout << "\n Luong co ban: " << LuongCoBan;
}


void NVQuanLy::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\n He So: ";
		cin >> HeSo;
	} while (HeSo < 0);
	do {
		cout << "\n Thuong: ";
		cin >> Thuong;
	} while (Thuong < 0);

}

void NVQuanLy::Xuat() {
	NhanVien::Xuat();
	cout << "\n He So: " << HeSo;
	cout << "\n Thuong: " << Thuong << endl;
}

float NVQuanLy::TinhLuong() {
	Luong = LuongCoBan * HeSo + Thuong;
	return Luong;
}


void NVSanXuat::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\n So san pham: ";
		cin >> SoSanPham;
	} while (SoSanPham < 0);
}

void NVSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "\n So San Pham: " << SoSanPham << endl;
}


float NVSanXuat::TinhLuong() {
	Luong = SoSanPham * 2000 + LuongCoBan;
	return Luong;
}

void NVVanPhong::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\n So ngay lam viec: ";
		cin >> SoNgayLamViec;
	} while (SoNgayLamViec < 0);
	do {
		cout << "\n Tro Cap: ";
		cin >> TroCap;
	} while (TroCap < 0);
}

void NVVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "\n So ngay lam viec: " << SoNgayLamViec;
	cout << "\n Tro Cap: " << (size_t)TroCap << endl;
}


float NVVanPhong::TinhLuong() {
	Luong = LuongCoBan + TroCap + SoNgayLamViec * 100000;
	return Luong;
}

void CongTy::Nhap() {
	int LuaChon;
	cout << "\n-------Menu-------";
	cout << "\n 1. Nhap nhan vien van phong!";
	cout << "\n 2. Nhap nhan vien san xuat!";
	cout << "\n 3. Nhap nhan vien quan li!";
	cout << "\n 4.Thoat";
Again:
	cout << "\n Nhap lua chon cua ban: ";
	cin >> LuaChon;
	switch (LuaChon)
	{
	case 1: {
		NVVanPhong VP;
		VP.Nhap();
		NhanVienVanPhong.push_back(VP);
		goto Again;
	}
	case 2: {
		NVSanXuat SX;
		SX.Nhap();
		NhanVienSanXuat.push_back(SX);
		goto Again;
	}
	case 3: {
		NVQuanLy QL;
		QL.Nhap();
		NhanVienQuanLy.push_back(QL);
		goto Again;
	}
	case 4: {
		break;
	}
	default:
		goto Again;
		break;
	}


	/*do {
		cout << "\n-------Menu-------";
		cout << "\n 1. Nhap nhan vien van phong!";
		cout << "\n 2. Nhap nhan vien san xuat!";
		cout << "\n 3. Nhap nhan vien quan li!";
		cout << "\n 4.Thoat";
		do {
			cout << "\n Nhap lua chon cua ban: ";
			cin >> LuaChon;
			if (LuaChon < 1 || LuaChon > 4)
				cout << "\n Ban da nhap sai lua chon!";
		} while (LuaChon < 1 || LuaChon > 4);
		if (LuaChon == 1) {
			NVVanPhong VP;
			VP.Nhap();
			NhanVienVanPhong.push_back(VP);
		}
		else if (LuaChon == 2) {
			NVSanXuat SX;
			SX.Nhap();
			NhanVienSanXuat.push_back(SX);
		}
		else if (LuaChon == 3) {
			NVQuanLy QL;
			QL.Nhap();
			NhanVienQuanLy.push_back(QL);
		}

		cin >> LuaChon;
	} while (LuaChon != 4);*/
}

void CongTy::Xuat() {
	cout << "\n ----------------Danh sach nhan Vien Quan Ly: " << endl;
	for (int i = 0; i < NhanVienQuanLy.size(); i++) {
		NhanVienQuanLy[i].Xuat();
	}
	cout << "\n ----------------Danh sach nhan Vien San Xuat: " << endl;
	for (int i = 0; i < NhanVienSanXuat.size(); i++) {
		NhanVienSanXuat[i].Xuat();
	}
	cout << "\n ----------------Danh sach nhan Vien Van Phong: " << endl;
	for (int i = 0; i < NhanVienVanPhong.size(); i++) {
		NhanVienVanPhong[i].Xuat();
	}
}


float CongTy::TinhTongLuong() {
	float Tong = 0;
	for (int i = 0; i < NhanVienQuanLy.size(); i++) {
		Tong += NhanVienQuanLy[i].TinhLuong();
	}
	for (int i = 0; i < NhanVienSanXuat.size(); i++) {
		Tong += NhanVienSanXuat[i].TinhLuong();
	}
	for (int i = 0; i < NhanVienVanPhong.size(); i++) {
		Tong += NhanVienVanPhong[i].TinhLuong();
	}

	return Tong;
}



void CongTy::TimKiemNV(string name) {
	bool Check = false;
	cout << "\n -----------------Ket qua tim kiem ";
	for (int i = 0; i < NhanVienQuanLy.size(); i++) {
		if (NhanVienQuanLy[i].GetName() == name) {
			NhanVienQuanLy[i].Xuat();
			Check == true;
			cout << endl;
		}
			
	}
	for (int i = 0; i < NhanVienSanXuat.size(); i++) {
		if (NhanVienSanXuat[i].GetName() == name) {
			NhanVienSanXuat[i].Xuat();
			Check == true;
			cout << endl;
		}
	}
	for (int i = 0; i < NhanVienVanPhong.size(); i++) {
		if (NhanVienVanPhong[i].GetName() == name) {
			NhanVienVanPhong[i].Xuat();
			Check == true;
			cout << endl;
		}
	}
	if (!Check)
		cout << "\n Khong tim thay nhan vien co ten la " << name;
}

int main() {
	CongTy ct;
	ct.Nhap();
	ct.Xuat();
	ct.TimKiemNV("Nguyen Van Khoa");
	system("pause");
	return 0;
}

// Bia 58
