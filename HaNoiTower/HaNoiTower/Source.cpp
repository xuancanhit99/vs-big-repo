#include <iostream>

using namespace std;

int d = 0;
void Tower(int n, char a, char b, char c) {
	if (n == 1) {
		if (d % 5 == 0) cout << endl;
		cout << "\t" << a << "=>" << c << " "; d++;
		return;
	}
	
	Tower(n - 1, a, c, b);
	Tower(1, a, b, c);
	Tower(n - 1, b, a, c);
}
int main() {
	char a = '1', b = '2', c = '3';
	int n;
	cout << "Enter n = ";
	cin >> n;
	Tower(n, a, b, c);
}