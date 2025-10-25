#include <iostream>
using namespace std;

void rearrange(int* arr, int n) {
    int result[100];
    int* ptr = result;
    
    for (int i = 0; i < n; i += 2) {
        *ptr = *(arr + i);
        ptr++;
    }
    
    for (int i = 1; i < n; i += 2) {
        *ptr = *(arr + i);
        ptr++;
    }
    
    for (int i = 0; i < n; i++) {
        *(arr + i) = result[i];
    }
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
    
    rearrange(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i);
        if (i < n - 1) {
            cout << " ";
        }
    }
    
    return 0;
}