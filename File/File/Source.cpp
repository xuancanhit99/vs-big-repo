#include <iostream>
#include <fstream>
#define MAX 50

using namespace std;

double Sum(double a[], int n) {
	int i;
	double s = 0;
	for (i = 0; i < n; i++) {
		if (a[i] != 0)
			s += a[i];
		else
			break;
	}
	return s;
}

double Multi(double a[]) {
	int i;
	double m = 1;
	for (i = 0; i < 2; i++) {
		m *= a[i];
	}
	return m;
}

double Div(double a[]) {
	int i=0;
	double d = 1/a[i];
	return d;
}

double Factorial(double a[]) {
	int i; 
	double f = 1;
	for (i = 1; i <= a[0]; i++) {
		f *= i;
	}
	return f;
}

double Max(double a[], int n) {
	int i;
	double max = a[0];
	for (i = 1; i < 5; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

double Imin(double a[], int n) {
	int i;
	double min = a[0], pli = 0;
	for (i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			pli = i;
		}
	}
	return pli + 1;
}


double Process(double a[], int n, char ai) {
	ofstream wFile;
	
	double D = 0;
	if (ai == '+') {
		D = Sum(a, n);
		wFile.open("D:/OutputMyFile.txt");
		wFile << "The sum is: " << D;
		cout << "The sum is: " << D << endl;
	}
	else if (ai == '*') {
		D = Multi(a);
		wFile.open("D:/OutputMyFile.txt");
		wFile << a[0] << " * " << a[1] << " = " << D;
		cout << a[0] << " * " << a[1] << " = " << D << endl;
	}
		
	else if (ai == '/') {
		D = Div(a);
		wFile.open("D:/OutputMyFile.txt");
		wFile << "1/" << a[0] << " = " << D;
		cout << "1/" << a[0] << " = " << D << endl;
	}

	else if (ai == '!') {
		D = Factorial(a);
		wFile.open("D:/OutputMyFile.txt");
		wFile << a[0] << "!" << " = " << D;
		cout << a[0] << "!" << " = " << D << endl;

	}
		
	else if (ai == 'M') {
		D = Max(a, n);
		wFile.open("D:/OutputMyFile.txt");
		wFile << "The maximum of the first 5 numbers is: " << D;
		cout << "The maximum of the first 5 numbers is: " << D << endl;
	}	
	else if (ai == 'X') {
		D = Imin(a, n);
		wFile.open("D:/OutputMyFile.txt");
		wFile << "The place of the minimum is: " << D;
		cout << "The place of the minimum is: " << D << endl;
	}
		


	//wFile.close;
	return D;
}





int main() {
	char ai = { 0 };
	double a[MAX];
	int i;
	//Openfile and readfile
	ifstream myFile;
	myFile.open("D:/myfile.txt");
	if (!myFile)
	{
		cout << "Failed to open this file!" << endl;
		return 1;
	}
	i = 0;
	while (!myFile.eof())
	{
		if (i == 0) {
			myFile >> ai;
		}
		myFile >> a[i];
		//if (myFile.eof()) break;//tranh in thua 1 ki tu
		//cout << a[i] << " ";
		i++;
	}
	myFile.close();
	
	Process(a, i, ai);

	return 0;
}