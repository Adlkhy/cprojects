#include <iostream>
using namespace std;

int sumBetweenZeros(int* arr, int n) {
    int* ptr = arr;
    bool foundFirstZero = false;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        if (*(ptr + i) == 0) {
            if (!foundFirstZero) {
                foundFirstZero = true;
            } else {
                break;
            }
        } else if (foundFirstZero) {
            sum += *(ptr + i);
        }
    }
    
    return sum;
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    
    int arr[100];
    int* ptr = arr;
    
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);
    }
    
    int result = sumBetweenZeros(arr, n);
    cout << result << endl; 
    
    return 0;
}