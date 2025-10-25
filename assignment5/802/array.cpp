#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    
    int arr[100];
    int *ptr = arr; 
    
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i);
        if (i < n - 1) {
            cout << " ";
        }
    }
    
    return 0;
}