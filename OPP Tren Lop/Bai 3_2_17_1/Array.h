#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <iomanip>
#define MAX 20

using namespace std;

class Array {
private:
	int N;
	int* a = new int[MAX];
public:
	Array(int n);
	void Creat();
	void Output();
};
#endif