#include "Integer1.h"
#include "Integer2.h"


int Max(Integer1& in1, Integer2& in2) {
	int max = in1.N;
	if (in2.A >= max)
		max = in2.A;
	if (in2.B >= max)
		max = in2.B;
	return max;
}


int main() {
	int a;
	int max;
	cin >> a;
	Integer1 in1(a);
	Integer2 in2;
	in2.Input2();
	max = Max(in1, in2);
	cout << "max = " << max;
	return 0;
}