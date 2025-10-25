#include <iostream>
using namespace std;

int MinMax(int* arr, int n) {
    int* ptr = arr;
    
    int minPos = 0, maxPos = 0;
    int minVal = *ptr, maxVal = *ptr;
    
    for (int i = 1; i < n; i++) {
        if (*(ptr + i) < minVal) {
            minVal = *(ptr + i);
            minPos = i;
        }
        if (*(ptr + i) > maxVal) {
            maxVal = *(ptr + i);
            maxPos = i;
        }
    }
    
    int start, end;
    if (minPos < maxPos) {
        start = minPos + 1;
        end = maxPos - 1;
    } else {
        start = maxPos + 1;
        end = minPos - 1;
    }
    
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (*(ptr + i) % 2 == 0) {
            count++;
        }
    }
    
    return count;
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
    
    int result = MinMax(arr, n);
    cout << "Output: " << result << endl;
    
    return 0;
}