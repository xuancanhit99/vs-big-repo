#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> arr1;
    vector<long long> arr2;
    int z;
    int arr1size = 5;
    int arr2size = 5;
    for (int r = 0; r < 5; r++) {
        cin >> z;
        arr1.push_back(z);
    }
    for (int w = 0; w < 5; w++) {
        cin >> z;
        arr2.push_back(z);
    }
    for (long long i = 0; i < 1000000; i++) {
        if (arr2size == 0) {
            cout << "first " << i + 1;
            return 0;
        }
        if (arr1size == 0) {
            cout << "second " << i + 1;
            return 0;
        }
        if (arr1[i] > arr2[i] and arr2[i] != 0) {
            arr1.push_back(arr1[i]);
            arr1.push_back(arr2[i]);
            arr1size += 2;
            arr2size -= 1;
        }
        if (arr2[i] > arr1[i] and arr1[i] != 0) {
            arr2.push_back(arr1[i]);
            arr2.push_back(arr2[i]);
            arr2size += 2;
            arr1size -= 1;
        }
        if (arr2[i] == 0) {
            arr2.push_back(arr1[i]);
            arr2.push_back(arr2[i]);
            arr2size += 2;
            arr1size -= 1;
        }
        if (arr1[i] == 0) {
            arr1.push_back(arr1[i]);
            arr1.push_back(arr2[i]);
            arr1size += 2;
            arr2size -= 1;
        }

    }
    cout << "botva";
    return 0;
}