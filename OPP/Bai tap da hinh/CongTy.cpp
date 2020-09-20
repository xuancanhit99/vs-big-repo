//#include "CongTy.h"
//
//void CongTy::Nhap() {
//	int LuaChon;
//	cout << "\n-------Menu-------";
//	cout << "\n 1. Nhap nhan vien van phong!";
//	cout << "\n 2. Nhap nhan vien san xuat!";
//	cout << "\n 3. Nhap nhan vien quan li!";
//	cout << "\n 4.Thoat";
//Again:
//	cout << "\n Nhap lua chon cua ban: ";
//	cin >> LuaChon;
//	switch (LuaChon)
//	{
//	case 1: {
//		NVVanPhong VP;
//		VP.Nhap();
//		NhanVienVanPhong.push_back(VP);
//		goto Again;
//	}
//	case 2: {
//		NVSanXuat SX;
//		SX.Nhap();
//		NhanVienSanXuat.push_back(SX);
//		goto Again;
//	}
//	case 3: {
//		NVQuanLy QL;
//		QL.Nhap();
//		NhanVienQuanLy.push_back(QL);
//		goto Again;
//	}
//	case 4: {
//		break;
//	}
//	default:
//		goto Again;
//		break;
//	}
//
//
//	/*do {
//		cout << "\n-------Menu-------";
//		cout << "\n 1. Nhap nhan vien van phong!";
//		cout << "\n 2. Nhap nhan vien san xuat!";
//		cout << "\n 3. Nhap nhan vien quan li!";
//		cout << "\n 4.Thoat";
//		do {
//			cout << "\n Nhap lua chon cua ban: ";
//			cin >> LuaChon;
//			if (LuaChon < 1 || LuaChon > 4)
//				cout << "\n Ban da nhap sai lua chon!";
//		} while (LuaChon < 1 || LuaChon > 4);
//		if (LuaChon == 1) {
//			NVVanPhong VP;
//			VP.Nhap();
//			NhanVienVanPhong.push_back(VP);
//		}
//		else if (LuaChon == 2) {
//			NVSanXuat SX;
//			SX.Nhap();
//			NhanVienSanXuat.push_back(SX);
//		}
//		else if (LuaChon == 3) {
//			NVQuanLy QL;
//			QL.Nhap();
//			NhanVienQuanLy.push_back(QL);
//		}
//
//		cin >> LuaChon;
//	} while (LuaChon != 4);*/
//}
//
//void CongTy::Xuat() {
//	cout << "\n ----------------Danh sach nhan Vien Quan Ly: " << endl;
//	for (int i = 0; i < NhanVienQuanLy.size(); i++) {
//		NhanVienQuanLy[i].Xuat();
//	}
//	cout << "\n ----------------Danh sach nhan Vien San Xuat: " << endl;
//	for (int i = 0; i < NhanVienSanXuat.size(); i++) {
//		NhanVienSanXuat[i].Xuat();
//	}
//	cout << "\n ----------------Danh sach nhan Vien Van Phong: " << endl;
//	for (int i = 0; i < NhanVienVanPhong.size(); i++) {
//		NhanVienVanPhong[i].Xuat();
//	}
//}
//
//
//float CongTy::TinhTongLuong() {
//	float Tong = 0;
//	for (int i = 0; i < NhanVienQuanLy.size(); i++) {
//		Tong += NhanVienQuanLy[i].TinhLuong();
//	}
//	for (int i = 0; i < NhanVienSanXuat.size(); i++) {
//		Tong += NhanVienSanXuat[i].TinhLuong();
//	}
//	for (int i = 0; i < NhanVienVanPhong.size(); i++) {
//		Tong += NhanVienVanPhong[i].TinhLuong();
//	}
//
//	return Tong;
//}
//
//
//
//void CongTy::TimKiemNV(string name) {
//	bool Check = false;
//	cout << "\n -----------------Ket qua tim kiem ";
//	for (int i = 0; i < NhanVienQuanLy.size(); i++) {
//		if (NhanVienQuanLy[i].GetName() == name) {
//			NhanVienQuanLy[i].Xuat();
//			Check == true;
//			cout << endl;
//		}
//			
//	}
//	for (int i = 0; i < NhanVienSanXuat.size(); i++) {
//		if (NhanVienSanXuat[i].GetName() == name) {
//			NhanVienSanXuat[i].Xuat();
//			Check == true;
//			cout << endl;
//		}
//	}
//	for (int i = 0; i < NhanVienVanPhong.size(); i++) {
//		if (NhanVienVanPhong[i].GetName() == name) {
//			NhanVienVanPhong[i].Xuat();
//			Check == true;
//			cout << endl;
//		}
//	}
//	if (!Check)
//		cout << "\n Khong tim thay nhan vien co ten la " << name;
//}
