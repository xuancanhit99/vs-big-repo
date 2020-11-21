#include <iostream>
#include <fstream>
#define maska 0x1F
#define BITSPEWORD 32
#define SHIFT 5
#define N 10000
//000
using namespace std;

unsigned int a[1 + N / BITSPEWORD];
void set(int i) {
    a[i >> SHIFT] |= (1 << (i & maska));
}

void clr(int i) { 
    a[i >> SHIFT] &= ~(1 << (i & maska)); 
}

int test(int i) {
    return a[i >> SHIFT] & (1 << (i & maska));
}

void coutp(unsigned int x)
{
    int n = sizeof(int) * 8;
    unsigned  maska1 = (1 << (n - 1));

    for (int i = 1; i <= n; i++)
    {
        cout << ((x & maska1) >> (n - i));
        maska1 = maska1 >> 1;
    }
}

void createfile(const char* namef, int n) {
    ofstream fo(namef);
    for (int i = 0; i < n; i++) {
        clr(i);
    }
    for (int i = 1; i <= n; i++) {
        fo << ' ' << 100 + rand() % 100;
    }
    
    fo.close();
}

void readfile(const char* namef) {
    ifstream fi(namef);
    int i;
    if (!fi) {
        cout << "File no open" << endl;
        return;
    }
    while (!fi.eof()) {
        fi >> i;
        cout << i << " ";
    }
    fi.close();
}

void creatrbitarray(const char* namef) {
    ifstream fi(namef);
    int i;
    if (!fi) {
        cout << "File no open" << endl;
        return;
    }
    while (!fi.eof()) {
        fi >> i;
        set(i);
    }
    fi.close();
}

void inputfile(const char* namef, int n) {
    ofstream fo(namef);
    for (int i = 0; i <= n; i++) {
        if (test(i))
            fo << i << ' ';
    }
    fo.close();
}

int main() {
    createfile("inputfile.txt", N);
    readfile("inputfile.txt");
    cout << endl << endl;
    creatrbitarray("inputfile.txt");
    inputfile("inputfile.txt", N);
    readfile("inputfile.txt");
    return 0;
}