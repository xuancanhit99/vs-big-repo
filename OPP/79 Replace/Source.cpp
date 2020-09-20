#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

template <typename type>
void display(vector<type> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main() {
	int size = 8;
	vector<int> numbers(10); // vecto chua 10 phan tu bang 0
	replace(numbers.begin(), numbers.end() - 5, 0, 1);
	string strInput[] = { "toi", "yeu", "em", "em", "co", "yeu", "toi", "khong" };
	vector<string> str(strInput, strInput + size);
	display(str);
	return 0;
}