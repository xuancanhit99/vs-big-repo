#include "triangle.h"

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	triangle tr(a, b, c);
	tr.P();
	cout << endl;
	tr.S();
	return(0);
}
