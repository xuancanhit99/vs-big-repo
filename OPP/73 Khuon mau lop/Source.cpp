#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename type>
class Stack {
private:
	type data[100];
	int top;
public:
	Stack() {
		top = -1; // Khi them phan tu moi vao, thi phan tu dau tien se = 0
	}
	void push(type number) {
		top++;
		data[top] = number;
	}
	type pop() { // lay tren cung
		type val = data[top];
		top--;
		return val;
	}
	type peek() { // Giong pop nhung de xem khong lay ra nhu pop
		return data[top];
	}
};

int main() {
	Stack<int> st;
	/*st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.pop();
	cout << "\n sau khi pop" << endl;
	cout << st.peek();*/
	Stack<string> str;
	str.push("Vu Xuan a");
	str.push("Vu Xuan b");
	str.push("Vu Xuan c");
	str.push("Vu Xuan d");
	str.pop();
	cout << "\n sau khi pop" << endl;
	cout << str.peek();

	return 0;
}
