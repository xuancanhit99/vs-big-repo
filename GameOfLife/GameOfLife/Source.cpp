#include <iostream>
#include <fstream>

#define MAX 21
using namespace std;


void Output(int a[][MAX], int m, int n) { // In the he vi sinh vat

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}



int OriGen(int a[][MAX], int m, int n) { //Read vi sinh vat ban dau D:/work.dat
	ifstream myFile;
	myFile.open("D:/work.dat");
	if (!myFile) {
		cout << "Failed to open this file!" << endl;
		return 1;
	}
	while (!myFile.eof()) {
		//Doc mang vi sinh vat ban dau
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				myFile >> a[i][j];
			}
		}
	}
	myFile.close();
}


void NextGen(int a[][MAX], int future[][MAX], int m, int n) { // The he tiep theo
	for (int h = 1; h < m - 1; h++) {
		for (int k = 1; k < n - 1; k++) {
			int aliveNeighbours = 0; // so hang xom
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					aliveNeighbours += a[h + i][k + j];

				}
			}
			aliveNeighbours -= a[h][k]; 
			//Cac quy tac can de song hoac chet
			//Chet do co don
			if ((a[h][k] == 1) && (aliveNeighbours < 2))
				future[h][k] = 0;
			//Chet do qua dong
			else if ((a[h][k] == 1) && (aliveNeighbours > 3))
				future[h][k] = 0;

			//Mot te bao duoc sinh ra

			else if ((a[h][k] == 0) && (aliveNeighbours == 3))
				future[h][k] = 1;

			// Te bao con lai binh thuong
			else
				future[h][k] = a[h][k];
		}
	}
}


void aTob(int a[][MAX], int b[][MAX], int m, int n) { // Chuyen de lap
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = b[i][j];
		}
	}
}


int Checkdie(int b[][MAX], int m, int n) { // Kiem tra song chet
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			c += b[i][j];
		}
	}
	return c;
}


int main() {

	int c, m = 21, n = 21;
	int a[MAX][MAX];
	int b[MAX][MAX] = { 0 };
	cout << "Enter the number of generations: "; cin >> c;

	OriGen(a, m, n);
	cout << endl << "Read successfully from the file: D:/work.dat" << endl << endl;
	cout << endl << "Original Generation: " << endl << endl;
	Output(a, m, n);

	//Ghi File work.out
	ofstream wFile;
	wFile.open("D:/work.out");

	int gen = 0;
	while (c != 0) {
		gen++;
		if (gen == 1) {
			wFile << endl << "1st Generation: " << endl << endl;
			cout << endl << "1st Generation: " << endl << endl;
		}
		else if (gen == 2) {
			wFile << endl << "2nd Generation: " << endl << endl;
			cout << endl << "2nd Generation: " << endl << endl;
		}
		else if (gen == 3) {
			wFile << endl << "3rd Generation: " << endl << endl;
			cout << endl << "3rd Generation: " << endl << endl;
		}
		else {
			wFile << endl << gen << "th Generation: " << endl << endl;
			cout << endl << gen << "th Generation: " << endl << endl;
		}
		NextGen(a, b, m, n);

		if (Checkdie(b, m, n) == 0) {
			wFile << "\tGenerations die" << endl;
			cout << "\tGenerations die" << endl;
			break;
		}

		Output(b, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				wFile << a[i][j] << " ";
			}
			wFile << endl;
		}
		aTob(a, b, m, n);
		c--;
	}
	cout << endl << endl << "Write successfully to the file D:/work.out" << endl << endl;
	return 0;
}