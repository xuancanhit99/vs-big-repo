#include "Caculate.h"

int main() {
	Caculate ca;
	int a, b;
	char ch;
	cin >> a >> ch >> b;
	int c1 = ca.Cclate(a, b, ch);
	cin >> ch >> b;
	int c2 = ca.Cclate(c1, b, ch);
	cin >> ch >> b;
	int c3 = ca.Cclate(c2, b, ch);
	cout << c3;
	return 0;
}
