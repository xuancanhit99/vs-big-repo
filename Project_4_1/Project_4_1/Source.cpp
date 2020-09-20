#include<iostream>
#include<fstream>
#define MAX 50

using namespace std;

void Input(double a[]) {
	int i;
	for (i = 0; i < 10; i++) {
		if (i == 0)
			cout << "Enter 1st number: ";
		else if (i == 1)
			cout << "Enter 2nd number: ";
		else if (i == 2)
			cout << "Enter 3rd number: ";
		else
			cout << "Enter " << i+1 << "th number: ";
		cin >> a[i];
	}
}

double Output(double b[]) {
	int i;
	double S=0;
	for (i = 0; i < 10; i++) {
		S += b[i];
	}
	return S;
}

int main()
{
	char Path[MAX];
	int i;
	double a[MAX], b[MAX];
//Writefile
	ofstream wfile; 
	cout << "Enter file name or pathfile: ";
	cin >> Path;
	wfile.open(Path);
	cout << "\nWrite 10 numbers " << endl << endl; 
	Input(a);
	for (i = 0; i < 10; i++) {
		wfile << a[i];
		if (i != 9)
			wfile << " ";
	}
	cout << "\nCreate file successfully" << endl << endl;
	wfile.close();
//Read file
	ifstream rfile;
	rfile.open(Path);
		if (!rfile) {
		cout << "Cannot open file" << endl;
		return 1;
	}
	i = 0;
	cout << "Content in file: ";
	while (!rfile.eof())
	{
		rfile >> b[i];
		if (rfile.eof()) break;//tranh in thua 1 ki tu
		cout << b[i] << " ";
		i++;
	}
	rfile.close();
	cout << "\n\nSum = " << Output(b) << endl;
	return 0;
}


