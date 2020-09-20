#include <iostream>
#include <string>
#include <vector>
using namespace std;
// MUc tieu: XUat du lieu cua 1 mang ma khong quan tam
// kieu du lieu

template<typename type>
void display(type arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}


void Displaystring(string str[], int size) {
	for (int i = 0; i < size; i++) {
		cout << str[i] << " ";
	}
}



template<typename type1>
type1 max(type1 a, type1 b) {
	if (a > b)
		return a;
	else
		return b;
}


template<typename type2, typename type3>
type2 max(type2 a, type3 b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	/*int const size = 10;
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	string str[] = { "Canh", "Anh", "Khoa", "Linh", "Hong", "Dao", "Chung", "Tuan", "Hieu", "Nhung" };
	display(arr, size);
	cout << endl;
	display(str, size);*/



	/*int a = 10, b = 20;
	string x = "ngu", y = "nga";
	cout << max(a, b) << endl << max(x, y);
	system("pause");*/

	int a = 10;
	float b = 20.5;
	cout << "max=" << max(b, a);


	return 0;
}
