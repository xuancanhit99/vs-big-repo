#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

template <typename type>
void display(vector<type> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main() {
	int x, y;
	cout << "\n Nhap vao 1 so lon hon 0";
	cin >> x;
	try {
		if (x < 0) {
			throw x;
		}
		cout << "\n Gia tri cua x " << x;
	}
	catch (int x) {
		cout << "\n Nhap so lon hon 0";
	}
	//display(number1);
	return 0;
}