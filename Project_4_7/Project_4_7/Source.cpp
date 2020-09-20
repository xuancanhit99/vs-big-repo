#include <iostream> 

using namespace std;

int main() {
	int m, s=1, i, c, j;
	cout << "Input m = "; cin >> m;
	cout << "Input i = "; cin >> i;
	cout << "Input c = "; cin >> c;
	cout << "Random: ";
	for (j = 0; j < 10000; j++) {
		s = (m * s + i) % c;
		cout << s << "  ";
	}
	return 0;
}