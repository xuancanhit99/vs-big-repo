#include <iostream>
#include <vector>
using namespace std;

//dictionary : C#,(key, value) dog: con cho
//Map, Pair : C++

template<class type1, class type2>
class CMap {
private:
	vector<type1> Keys;
	vector<type2> Values;
public:
	void insert(type1 key, type2 value) {
		Keys.push_back(key);
		Values.push_back(value);
	}
	void show(int n) {
		cout << Keys[n] << " : " << Values[n] << endl;
	}
};

int main() {
	CMap<string, float> Grades;
	Grades.insert("Canh", 10);
	Grades.insert("Hung", 1);
	Grades.insert("Nam", 2);
	Grades.insert("Linh", 7);
	Grades.insert("Hai", 8);
	for (int i = 0; i < 5; i++) {
		Grades.show(i);
	}
	system("pause");
	return 0;
}