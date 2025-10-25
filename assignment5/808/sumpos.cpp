#include <iostream>
using namespace std;

int sumBeforeMax(int* arr, int n) {
    int* ptr = arr;
    
    int maxPos = 0;
    int maxValue = 0;
    
    for (int i = 1; i < n; i++) {
        if (*(ptr + i) > maxValue) {
            maxValue = *(ptr + i);
            maxPos = i;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < maxPos; i++) {
        if (*(ptr + i) > 0) {
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
    
    int result = sumBeforeMax(arr, n);
    cout << "Output: " << result << endl;
    
    return 0;
}