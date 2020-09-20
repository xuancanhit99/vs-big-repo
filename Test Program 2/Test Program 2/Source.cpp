#include <iostream>

using namespace std;

int way = 0;

void Print(int i, int j) {
	way++;
	cout << "(" << way << ")" << endl;
	cout << "3 Blades: " << i << endl;
	cout << "4 Blades: " << j << endl;
}

void NumAna(int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if ((i * 3 + j * 4) == m) {
				Print(i, j);
			}
		}
	}
	if (way == 0) {
		cout << "Can not" << endl;
		cout << "3 Blades: 0" << endl;
		cout << "4 Blades: 0" << endl;
	}
}




int main() {

	int m;
	cout << "Enter M: "; cin >> m;
	NumAna(m);
	return 0;
}