#include <iostream>

using namespace std;


int main() {
	int i, a;
	cout << "Input N: ";
	cin >> a;
	if (a > 0) {
		cout << a << endl;
		for (i = 1; i < 10; i++) {
			a++;
			cout << a << endl;
		}
	}
	else {
		for (i = 0; i < 10; i++) {
			cout << i << endl;
		}
	}
	return 0;
}