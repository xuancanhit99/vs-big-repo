#include "Caculate.h"

int main() {
	Caculate ca;
	int a, b, c1, c2;
	char ch;
	cin >> a >> ch >> b;
	c1 = ca.Cclate(a, b, ch);
	int count = 1;
	while (1) {
		cin >> ch;
		if (count == 0 && ch != 'C') cout << endl;
		if (ch == 'C')
			break;
		count++;
		cin >> b;
		c1 = ca.Cclate(c1, b, ch);
		if (count == 3) {
			cout << c1;
			count = 0;
		}
	}
	return 0;
}