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
	// ao phai khai bao cu the
	virtual void Nhap();
	virtual void Xuat();
	//thuan ao khai bao chung chung lop con dinh nghia rieng tung cai
	virtual  float TinhLuong() = 0;
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
	vector<NhanVien*> DSNhanVien;
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
		cout << "\n Ban dang nhap nhan vien van phong: ";
		NhanVien* temp = new NVVanPhong;
		temp->Nhap();
		DSNhanVien.push_back(temp);
		goto Again;
	}
	case 2: {
		cout << "\n Ban dang nhap nhan vien san xuat: ";
		NhanVien* temp = new NVSanXuat;
		temp->Nhap();
		DSNhanVien.push_back(temp);
		goto Again;
	}
	case 3: {
		cout << "\n Ban dang nhap nhan vien quan li: ";
		NhanVien* temp = new NVQuanLy;
		temp->Nhap();
		DSNhanVien.push_back(temp);
		goto Again;
	}
	case 4: {
		break;
	}
	default:
		goto Again;
		break;
	}
}

void CongTy::Xuat() {
	for (int i = 0; i < DSNhanVien.size(); i++) {
		DSNhanVien[i]->Xuat();
	}
}


float CongTy::TinhTongLuong() {
	float Tong = 0;
	for (int i = 0; i < DSNhanVien.size(); i++) {
		Tong += DSNhanVien[i]->TinhLuong();
	}

	return Tong;
}



void CongTy::TimKiemNV(string name) {
	int Check = 0;
	cout << "\n -----------------Ket qua tim kiem ";
	for (int i = 0; i < DSNhanVien.size(); i++) {
		if (DSNhanVien[i]->GetName() == name) {
			Check = 1;
			cout << endl << Check;
			DSNhanVien[i]->Xuat();
			
		}
	}
	if (!Check)
		cout << "\n Khong tim thay nhan vien co ten la " << name;
}

int main() {
	CongTy congty;
	congty.Nhap();
	congty.Xuat();
	cout << "\n Tong luong la: " << (size_t)congty.TinhTongLuong();
	congty.TimKiemNV("Vu Xuan Canh");
	system("pause");
	return 0;
}
