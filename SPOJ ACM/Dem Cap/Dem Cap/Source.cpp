#include <iostream>
#include <string>
#define MAX 100

using namespace std;

int StringToArr(string inS, int* inInt) {
	int i;
	for (i = 0; i < inS.length(); i++) {
		*(inInt + i) = inS[i] - 48;
	}
	return i;
}

int Result(int* inInt, int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (*(inInt + i) == 1) {
			for (int j = i; j < len; j++) {
				if (*(inInt + j) == 2) {
					count++;
				}
			}
		}
	}
	return count;
}
int main() {
	string inS;
	int* inInt = NULL;
	inInt = new int[MAX];
	cin >> inS;
	int len = StringToArr(inS, inInt);
	cout << Result(inInt, len);
	delete[] inInt;
	return 0;
}