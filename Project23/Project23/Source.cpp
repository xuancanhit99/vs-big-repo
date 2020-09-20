#include <iostream>
#include <vector>

using namespace std;

void OutVec(vector<long long> age) {
    for (int i = 0; i < age.size(); i++) {
        cout << age[i] << " ";
    }
}

void Deli(long long i, vector<long long>& check) {
    while (i != 0) {
        int x = i % 10;
        check.push_back(x);
        i /= 10;
    }
}

bool Same(vector<long long> check) {
    
    for (int i = 0; i < check.size(); i++) {
        long long count = 0;
        for (int j = 0; j < check.size(); j++) {
            if (check[i] == check[j]) {
                count++;
            }
        }
        if (count >= 2) {
            return true;
        }
    }
    return false;
}


long long differentiateNumber(long long L, long long R)
{
    long long sum = 0;
    for (int i = L; i <= R; i++) {
        vector <long long> check;
        Deli(i, check);
        if (!Same(check))
            sum++;
        check.clear();
    }
    return sum;
}


int main() {
    vector<long> check = { 1,2,3,4,6 };
    cout << differentiateNumber(10, 23);
    //Deli(11231230, check);
    //OutVec(check);
    //cout << Same(check);
	return 0;
}