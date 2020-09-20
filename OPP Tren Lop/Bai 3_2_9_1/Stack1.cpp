#include"Stack1.h"


Stack1::Stack1(int n, string s) {
    N = n;
    S = s;
}
bool Stack1::isEmty() {
    if (top == -1) return true;
    return false;
}
bool Stack1::isFull() {
    if (top == N - 1) return true;
    return false;

}
bool Stack1::push(int data) {
    if (!(isFull())) {
        top += 1;
        st[top] = data;
        return true;
    }
    return false;
}

int Stack1::peek() {
    if (!(isEmty())) return st[top];
    else return -1;
}

int Stack1::size() {
    return top + 1;
}
void Stack1::print() {
    for (int i = top; i >= 0; i--) {
        cout << st[i] << endl;
    }
}