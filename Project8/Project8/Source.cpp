#include <iostream>
#include <vector>


using namespace std;

int main() {
	//tao vecto de luu tru cac so nguyen
	vector<int> vec;
	//hien thi kich co co ban dau cua vector
	cout << "Kich co cua vector = " << vec.size() << endl;

	//day 5 gia tri vao vector
	for (int i = 0; i < 5; i++) {
		vec.push_back(i);
	}

	//hien thi kich co da mo rong
	cout << "Kich co vecto sau khi mo rong = " << vec.size() << endl;

	//truy cap5 gia tri cua vector
	for (int i = 0; i < 5; i++) {
		cout << "Gia tri cua vecto [" << i << "] = " << vec[i] << endl;
	}

	//su dung iterator de truy cap cac gia tri
	vector<int>::iterator v = vec.begin();
	while (v != vec.end()) {
		cout << "Gia tri cua v = " << *v << endl;
		v++;
	}

	//

	vector<double> myvec;

	vector<double> myvec1(4, 50); // myvec1={50, 50, 50, 50}
	myvec1.push_back(3.1);
	myvec1.push_back(2.2);
	myvec1.push_back(2.9);
	// myvec1={50, 50, 50, 50, 3.1, 2.2, 2.9}

	// truy cap den vi tri dau tien chua gia tri 50
	vector<double>::iterator vfirst = myvec1.begin();
	vfirst += 2; // truy cap den vi tri thu 3 

	vector<double>::iterator vlast = myvec1.end();
	vlast -= 2; // truy cap den vi tri thu 5 chua gia tri 3.1
	
	//range contructor
	vector<double> myvec2(vfirst, vlast);
	// myvec2={50, 50, 3.1}

	//thay doi gia tri
	*vfirst = 23;
	cout << myvec1[2]; // 23

	// Vector có hàm thành viên cho phép truy xuất trực tiếp đến giá trị của các 
	// phần tử trong nó
	vector<double> myvector(4, 50);
	myvector.push_back(22);
	myvector.push_back(33);
	myvector.push_back(44);

	cout << endl << endl << myvector.at(5) << endl << myvector[6] << endl;

	// hàm pop_back() chức năng là xóa đi phần tử cuối cùng của vector
	// cho phép chúng ta có thể chèn hoặc xóa bỏ phần tử của một mảng ban đầu mà
	// không quan tâm đến kích thước mảng

	// hàm thành viên swap() cho phép hoán đổi nội dung giữa 2 vector

	vector<int> first(3, 100);
	vector<int> second(4, 50);

	first.swap(second);
	//2 vecto first va second bi doi gia tri cho nhau

	// hàm insert()
	vector<int> myvector1(4, 10);
	myvector1.insert(myvector1.begin(), 5, 1);
	// 1 1 1 1 1 10 10 10 10

	/*
	vector<int> myvec(4, 100);
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	myvec.insert(myvector.begin(), vec.begin(), vec.end());
	// 1 2 3 100 100 100 100
	*/

	vector<int> vec1(4, 10);
	vec1.push_back(5);
	vec1.insert(vec1.begin(), 9);
	// 9 10 10 10 10 5


	// Với hàm thành viên empty() cho phép kiểm tra vector có rỗng hay không
	// nếu có trả về true và ngược lại

	vector<double> vecfirst;
	if (vecfirst.empty() == true) {
		cout << "No value in vecfirst" << endl;
	}


	// Dùng hàm thành viên clear để xóa hết các phẩn tử của vector
	vector<double> second1(5, 100);
	second1.push_back(23);
	second1.clear();


	// Lấy kích thước của vector bằng hàm size()
	vector<double> third(4, 22);
	cout << third.size();

	//Dùng hàm thành viên resize() hay resize(element, value) để thay đổi kích thước của vector
	vector<double> four(6, 10);
	four.resize(3);
	for (int i = 0; i < four.size(); i++) {
		cout << four[i] << endl;
	}
	//10 10 10

	four.resize(10);
	for (int i = 0; i < four.size(); i++) {
		cout << four[i] << endl;
	}
	//10 10 10 0 0 0 0 0 0 0



	return 0;
}



