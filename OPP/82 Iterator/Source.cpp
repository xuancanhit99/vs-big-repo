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
	vector<int> number1;
	vector<int> number2;
	for (int i = 1; i <= 10; i++) {
		number1.push_back(i);
	}
	/*for (vector<int>::iterator iter = number1.begin(); iter < number1.end(); iter++) {
		cout << *iter << endl;
	}*/

	for (vector<int>::reverse_iterator r = number1.rbegin(); r < number1.rend(); r++) {
		cout << *r << endl;
	}

	//display(number1);
	return 0;
}