#include <iostream>
using namespace std;

bool isDivisibleBy11(char* num) {
    char* ptr = num;
    int sum = 0;
    int multiplier = 1;
    
    int len = 0;
    char* endPtr = num;
    while (*endPtr != '\0') {
        len++;
        endPtr++;
    }
    
    for (int i = len - 1; i >= 0; i--) {
        int digit = *(num + i) - '0';
        sum += multiplier * digit;
        multiplier = -multiplier;
    }
    
    return (sum % 11 == 0);
}

int main() {
    char num[1002];
    cout << "Input: ";
    cin >> num;
    
    if (isDivisibleBy11(num)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}