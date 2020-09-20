#include <iostream >
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define Max 100
int main() {
	do {

		int n, t;

		cout << "Nhap n: ";
		cin >> n;
		int x = n;
		n = abs(n);
		int dem = 0;
		do {
			n /= 10;
			dem++;
		} while (n);
		int tong = 0;
		while (x >= 0 && dem > 0) {
			dem--;
			t = x / pow(10, dem);
			x %= int(pow(10, dem));
			cout << t << endl;
		}
		cout << "Nhap phim ESC de thoat!\n";
	} while (_getch() != 27);
	return 0;
