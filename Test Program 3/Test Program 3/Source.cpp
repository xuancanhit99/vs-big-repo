#include <iostream>

using namespace std;

int Sum1toX(int x) {
	int Sum = 0;
	for (int i = 1; i <= x; i++) {
		Sum += i;
	}
	return Sum;
}


int main() {

	int m, n;
	cout << "Enter M: "; cin >> m;
	cout << "Enter N: "; cin >> n;
	cout << "Number of different rectangles: " << Sum1toX(m)*Sum1toX(n) << endl;


	return 0;
}