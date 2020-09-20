#include <iostream>
using namespace std;

class Integer2;

class Integer1 {
	
public:
	int N;
	Integer1(int n);
	friend int Max(Integer1&, Integer2&);
};