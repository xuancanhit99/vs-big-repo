#include <iostream>

using namespace std;


//Tham Tri Va Tham Bien
//Tham Tri: pass-by-value

void ThamTri(int x) {
	x++;
}
void ThamChieu(int& x) {
	x++;
}
int main() {
	int b = 12;
	int& a = b; // a: nickname cua b, alias
	
	ThamChieu(b);
	//ThamTri(b);
	cout << b;

	cout << endl; system("pause");
	return 0;
}