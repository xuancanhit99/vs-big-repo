#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

int x = 5, y = 3;

//2.1
void InputArr(int* a, int& n) {
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "]= ";
		cin >> *(a+i);
	}
}


int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

void RanArr(int* a, int n) {
	srand((int)time(0));
	for (int i = 0; i < n; i++)
		a[i] = random(1, 100);
}

//2.2
void OutPutArr(int *a, int n) {
	cout << endl << "Array:   ";
	for (int i = 0; i < n; i++)
		cout << setw(x) << *(a+i);
	cout << endl << "Index i =";
	for (int i = 0; i < n; i++)
		cout << setw(y) << "[" << i << "]";
	cout << endl << endl;
}

//2.3
void InsertArr(int* a, int* b, int n, int ins, int num_ins) {
	for (int i = 0; i < n; i++) {
		if (i >= ins) {
			if (i == ins)
				b[i] = num_ins;
			else
				b[i] = a[i - 1];
		}
		else 
			b[i] = a[i];
	}
	b[n] = a[n - 1];
}

//2.4
void LinearS(int* a, int n, int skey) {
	int count = 0;
	int* c = new int[n];
	for (int i = 0; i < n; i++) {
		if (a[i] == skey) {
			count++;
			*(c+count) = i;
		}
	}
	if (count == 0)
		cout << "Value not found." << endl;
	else {
		cout << "Value " << skey << " repeat: " << count << " times, with location:" << endl;
		for (int j = 1; j <= count; j++) {
			cout << "i = " << *(c + j) << endl;
		}
	}
}

//2.5
void FindI(int* a, int n, int sfirst) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == sfirst) {
			count++;
			cout << "Index of the first occurrence i = " << i << endl;
			break;
		}
	}
	if (count == 0)
		cout << "Value not found." << endl;
}

//2.6
void NumOfOcc(int* a, int n, int stimes) {
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == stimes)
			count++;
	if (count == 0)
		cout << "Value not found." << endl;
	else 
		cout << "The number of occurrences: " << count << endl;
}


//2.7
int DeArr(int* a, int* c, int n, int de) {
	int j = 0, f = 0;
	if (de >= 0 && de < n) {
		for (int i = 0; i < n; i++) {
			if (i != de) {
				c[j] = a[i];
				j++;
			}
			else
				f++;
		}
		return j;
	}
	return -1;
}

//2.8
int DeAllArr(int* a, int* c, int n, int num_de) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != num_de) {
			c[j] = a[i];
			j++;
		}
	}
	return j;
}

//9 
int BeforeFNum(int* a, int* b, int n, int farr) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < farr) {
			b[j] = a[i];
			j++;
		}
	}
	b[j] = farr; j++;
	return j;
}

int AfterFNum(int* a, int m, int* b, int n, int farr) {
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] > farr) {
			b[n] = a[i];
			n++;
		}
	}
	return n;
}

int main() {
	int n, ins, num_ins, skey, sfirst, stimes, de, num_de, in;
	//int* a;
	//a = new int[n];
	//1. Заполнение массива: с клавиатуры; датчиком случайных чисел.
	cout << "Enter n: "; cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	int* e = new int[n];
	int* f = new int[n];
	cout << "1. Input array:" << endl << "  (0). Random numbers" << endl << "  (1). From the keyboard" << endl;
rein:;
	cout << "Please choose(0 or 1): "; cin >> in;
	if (in == 1) {
		cout << "a. Input array: from the keyboard." << endl;
		InputArr(a, n);
	}
	else if (in == 0) {
		cout << "b. Input array: random numbers." << endl;
		RanArr(a, n);
	}
	else {
		cout << "Invalid selection" << endl;
		goto rein;
	}

	//2. Вывод массива.
	cout << endl << "2.The output of the array" << endl;
	OutPutArr(a, n);

	//3. Вставить значение в заданную позицию (контроль позиции в основной программе).
	cout << "3. Insert the value at the given position." << endl;
	cout << "Enter location you want to insert i = "; cin >> ins;
	cout << "Enter value you want to insert: "; cin >> num_ins;
	InsertArr(a, b, n, ins, num_ins);
	OutPutArr(b, n + 1);

	//4. Линейный поиск.
	cout << "4. Linear search." << endl;
	cout << "Enter value to search: "; cin >> skey;
	LinearS(b, n + 1, skey);

	//5. Найти индекс первого вхождения заданного значения в массиве.
	cout << endl << "5. Find the index of the first occurrence of the given value in the array." << endl;
	cout << "Enter value to search: "; cin >> sfirst;
	FindI(b, n + 1, sfirst);

	//6. Найти количество вхождений заданного значения в массиве (поиск всех вхождений).
	cout << endl << "6. Find the number of occurrences of a given value in the array (search for all occurrences)." << endl;
	cout << "Enter value to search: "; cin >> stimes;
	NumOfOcc(b, n + 1, stimes);

	//7. Удалить значение из заданной позиции: сохраняя порядок всех остальных элементов; не сохраняя порядок следования остальных элементов.
	cout << endl << "7. Delete the value from the given position: preserving the order of all other elements; without preserving the order of the remaining elements" << endl;
	cout << "Enter location to delete i = "; cin >> de;
	int m = DeArr(b, c, n + 1, de);
	if (m == -1)
		cout << "Index not found." << endl << endl;
	else {
		cout << endl << "Delete value " << b[de] << " with index i = " << de << endl; system("Pause");
		OutPutArr(c, m);
	}

	//8. Удалить все значения равные заданному.
	cout << "8. Delete all values equal to the specified." << endl;
	cout << "Enter value to delete: "; cin >> num_de;
	cout << endl << "Delete all value " << num_de << " in the array" << endl; system("Pause");
	int p = DeAllArr(c, d, m, num_de);
	OutPutArr(d, p);

	//9. Все элементы меньше первого элемента, расположить перед ним, сохраняя порядок следования элементов. 
	cout << "9. All elements are smaller than the first element, placed in front of it, preserving the sequence of elements." << endl; system("Pause");
	int farr = d[0];
	int q = DeArr(d, e, p, 0);
	int ub = BeforeFNum(e, f, q, farr);
	int ua = AfterFNum(e, q, f, ub, farr);
	OutPutArr(f, ua);

	delete[] a, b, c, d, e, f;

	cout << endl; system("Pause");
	return 0;
}