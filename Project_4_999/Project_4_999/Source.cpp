#include <iostream>

using namespace std;

const char CHAR_55 = 55;
const char CHAR_48 = 48;

int convertNumber(int n, int b) {
	if (n < 0 || b < 2 || b > 16) {
		printf("He co so hoac gia tri chuyen doi khong hop le!");
		return 0;
	}
	int i;
	char arr[20];
	int count = 0;
	int m;
	int remainder = n;
	while (remainder > 0) {
		if (b > 10) {
			m = remainder % b;
			if (m >= 10) {
				arr[count] = (char)(m + CHAR_55);
				count++;
			}
			else {
				arr[count] = (char)(m + CHAR_48);
				count++;
			}
		}
		else {
			arr[count] = (char)((remainder % b) + CHAR_48);
			count++;
		}
		remainder = remainder / b;
	}
	// hien thi he co so
	for (i = count - 1; i >= 0; i--) {
		printf("%c", arr[i]);
	}
	return 1;
}

/**
 * Ham main
 */
int main() {
	int n, m;
	cout << "Input n = "; cin >> n;
//	cout << "Input m = "; cin >> m;
	printf("So %d trong he co so 2 = ", n);
	convertNumber(n, 2);
	printf("\nSo %d trong he co so 8 = ", n);
	convertNumber(n, 8);
	printf("\nSo %d trong he co so 16 = ", n);
	convertNumber(n, 16);
	return 1;
}
