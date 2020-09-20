#include <iostream>

using namespace std;


char Input() {
	cout << "Nhap vao ki tu: ";
	cin >> a;
	return a;
}

int Chuyen(char a) {
	return int(a);
}

char Kt(int b) {
	char a;
	while (b < 48 || b > 57) {
		a = Input();
		if (b >= 48 || b <= 57)
			break;
	}
	Kt(a);
	return a;
}

int main() {
	char a;
	a = Input();
	int b = Chuyen(a);
	Kt(b);
	return 0;
}