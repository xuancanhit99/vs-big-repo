#include <iostream>
#include <vector>
using namespace std;

void printStack(const vector<int>& stack) { // (I)
	for (const auto& element : stack)
		cout << element << ' ';
	cout << "(cap " << stack.capacity() << " length " << stack.size() << ")" << endl;
}



int main() {
	//vector<int> array; 
	//vector<int> ar1 = { 1, 3, 5 ,7 };
	//vector<int> ar2{ 9,6,5,1 };

	//array[1] = 5; // khong kiem tra pham vi mang
	//array.at(1) = 5; // co kiem tra pham vi mang


	//vector<int> arr = { 2,5,6,7 };
	//cout << arr.size() << endl; // 4



	//vector<int> ar{ 2,5,6,3,7 }; // mang 5 phan tu 
	//ar.resize(10); // thay do do dai cua mang thanh 10 phan tu
	//cout << "Do dai mang: " << ar.size() << endl;
	//for (int i = 0; i < ar.size(); i++)
	//	cout << ar[i] << "  "; // cac gia tri mac dinh bang 0
	//// Neu thay doi kich thuoc mang nho hon kich thuoc ban dau thi cac phan tu thua bi bo di



	////dung luong va kich thuoc cua vec to
	////capacity va size
	////size so luong phan tu trong mang
	////cap so luong phan tu duoc cap phep cho vector trong bo nho
	//vector<int> ar1;
	//ar1 = { 0,2,3,4,5 }; // length = 5, cap = 5
	//cout << "length: " << ar1.size() << " capacity: " << ar1.capacity() << endl;
	//ar1 = { 1,2,3 }; // leng =3, cap =5
	//cout << "length: " << ar1.size() << " capacity: " << ar1.capacity() << endl;



	////chung ta co the cap phat dung luong ban dau cho vector
	//vector<int> arr;
	//arr.reserve(5);



	//(I) 
	vector<int> stack;
	stack.push_back(5); // push_back them mot phan tu vao cuoi vecto
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	// back() tra ve gia tri cua phan tu cuoi
	cout << "Phan tu cuoi: " << stack.back() << '\n';

	stack.pop_back(); // pop_bachk() xoa mot phan tu cuoi vector
	printStack(stack);

	stack.pop_back(); 
	printStack(stack);

	stack.pop_back(); 
	printStack(stack);


	system("pause");
	return 0;
}