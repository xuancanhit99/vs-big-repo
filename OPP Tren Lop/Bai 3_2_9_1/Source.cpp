#include "Stack1.h"
#include "Stack2.h"

void printst(Stack1& st1, Stack2& st2) {
    int i = st1.top;
    int j = st2.top;
    while (i >= 0 || j >= 0) {
        if (i < 0)
            if (j == 0) cout << setw(30) << st2.st[j];
            else cout << setw(30) << st2.st[j] << endl;
        else if (j < 0)
            if (i == 0)  cout << setw(15) << st1.st[i] << setw(15);
            else cout << setw(15) << st1.st[i] << setw(15) << endl;
        else
            if (i == 0 && j == 0) cout << setw(15) << st1.st[i] << setw(15) << st2.st[j];
            else cout << setw(15) << st1.st[i] << setw(15) << st2.st[j] << endl;
        i--; j--;
    }
}

int lenstr(string s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
void printstr(string s1, string s2) {
    int i, j;
    for (i = 0; i < lenstr(s1); i++) {
        cout << s1[i];
    }
    cout << setw(15-i+1);
    for (j = 0; j < lenstr(s2); j++) {
        cout << s2[j];
    }
    cout << setw(15-j+1) << "\n";
}
    
int main() {
    int n1, n2, a, ktmax;
    string s1, s2;
    cin >> s1 >> n1 >> s2 >> n2;
    Stack1 st1(n1, s1);
    Stack2 st2(n2, s2);
    if (n1 >= n2) ktmax = n1;
    else ktmax = n2;
    for (int i = 0; i < ktmax; i++) {
        cin >> a;
        st1.push(a);
        if (st2.peek() == n2) break;
        st2.push(a);
        if (st1.peek() == n1) break;
        //if (st1.peek() > n1 || st2.peek() > n2) break;
    }
    cout << s1 << " " << n1 << endl << s2 << " " << n2 << endl;
    printstr(s1, s2);
    //cout << s1 << setw(15) << "|" << s2 << setw(15) << "\n";
    printst(st1, st2);
    return 0;
}
