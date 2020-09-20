#include <iostream>
#define PI 3.14159
using namespace std;


int main() {
	double a, x, w1, w2;
	cout << "Input a x: ";
	cin >> a >> x;
	w1 = a * log(abs(x));
	w2 = sqrt(a - x * x);

	if (x <= 0) {
		cout << "Does not exist the value w" << endl;
	}
	else
	{
		if (abs(x) < 1) {
				cout << "w = " << w1 << endl;
			}
			else
			{
				if (a >= x * x)
					cout << "w = " << w2 << endl;
				else
				{
					cout << "Does not exist the value w" << endl;
				}
			}
	}
	return 0;
}