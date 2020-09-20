#include <iostream>
using namespace std;


//int add(int a, int b);
//auto add(int a, int b) -> int; // khai bao kieu khac cua dong tren


//Ta co the dung de tu dong xac dinh kieu tra ve cua ham
auto add(int a, int b) {
	return a + b;
}

//int add(int a, int b) {
//	return a + b;
//}


int main() {
	//// Xac dinh ro rang bien a1 la bien cuc bo
	//auto int a1(38); // truoc phien ban C++11

	////mac dinh da la bien cuc bo
	//int a2(38); // y nghia tuong tu cau lenh tren


	//char a1 = 'A'; 
	//int a2 = 1;
	//float a3 = 1.0F;
	//double a4 = 1.0;
	//tu khoa auto co the tu dong xac dinh kieu du lieu
	auto a1 = 'A'; // bat buoc phai khai bao phan tu thuoc kieu du lieu do
	cout << "type of a1: " << typeid(a1).name() << endl;
	auto a2 = 1;
	auto a3 = 1.0F;
	auto a4 = 1.0;


	//ham add() return kieu int => bien sum kieu int
	auto sum = (3, 8);
	cout << "type of sum: " << typeid(sum).name() << endl;



	// tu khoa auto khong the lam tham so ham-auto xac dinh kieu du lieu tai thoi diem bien dich
	system("pause");
	return 0;
}

//https://www.howkteam.vn/course/khoa-hoc-lap-trinh-c-can-ban/tu-khoa-auto-trong-c11the-auto-keyword-2697