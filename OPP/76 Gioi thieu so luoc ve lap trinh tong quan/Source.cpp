#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main() {
	vector<int> numbers;
	for (int i = 0; i < 10; i++) {
		numbers.push_back(i);
	}
	int sum = 0;
	/*for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}*/
	sum = accumulate(numbers.begin(), numbers.end(), 0);
	cout << sum << endl;
	
	vector<string> str;
	str.push_back("Vu ");
	str.push_back("Xuan ");
	str.push_back("Canh");
	string strOutput;
	strOutput = accumulate(str.begin(), str.end(), string(""));
	cout << strOutput << endl;
	return 0;
}