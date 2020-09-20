#include "process.h"

int main() {

	int n, ins, num_ins, skey, sfirst, stimes, de, num_de;
	while (1) {
		//1. Заполнение массива: с клавиатуры; датчиком случайных чисел.
		int in;
		cout << "Enter n: "; cin >> n;
		int* a = new int[n];
		int* b = new int[n];
		int* c = new int[n];
		cout << "Input array:" << endl << "  (0). Random numbers" << endl << "  (1). From the keyboard" << endl;
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
		cout << endl << "The output of the array" << endl;
		OutPutArr(a, n);

		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
		cout << "1. Insert the value at the given position." << endl;
		cout << "2. Linear search." << endl;
		cout << "3. Find the index of the first occurrence of the given value in the array." << endl;
		cout << "4. Find the number of occurrences of a given value in the array (search for all occurrences)." << endl;
		cout << "5. Delete the value from the given position." << endl;
		cout << "6. Delete all values equal to the specified." << endl;
		cout << "7. All elements are smaller than the first element, placed in front of it, preserving the sequence of elements." << endl;
		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
		int choose;
		cout << "Please choose: "; cin >> choose;
		switch (choose) {
		case 1: {
			//3. Вставить значение в заданную позицию (контроль позиции в основной программе).
			cout << "Enter location you want to insert i = "; cin >> ins;
			cout << "Enter value you want to insert: "; cin >> num_ins;
			InsertArr(a, b, n, ins, num_ins);
			OutPutArr(b, n + 1);
			break;
		}
		case 2: {
			//4. Линейный поиск.
			cout << "Enter value to search: "; cin >> skey;
			LinearS(a, n, skey);
			break;
		}

		case 3: {
			//5. Найти индекс первого вхождения заданного значения в массиве.
			cout << "Enter value to search: "; cin >> sfirst;
			FindI(a, n, sfirst);
			break;
		}
		case 4: {
			//6. Найти количество вхождений заданного значения в массиве (поиск всех вхождений).
			cout << "Enter value to search: "; cin >> stimes;
			NumOfOcc(a, n, stimes);
			break;
		}
		case 5: {
			//7. Удалить значение из заданной позиции: сохраняя порядок всех остальных элементов; не сохраняя порядок следования остальных элементов.
			cout << "Enter location to delete i = "; cin >> de;
			int m = DeArr(a, b, n, de);
			if (m == -1)
				cout << "Index not found." << endl << endl;
			else {
				cout << endl << "Delete value " << a[de] << " with index i = " << de << endl; system("Pause");
				OutPutArr(b, m);
			}
			break;
		}
		case 6: {
			//8. Удалить все значения равные заданному.
			cout << "Enter value to delete: "; cin >> num_de;
			cout << endl << "Delete all value " << num_de << " in the array" << endl; system("Pause");
			int p = DeAllArr(a, b, n, num_de);
			OutPutArr(b, p);
			break;
		}
		case 7: {
			//9. Все элементы меньше первого элемента, расположить перед ним, сохраняя порядок следования элементов. 
			cout << "All elements are smaller than the first element, placed in front of it, preserving the sequence of elements." << endl; system("Pause");
			int farr = a[0];//d
			int q = DeArr(a, b, n, 0); // d e p
			int ub = BeforeFNum(b, c, q, farr); //e f q 
			int ua = AfterFNum(b, q, c, ub, farr); // e q f ub 
			OutPutArr(c, ua);
			break;
		}
		default:
			cout << "Invalid selection" << endl;
			break;
		}
		delete[] a, b, c;
		char s;
		cout << "Do you continue(y/n): "; cin >> s;
		if (s == 'n')
			break;
	}

	cout << endl; system("Pause");
	return 0;
}