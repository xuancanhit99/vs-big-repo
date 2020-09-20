#include<iostream>
using namespace std;

int main()
{
	char a;
	cin >> a;
	if ((int(a) > 64 && int(a) < 91) || (int(a) > 96 && int(a) < 123)) {
		if (a == 'a' || a == 'e' || a == 'o' || a == 'i' || a == 'u' || a == 'A' || a == 'E' || a == 'O' || a == 'I' || a == 'U' || a == 'Y' || a == 'y') {
			cout << "vowel";
		}
		else
			cout << "consonant";
	}
	else {
		cout << "Not letter";
	}
	return(0);
}