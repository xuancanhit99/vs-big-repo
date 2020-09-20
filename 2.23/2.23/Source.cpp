#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
#define MAX 10
#define KC 3

int random(int minN, int maxN) { //create random numbers from a to b
	return minN + rand() % (maxN + 1 - minN);
}

void Cre(int a[][MAX]) {
	srand((int)time(0)); // Add time variables to create different values at different time intervals
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			a[i][j] = random(1, 100); // from 1 to 100
		}
	}
}

void Pri(int a[][MAX]) { // Create a chess board with random numbers on each chess box
	int d = 1;
	cout << "   H   G   F   E   D   C   B   A" << endl;
	cout << "  --------------------------------" << endl;
	for (int i = 0; i < 8; i++) {
		cout << d << "|";	
		for (int j = 0; j < 8; j++) {
			cout << setw(KC) << a[i][j] << " ";
		}
		cout << "|" << d;
		d++;
		cout << endl;
	}
	cout << "  --------------------------------" << endl;
	cout << "   H   G   F   E   D   C   B   A" << endl;
}

int Chose(int a[][MAX], int b[], int di[], int ci[], int d1, int c1, int d2, int c2) {
	int k = 0;
	b[k] = a[d1][c1];
	di[k] = d1;
	ci[k] = c1;
	if (d1 < d2) {
		while (1) {
			k++;
			b[k] = a[d1 + 1][c1 + 1];
			d1++; di[k] = d1;
			c1++; ci[k] = c1;
			if (c1 > c2)
				break;
		}
		return k;
	}
	else {
		while (1) {
			k++;
			b[k] = a[d1 - 1][c1 + 1];
			d1--; di[k] = d1;
			c1++; ci[k] = c1;
			if (c1 > c2)
				break;
		}
		return k;
	}
}


void Bubblesort(int arr[], int n) { //sort the selected values, use bubble sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void CreA0(int b[], int di[], int ci[], int k) { //Create arrays with diagonal values selected for display, the
	int NS[MAX][MAX] = { 0 };
	int i = 0;
	while (1) {
		NS[di[i]][ci[i]] = b[i];
		i++;
		if (i >= k)
			break;
	}
	Pri(NS);
}

int main() {
	int a[MAX][MAX];
	int b[MAX];
	int c1, c2, d1, d2;
	int dd1, dd2;
	char cc1, cc2;
	int di[MAX];
	int ci[MAX];
	char cmdToDir[128]; //ASCI // setup keyboard
	cmdToDir['H'] = 0; cmdToDir['h'] = 0;
	cmdToDir['G'] = 1; cmdToDir['g'] = 1;
	cmdToDir['F'] = 2; cmdToDir['f'] = 2;
	cmdToDir['E'] = 3; cmdToDir['e'] = 3;
	cmdToDir['D'] = 4; cmdToDir['d'] = 4;
	cmdToDir['C'] = 5; cmdToDir['c'] = 5;
	cmdToDir['B'] = 6; cmdToDir['b'] = 6;
	cmdToDir['A'] = 7; cmdToDir['a'] = 7;
	cout << "1. Matrix with random integers in the range from 1 to 100: " << endl << endl;
	Cre(a);
	Pri(a);
	cout << endl << "2. Selects the diagonal on the matrix, setting the coordinates of two cells (its beginning and end): " << endl << endl;
	cout << "Begin: "; cin >> cc1 >> dd1;
	cout << "End: "; cin >> cc2 >> dd2;
	cout << endl << "  * Diagonal elements are selected, the remaining elements are zero: " << endl << endl;
	d1 = dd1 - 1; 
	d2 = dd2 - 1; 
	c1 = cmdToDir[cc1]; 
	c2 = cmdToDir[cc2]; 
	int k = Chose(a, b, di, ci, d1, c1, d2, c2);
	CreA0(b, di, ci, k);
	cout << endl << "3. Arrange diagonal elements, the rest are zero: " << endl << endl;
	Bubblesort(b, k);
	CreA0(b, di, ci, k);
	return 0;
}