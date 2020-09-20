#include<iostream>
#include<fstream>//FILE
#include<conio.h>//getch();

using namespace std;

int main()
{
	/*----------------WRITE FILE------------------------*/
	char path[40];//duong dan file hoac file name
	char c;
	ofstream outf; //object for writing from a file outf(tuychon)
	cout << "Enter file name or pathfile: ";
	cin >> path;
	outf.open(path);//create file
	cout << "\nEnter content file: ";
	while (1)//write file
	{

		c = _getch();
		cout << c;
		
		if (c == 13) break;//enter=13 ket thuc
		outf << c;
		outf << " ";
	}
	outf.close();//Close file;
	//system("cls"); // Lenh xoa man hinh trong thu vien iostream
	cout << "\n\nCreate file successfully" << endl << endl;
	/*-----------------READ FILE-------------------------*/
	ifstream inf;//object for reading from a file
	char ch;
	inf.open(path);
	if (!inf) {
		cout << "Cannot open file" << endl;
		return 1;
	}
	cout << "File  " << path << "  number in content: " << endl;
	while (!inf.eof())//read file
	{
		inf >> ch;
		//if (inf.eof()) break;//tranh in thua 1 ki tu
		if (ch >= 48 && ch <= 57)
			cout << ch;
	}
	inf.close();//close file 
	cout << "\n";
	system("pause");
	return 0;
}
/* Ly thuyet o trang http://www.cplusplus.com/doc/tutorial/files/
	C++ cung cap cac lop de thuc hien dau ra va dau vao cua cac ki tu to/from files
	ofstream: Stream class to write on files - Luong lop de ghi vao tep
	ifstream: Stream class to read from files -  Lop truyen phat de doc tu tep
	fstream: Stream class to both read and write from/to files - luong lop de ca doc va nghi from/to tep
*/