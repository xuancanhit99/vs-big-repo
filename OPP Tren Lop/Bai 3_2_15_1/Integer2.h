#include <iostream>
using namespace std;

class Integer1;
class Integer2{
public:
	int A, B;
	void Input2();
	friend int Max(Integer1&, Integer2&);
};
