#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS // bo qua canh bao loi fopen
#endif
#include <iostream>
#include  <cstdio>
#include <windows.h>

using namespace std;

int main() {
	const char* filePath = "D:/my_text.txt";
	FILE* file;


	file = fopen(filePath, "w");
	if (!file)
		std::cout << "Can not open this file" << std::endl;
	else
		std::cout << "File is created" << std::endl;

	fclose(file);
	CopyFile("D:/my_text.txt", "C:/Users/daota/Desktop/copy_my_text.txt", true);
	cout << "File is copied" << endl;
	return 0;
}

/*if (!file)
std::cout << "Can not open this file" << std::endl;
else
std::cout << "File is opened" << std::endl;*/