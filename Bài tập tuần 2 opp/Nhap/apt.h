#ifndet TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <math.h>

using namespace std;
class triangle {
private:
	int A, B, C;
public:
	triangle(int a, int b, int c);
	int Check();
	void P();
	void S();
}
#endif