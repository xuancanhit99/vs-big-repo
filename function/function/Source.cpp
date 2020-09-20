#include <iostream>
#include <time.h>

using namespace std;

int random(int minR, int maxR) {
	return minR + rand() % (maxR + 1 - minR);
}


int main() {
	srand((int)time(0));
	int min, max;
	cout << "Input Min = "; cin >> min;
	cout << "Input Max = "; cin >> max;
	cout << "Random = " << random(min, max) << endl;
	return 0;
}