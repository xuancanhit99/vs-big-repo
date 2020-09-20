#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>
using namespace std;
long long c = 0, m = 0;
void ReheapifyDown(int arr[], int n) {
	for (int i = 0; i < n / 2; i++) {
		if (2 * i + 2 < n) {
			if (arr[i] < arr[2 * i + 1])
				swap(arr[i], arr[2 * i + 1]);
			if (arr[i] < arr[2 * i + 2])
				swap(arr[i], arr[2 * i + 2]);
		}
		else if (2 * i + 1 < n) {
			if (arr[i] < arr[2 * i + 1])
				swap(arr[i], arr[2 * i + 1]);
		}
		else break;
	}
}

void MakeHeap(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[(i - 1) / 2])
			swap(arr[i], arr[(i - 1) / 2]);
		int k = i;
		while (k > 0) {
			if (arr[k] > arr[(k - 1) / 2])
				swap(arr[k], arr[(k - 1) / 2]);
			k--;
		}
	}
}


void HeapSort(int arr[], int n) {
	MakeHeap(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int m = n;
	while (m > 1) {
		swap(arr[0], arr[m - 1]);
		ReheapifyDown(arr, m - 1);
		m--;

	}
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	clock_t startt = clock();
	HeapSort(arr, n);
	clock_t finish = clock();
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	double duration = (double)(finish - startt) / CLOCKS_PER_SEC;
	cout << "\n";
	cout << fixed;
	cout << "Excution time : " << setprecision(6) << duration;
	system("pause");
	return 0;
}



