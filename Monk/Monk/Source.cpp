#include <iostream>

#define MAX1 1000
#define MAX2 5

using namespace std;

int InputData(int a[][MAX2]) {
	int line;
	cout << "Enter number of data: "; cin >> line;
	cout << "Enter input data: " << endl;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	cout << endl << "Successfully import data!" << endl << endl;
	return line;
}

int ir = 0;
int result[MAX1];

void Monkequal1(int a[][MAX2], int pnum, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 1; j < 4; j++) {
			if (pnum == a[i][j]) {
				result[ir] = a[i][0];
				ir++;
				pnum = a[i][0];
				Monkequal1(a, pnum, line);
			}
		}
	}
}



int Arrto1(int a[], int b[]) {
	int i;
	for (i = 0; i < ir; i++) {
		b[i] = a[i];
		if (b[i] == 1)
			break;
	}
	return i+1;
}





int result1[MAX1], result2[MAX1];
int ir1=0, ir2=0;


//debug
void Debug(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
//debug


int Generalteacher() {
	for (int i = 0; i < ir1; i++) {
		for (int j = 0; j < ir2; j++) {
			if (result1[i] == result2[j]) {
				return result1[i];
				break;
			}	
		}
	}
}

int Check1 = 0, Check2 = 0;

void Monkequal2(int a[][MAX2], int pnum1, int pnum2, int line) {
	Monkequal1(a, pnum1, line);
	Check1 = ir;
	ir1 = Arrto1(result, result1); 
	ir = 0;
	Monkequal1(a, pnum2, line);
	Check2 = ir;
	ir2 = Arrto1(result, result2);
	ir = 0;
}

int InputTask(int a[][MAX2], int line) {
	int m, pnum1, pnum2;
	cout << "How many monks? "; cin >> m;
	
	if (m == 1) {
		cout << "Personal number: "; cin >> pnum1;
		Monkequal1(a, pnum1, line);
	}
		
	if (m == 2) {
		cout << "Personal-1 number: "; cin >> pnum1;
		cout << "Personal-2 number: "; cin >> pnum2;
		Monkequal2(a, pnum1, pnum2, line);
	}
	return m;
}


//void OutPut(int a[][MAX2], int line) {
//	for (int i = 0; i < line; i++) {
//		for (int j = 0; j < 4; j++) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}


void OutPutar1(int a[]) {
	cout << "This is a monk. His teacher: ";
	int i = 0;
	while (i < ir) {
		if (a[i] == 1)
			break;
		cout << a[i] << " ";
		i++;
	}
	cout << endl;
}

int main() {
	int A[MAX1][MAX2];
	int line = InputData(A);
	
	while (1) {
		int m = InputTask(A, line);

		if (m == 1) {
			if (ir == 0)
				cout << "Not Monk" << endl;
			else
				OutPutar1(result);
			ir = 0;
		}
		else {
			if (Check1 == 0 && Check2 == 0) {
				cout << "Monk1: Not Monk" << endl;
				cout << "Monk2: Not Monk" << endl;
			}

			else if (Check1 == 0 && Check2 != 0) 
				cout << "Monk1: Not Monk" << endl;
			else if (Check1 != 0 && Check2 == 0)
				cout << "Monk2: Not Monk" << endl;
			else {
				cout << "These are 2 monks. General teacher: " << Generalteacher() << endl;
				ir1 = 0; ir2 = 0;
			}
		}
		Check1 = 0; Check2 = 0;
		char h;
		cout << endl << "Do you want continue?(y/n): "; cin >> h; cout << endl;
		if (h == 'n')
			break;
	}

	return 0;
}