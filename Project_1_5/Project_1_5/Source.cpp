#include <iostream>

using namespace std;

int main()
{
	cout << "True = 1" << endl << "False = 0" << endl;

	bool a, b, c = false;
	int x;
	cout << "Daytime-na ulitse den (1 or 0): ";
	cin >> x;
	if (x == 1) 
		a = true;
	else 
		a = false;
	cout << "The curtains are spread-razdvinuty shtory (1 or 0): ";
	cin >> x;
	if (x == 1) 
		b = true;
	else
		b = false;
	cout << "The lamp is on-vklyuchena lampa (1 or 0): ";
	cin >> x;
	if (x == 1) 
		c = true;
	else
		c = false;
	if (a == true && (b == true || c == true))
		cout << "Light in the room-da, svetlo v komnate!" << endl;
	else
		cout << "Dark in the room-temno v komnate!" << endl;
	return 0;
}
