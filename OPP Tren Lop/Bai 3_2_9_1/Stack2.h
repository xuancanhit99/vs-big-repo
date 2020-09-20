#include <iostream>
#include <string>
#include <iomanip>
#define MAX 100
using namespace std;

class Stack2 {
public:
    int top = -1;
    int N;
    string S;
    int st[MAX];
    Stack2(int n, string s);
    bool isEmty();
    bool isFull();
    bool push(int data);
    int peek();
    int size();
    void print();
};