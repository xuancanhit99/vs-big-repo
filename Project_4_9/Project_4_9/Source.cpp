#include <iostream>
#include <cstring>
#include <algorithm> //copy arr

using namespace std;
const char MAX = 50;
const char C55 = 55;
const char C48 = 48;


void Conver10ToAll(int n, int b) { // Dec to All, n la so, con b la he co so can chuyen sang
	if (n > 0 && b >= 2 && b <= 16) {
		int i;
		char arr[MAX];
		int count = 0;
		int m;
		while (n > 0) {
			if (b > 10) {
				m = n % b;
				if (m >= 10) {
					arr[count] = (char)(m + C55);
					count++;
				}
				else {
					arr[count] = (char)(m + C48);
					count++;
				}
			}
			else {
				arr[count] = (char)((n % b) + C48);
				count++;
			}
			n = n / b;
		}
		for (i = count - 1; i >= 0; i--) {
			cout << arr[i];
		}
		cout << endl;
	}
	else {
		cout << "Input is false" << endl;
	}
}

void DaoNguoc(char a[], int n) {
	int i; 
	for (i = 0; i < n / 2; i++) {
		int temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}

void CharToInt(char a[], int b[], int n) {
	int i; 
	for (i = 0; i < n; i++) {
		if (a[i] == 'A')
			b[i] = 10;
		else if (a[i] == 'B')
			b[i] = 11;
		else if (a[i] == 'C')
			b[i] = 12;
		else if (a[i] == 'D')
			b[i] = 13;
		else if (a[i] == 'E')
			b[i] = 14;
		else if (a[i] == 'F')
			b[i] = 15;
		else
			b[i] = (int)a[i] - 48;
	}
}

double ConvertAllTo10(int a[], int n, int x) {
	int i;
	double s = 0;
	for (i = 0; i < n; i++) {
		s += a[i] * pow(x, i);
	}
	return s;
}

void In(char a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << a[i];
	}
}

int main() {
	int a, x, y, len;
	char k[MAX], kin[MAX];
	int l[MAX];
	double s;
	cout << "    A     =>    B" << endl;
	cout << "      x           y" << endl;
	cout << "Enter x (2 <= x <= 16) " << endl;
	cout << "x = "; cin >> x;
	if (x >= 2 && x <= 16) {
		if (x == 10) {
			cout << "\nEnter A (A > 0)" << endl;
			cout << "A = "; cin >> a;
			cout << "\nEnter y (2 <= x <= 16) " << endl;
			cout << "y = "; cin >> y;
			cout << endl;
			cout << "    " << a << "     =     ";
			Conver10ToAll(a, y);
			cout << "      " << x << "             " << y << endl;
		}
		else {
			cout << "\nEnter A (A > 0)" << endl;
			cout << "A = ";
			cin.ignore();
			cin.getline(k, 30);
			len = strlen(k);
			copy_n(k, len ,kin); // copy arr
			DaoNguoc(k, len);
			CharToInt(k, l, len);
			cout << "\nEnter y (2 <= x <= 16) " << endl;
			cout << "y = "; cin >> y;
			s = ConvertAllTo10(l, len, x);
			cout << endl;
			cout << "    ";
			In(kin, len);
			cout << "     =     ";
			Conver10ToAll(s, y);
			cout << "      " << x << "             " << y << endl;
		}
	}
	else {
		cout << "Input is false" << endl;
	}
	return 0;
}
