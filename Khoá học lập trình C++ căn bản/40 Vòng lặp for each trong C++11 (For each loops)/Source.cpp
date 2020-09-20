#include <iostream>
#define MAX 5
using namespace std;

int main() {
	int arr[MAX] = { 14, 3, 6, 27, 12 };


	//vong lap binh thuong
	for (int i = 0; i < MAX; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;


	//vong lap for each
	// bien item dai dien cho phan tu arr-khong phai chi so
	// co the su dung auto cho kieu du lieu cua item
	for(auto item: arr) {} // khong su dung tham chieu lang phi bo nho-thoi gian lau hon
	for (auto& item : arr) {} // su dung tham chieu-co the thay doi gia tri cua bien-nhung giam thoi gian
	for (const auto& item : arr) { //su dung tham chieu-(const)khong thay doi gia tri cua bien-nhung giam thoi gian
		// bien item dai dien cho phan tu mang o moi vong lap
		cout << item << " ";
	}

	//for each khong lam viec voi con tro mang
	// co the dung them bien i de xem chi so trong mang 
	
	return 0;
}