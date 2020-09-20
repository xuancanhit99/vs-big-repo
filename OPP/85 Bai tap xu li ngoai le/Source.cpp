#include <iostream>
#include <stdexcept> // thu vien cua xu li ngoai le
#include <string>
#include <vector>
using namespace std;

//Mat khau co itnhat 8 ki tu
// Co li tu @


class EmailLegth : public runtime_error{
public:
	EmailLegth() : runtime_error("\n Email phai co it nhat 8 ki tu"){}
};


class Character : public runtime_error {
public:
	Character() : runtime_error("\n Email phai co dau @") {}
};

void GetEmail(vector<char> &EmailInput, string email) {
	cout << "\n Nhap email: ";
	cin >> email;
	copy(email.begin(), email.end(), back_inserter(EmailInput)); // lay chuoi bo vao vector cha
}

template <typename type>
void Display(vector<type> T) {
	for (int i = 0; i < T.size(); i++) {
		cout << T[i];
	}
}

int main() {
	string email;
	vector<char> EmailInput;
	GetEmail(EmailInput, email);
	//Display(EmailInput);
	try {
		if (EmailInput.size() <= 8) {
			throw EmailLegth();
		}
	}
	catch (EmailLegth &exception) {
		cout << exception.what();
	}
	try {
		vector<char>::iterator iter;
		iter = find(EmailInput.begin(), EmailInput.end(), '@');
		if (iter == EmailInput.end()) {
			throw Character();
		}
	}
	catch (Character &exception) {
		cout << exception.what();
	}
	cout << endl;
	system("pause");
	return 0;
}