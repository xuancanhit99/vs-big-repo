#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

template <typename type>
void display(vector<type> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main() {
// Cach copy du lieu tu array sang vector
	int size = 10;
	int number[] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> num(number, number + size);
	display(num);
	return 0;
}