#include <iostream>
#include <array>
#define MAX 5
using namespace std;

void printArray(const array<int, MAX>& arr) // truyen tham chieu (hang) vi hieu xuat
{
	cout << "so phan tu: " << arr.size() << endl;
	for (const auto& item : arr) // co the su dung for-each loops o moi ham
	{
		cout << item << ' ';
	}
	cout << endl;




}

int main() {
	array <int, 5> arr; // mang arr co 5 phan tu kieu int 
	array<string, 10> arr2; // mang arr2 co 10 phan tu kieu string


	// khai bao
	array <int, 5> arr = { 2,5,8,3,1 };
	array <int, 5> arr2{ 2,5,8,3,1 }; // khoi tao dong nhat C++11

	array <int, 5> arr3;
	arr3 = { 2,5,8,3,1 }; // khoi tao day du cac phan tu
	arr3 = { 2,5,8 }; // khoi tao 3 phan tu dau, con lai la 0



	// truy cap
	array <int, 5> arr = { 2,5,8,3,1 };
	arr[1] = 3; // gan =3 cho phan tu thu 2
	arr.at(1) = 3; // tuong tu nhu tren
	cout << arr[4]; // truy cap gia tri phan tu thu 5
	cout << arr.at(6); // ngoai pham vi mang, nem ra mot loi va ket thuc chuong trinh
	
	
	//xem kich thuoc cua mang
	cout << arr.size() << endl;
	
	
	//Không giống như mảng 1 chiều tĩnh, mảng kiểu std::array không chuyển thành con trỏ 
	//khi truyền vào hàm. Vì vậy, hàm size() và for-each loops vẫn hoạt động bên trong hàm khác:
	array <int, MAX> arr = { 2, 5, 8, 3, 1 };
	printArray(arr);



	//Mảng kiểu std::array có thể được sắp xếp bằng cách sử dụng hàm std::sort() được khai báo
	//trong thư viện <algorithm>:
	array <int, MAX> arr = { 2,5,8,3,1 };
	cout << "Sap xep tang: \n";
	sort(arr.begin(), arr.end()); // sap xep tang dan
	printArray(arr);

	cout << "Sap xep giam: \n";
	sort(arr.rbegin(), arr.rend());
	printArray(arr);

	system("pause");
	return 0;
}

