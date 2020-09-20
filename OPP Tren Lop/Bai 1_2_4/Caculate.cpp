
#include "Caculate.h"

int Caculate::Cclate(int a, int b, char ch) {
	A = a;
	B = b;
	CH = ch;
	if (CH == '+')
		return A + B;
	if (CH == '-')
		return A - B;
	if (CH == '*')
		return A * B;
	if (CH == '%')
		return A % B;
}