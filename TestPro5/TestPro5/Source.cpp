#include <iostream>

using namespace std;


int a1=0, a2=0;
double Sx(int n, int k) {
	
	for (int i = 0; i < k; i++) {
		if (n % 2 == 0) {
			a1 = (n / 2) - 1; 
			a2 = n / 2;
			return Sx(a2, k - 1);
		}
		if (n%2!=0)
		{
			a1 = n / 2;
			a2 = a1;
			return Sx(a1, k - 1);
		}
	}
	return n;
}


int main() {
	int n, k;
	while (1) {
		cout << "N: "; cin >> n;
		cout << "K: "; cin >> k;
		int h = k;
		Sx(n, k);

		if (h >= 3) {
			cout << "a1: " << a1 +1 << endl;
			cout << "a2: " << a2 +1 << endl;
		}
		else
		{
			cout << "a1: " << a1 << endl;
			cout << "a2: " << a2 << endl;

		}

		char o;
		cout << endl << "Do you want contunue?(y/n): "; cin >> o;
		if (o == 'n')
			break;
	}

	
	return 0;
}