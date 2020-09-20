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
	vector<int> numbers(10);
	/*for (int i = 0; i < numbers.size(); i++) {
		if (i <= 3) {
			numbers[i] = 4;
		}
		else if (i <= 5) {
			numbers[i] = 5;
		}
		else if (i <= 9) {
			numbers[i] = 6;
		}
	}*/

	fill(numbers.begin(), numbers.begin() + 4, 4);
	fill(numbers.begin() + 4, numbers.begin() + 6, 5);
	fill(numbers.begin() + 6, numbers.end(), 6);

	int size = 3;
	string strInput[] = { "Vu", "Xuan", "Canh" };
	vector<string> str(strInput, strInput + size);
	//fill(str.begin(), str.end(), "hello");
	display(str);
	display(numbers);
	return 0;
}