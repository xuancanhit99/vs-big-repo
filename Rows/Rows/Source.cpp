#include <iostream> 

using namespace std;


//1.
//double SumSin(int x) {
//	double sum = 0;
//	for (int i = 1; i <= x; i++) {
//		sum += sin(i);
//	}
//	return sum;
//}
//
//double SSum(int x) {
//	double Sum = 0;
//	for (int i = 1; i <= x; i++) {
//		Sum += i/SumSin(i);
//	}
//	return Sum;
//}
//
//int main() {
//	int n;
//	cout << "Enter n = "; cin >> n;
//	cout << SSum(n);
//	return 0;
//}


//2.




int giaiThua(int n)
{
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}

int i = 1;

double SQRT(int a) {
	double q=0;

	i = 0;
	while (i <= a) {
		i++;
		q += i;
	}
	return sqrt(q);
}


int main() {
	int n;
	cout << "Enter n = "; cin >> n;

	cout << SQRT(n) << " ";

	return 0;
}