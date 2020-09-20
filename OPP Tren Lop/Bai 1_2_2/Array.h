#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Array {
private:
	int N;
	int A[10];  // Original array
	int B[10]; // Array is reversed
public:
	void Input();
	void Output();
	void Reverse();
};
