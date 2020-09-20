#include <iostream>

using namespace std;
int Sum = 0;
int count = 0;
void Rep(int N) {
	
	for (int i = 1; i <= 4; i++) {
		Sum += i;
		if (Sum == N) {
			count++;
			break;
		}
			
		Rep(N);
	}
}

int main() {
	int N;
	cin >> N;

	return 0;
}