#include <iostream>
#include <ctime>
#define MAX 6000
using namespace std;
int a[20], b[20], m, n;


void Mode() {
	n = 10;
	m = 4;
	//cin >> n >> m; 
	a[0] = 1;
	for (int i = 0; i <= n; i++)
		b[i] = 0;
}

int FourToDec() {
	int c=0;
	int d = 3;
	for (int i = 1; i <= m; i++) {
		c+=a[i]*pow(10,d);
		d--;
	}
	return c;
}

int c[MAX];
int k = 0;

void AllNums(int i) {
	for (int j = 0; j <= n-1; j++) { //mien gia tri cua a[i] - 
		if (b[j] == 0) {
			a[i] = j;
			if (i == m) {
				c[k]=FourToDec();
				k++;
			} 
			else {
				b[j] = 1;       //danh dau da su dung
				AllNums(i + 1);
				b[j] = 0;          //tra lai de su dung cho TH khac
			}
		}
	}
}


int Random() {
	srand(time(0));
	return rand() % (5041);
}


void DecToFour(int a[], int n) { // n la so(dec) bien doi sang mang rd 4 phan tu
	if (n < 1000) {
		a[0] = 0;
		a[1] = n / 100;
		a[2] = (n % 100) / 10;
		a[3] = n % 10;
	}
	else {
		a[0] = n / 1000;
		a[1] = (n % 1000) / 100;
		a[2] = ((n % 1000) % 100) / 10;
		a[3] = n % 10;
	}
}

int bull = 0, cow = 0;

void BullsAndCows(int a[], int b[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i] == b[j]) {
				if (i == j)
					bull++;
				else
					cow++;
			}
		}
	}
}


void In(int a[]) {
	for (int i = 0; i < 4; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int rddec; // so random o dec
	int ard[5]; // mang chua phan tu random

	int dec; // so doan
	int adec[5]; // mang chua phan tu doan
	


	cout << "----------Welcome to the Bulls and Cows game!----------" << endl;
	cout << "|     1. Bulls = correct code, correct position.      |" << endl;
	cout << "|     2. Cows  = correct code, wrong position.        |" << endl;
	cout << "|             You win when Bulls = 4                  |" << endl;
	cout << "-------------------------------------------------------" << endl;
	Mode();
	AllNums(1);
	//rddec = c[Random()];
	//DecToFour(ard, rddec);
	//In(ard); cout << endl;// So cua may


	while (1) {
		rddec = c[Random()];
		DecToFour(ard, rddec);
		//In(ard); cout << endl;// So cua may
		while (1) {
			cout << "\nEnter your number (XXXX): ";
			cin >> dec; cout << endl;
			DecToFour(adec, dec);
			In(adec); // So doan

			BullsAndCows(ard, adec);
			cout << "Bulls(+) = " << bull << endl;
			if (bull == 4)
				break;
			cout << "Cows(-)  = " << cow << endl << endl;
			bull = 0;
			cow = 0;
		}
		cout << "\n----------You Win!!!----------\n" << endl;
		char k;
		cout << "Do you want to continue(y/n): "; cin >> k;
		bull = 0;
		cow = 0;
		if (k == 'n')
			break;
	}
	cout << "\n----------Thanks for playing!----------" << endl;
	return 0;
}