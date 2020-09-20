#include <iostream>
#include <string>
using namespace std;

class HocSinh {
	//Khai bao(cai dat) thuoc tinh
	//Khia bao(cai dat) phuong thuc
	//private, protected, public
	//Khai bao thuoc tinh: Giong khai bao bien
	//Khai bao phuong thuc: Giong khai bao ham
	//Private: chi su dung trong class
	//Public: The gioi ben ngoai co the su dung
	//Protected: Se giai thich khi hoc ke thua
	//Neu khong co tu khoa private hay public o phia truoc thi chuong trinh se tu hieu la private
private: // ra ngoai ham main khong truy cap duoc
	string Hoten;
	void Xuat();
public: // ra ngoai ham main van truy cap duoc
	string DiaChi;
	void Nhap();
	float TinhDiem();
};

int main() {
	HocSinh HS; //Cach khoi tao 1 doi tuong tu class
	HS.DiaChi = "Quang Xuong, Thanh Hoa";
	HS.Nhap(); // Cach truy cap den thanh phan cua 1 class
	system("pause");
	return 0;
}