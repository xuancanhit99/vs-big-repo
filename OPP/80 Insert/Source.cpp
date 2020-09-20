#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

template <typename type>
void display(vector<type> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main() {
	int size = 8;
	vector<int> number1;
	vector<int> number2;
	deque<int > number3;
	number3.push_back(4);
	number3.push_back(5);
	number3.push_back(6);
	number1.push_back(1);
	number1.push_back(2);
	number1.push_back(3);
	number2.push_back(4);
	number2.push_back(5);
	number2.push_back(6);
	/*for (int i = 0; i < number2.size(); i++) {
		number1.push_back(number2[i]);
	}*/
	copy(number2.begin(), number2.end(), back_inserter(number1)); // chen vao sau
	//copy(number2.begin(), number2.end(), front_inserter (number3));
	display(number1);
	return 0;
}