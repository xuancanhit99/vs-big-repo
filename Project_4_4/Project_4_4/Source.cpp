#include <iostream>

using namespace std;

int main() {
	int i, j;
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 50; j++) {
			if (i > 0 && i && i < 7 && j>=0 && j < 8) {
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl; 
	}
	return 0;
}