#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	double x;
	cout << "Input b = ";
	cin >> a;
	cout << "Input c = ";
	cin >> b;
	if (a == 0) {
		if (b == 0) {
			cout << "Innumerable roots" << endl;
		}
		else {
			cout << "Non root" << endl;
		}
	}
	else {
		x = (double)-b / a;
		cout << "One root: x = " << x << endl;
	}
	return 0;
}
