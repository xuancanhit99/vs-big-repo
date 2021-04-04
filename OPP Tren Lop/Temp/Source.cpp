#include <iostream> 
#include <time.h>
using namespace std;


void Input(int a[], int n) {
	cout << "Enter n: "; cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "a[" << i << "]: "; cin >> a[i];
	}
}

void Output(int a[], int n) {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

//1.3
//algorithm 1
int delFirstMetod1(int x[], int& n, int key) {
	int i = 1;
	int count = 0;
	while (i <= n) {
		if (x[i] == key) {
			count++;
			for (int j = i; j < n; j++)
				x[j] = x[j + 1];
			n = n - 1;
		}
		else
			i++;
		cout << "=> "; Output(x, n);
	}
	return count;
}


//algorithm 2
int delFirstMetod2(int x[], int& n, int key) {
	int j = 1;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		x[j] = x[i];
		if (x[i] != key) {
			count++;
			j++;
		}
		cout << "=> ";  Output(x, n);
	}
	n = j-1;
	return count;
}

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

void InputRandom(int a[], int n) {
	cout << "Enter n: "; cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = random(1, 100);
	}
}

int main()
{
	
	int n1 = 10;
	int n2 = 100;
	int a1[11], a2[101];

	//1.3
	cout << "Array input: ";
	Input(a1, n1);

	cout << "Number of comparisons: " << delFirstMetod1(a1, n1, 2) << endl;
	cout << "Number of comparisons:" << delFirstMetod2(a1, n1, 2) << endl;
	delFirstMetod2(a1, n1, 2);
	cout << "Array output: "; Output(a1, n1);

	//1.4
	InputRandom(a1, n1);
	Output(a1, n1);
	return 0;
}