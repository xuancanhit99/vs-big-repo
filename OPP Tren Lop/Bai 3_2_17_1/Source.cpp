#include "Array.h"


int main() {
	int n;
	cin >> n;
	if (n <= 20 && n >= 5) {
		Array ar(n);
		ar.Creat();
		ar.Output();
	}
	return 0;
}