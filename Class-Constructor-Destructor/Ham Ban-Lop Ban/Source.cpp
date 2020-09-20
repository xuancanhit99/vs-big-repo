#include <iostream>

using namespace std;

//class HinhChuNhat
//{
//private:
//	float a, b;
//public:
//	HinhChuNhat(){}
//	HinhChuNhat(float a, float b) {
//		this->a = a;
//		this->b = b;
//	}
//	friend float DienTich(HinhChuNhat); //hàm friend có thể khai báo ở private hay public đều được 
//	~HinhChuNhat() {}
//};
//
//float DienTich(HinhChuNhat H) {
//	return H.a * H.b;
//}
//
//int main() {
//	HinhChuNhat H(2,3);
//	cout << "\n Dien tich = " << DienTich(H);
//	return 0;
//}


//forwarding declare: Khai bao truoc su dung sau
class ConHeo;
class ConGa {
	int khoiluong;
	friend void LamThit(ConGa, ConHeo);
public:
	ConGa(int a) {
		khoiluong = a;
	}
};

class ConHeo {
	int khoiluong;
	friend void LamThit(ConGa, ConHeo);
public:
	ConHeo(int a) {
		khoiluong = a;
	}
};


void LamThit(ConGa ga, ConHeo heo) {
	if (ga.khoiluong >= heo.khoiluong) {
		cout << "\n lam thit con ga";
	}
	else
		cout << "\n lam thit con heo";
}


int main() {
	ConGa ga(6);
	ConHeo heo(6);
	LamThit(ga, heo);
}