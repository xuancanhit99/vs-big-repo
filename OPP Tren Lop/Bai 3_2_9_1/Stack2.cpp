#include "Stack2.h"

Stack2::Stack2(int n, string s) {
    N = n;
    S = s;
}
bool Stack2::isEmty() {
    if (top == -1) return true;
    return false;
}
bool Stack2::isFull() {
    if (top == N - 1) return true;
    return false;
}
bool Stack2::push(int data) {
    if (!(isFull())) {
        top += 1;
        st[top] = data;
        return true;
    }
    return false;
}

int Stack2::peek() {
    if (!(isEmty())) return st[top];
    else return -1;
}

int Stack2::size() {
    return top + 1;
}
void Stack2::print() {
    for (int i = top; i >= 0; i--) {
        cout << st[i] << endl;
    }
}