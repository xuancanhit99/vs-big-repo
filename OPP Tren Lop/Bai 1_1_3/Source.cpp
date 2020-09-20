#include<iostream>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    if (n < 0)
        n = n * -1;
    int count = 0;
    while(n >= 10) {
        n /= 10; 
        count++;
    }
    cout << "Number of digits: " << count + 1;
    return 0;
}