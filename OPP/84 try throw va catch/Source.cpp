#include <iostream>
#include <stdexcept> // thu vien cua xu li ngoai le

using namespace std;




class LessThanZero : public runtime_error {
public:
	LessThanZero() : runtime_error("\n So duoc nhap be hon 0 ") {} // viet chong loi 
};


class MoreThanTen : public runtime_error {
public:
	MoreThanTen() : runtime_error("\n So duoc nhap lon hon 10"){}
};

int main() {
	int x;
	cout << "\n Nhap vao 1 so lon hon 0: ";
	cin >> x;
	try { // bo doan code co the xay ra loi
		if (x < 0) { // neu nhap loi
			throw LessThanZero(); // nem ra cai loi
		}
		if (x > 10) {
			throw MoreThanTen();
		}
		cout << "\n Gia tri cua x " << x;
	}
	catch (LessThanZero &exc) {
		cout << exc.what() << endl;// tra ve nguyen nhan loi (da viet chong len roi)
		x = 0;
	}
	catch (MoreThanTen& exc) {
		cout << exc.what() << endl;// tra ve nguyen nhan loi (da viet chong len roi)
		x = 10;
	}
	cout << x;
	//display(number1);
	return 0;
}