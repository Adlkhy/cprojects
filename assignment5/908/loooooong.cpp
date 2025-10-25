#include <iostream>
#include <cstring>
using namespace std;

void addVeryLongIntegers(char* a, char* b, char* c) {
    char* ptrA = a;
    char* ptrB = b;
    char* ptrC = c;
    
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    
    for (int i = 0; i <= maxLen; i++) {
        *(ptrC + i) = '0';
    }
    *(ptrC + maxLen + 1) = '\0';
    
    int carry = 0;
    
    for (int i = 0; i <= maxLen; i++) {
        int digitA = (i < lenA) ? (*(ptrA + lenA - 1 - i) - '0') : 0;
        int digitB = (i < lenB) ? (*(ptrB + lenB - 1 - i) - '0') : 0;
        
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        
        *(ptrC + maxLen - i) = (sum % 10) + '0';
    }
    
    if (*ptrC == '0' && maxLen > 0) {
        char* src = ptrC + 1;
        char* dest = ptrC;
        while (*src != '\0') {
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0';
    }
}

int main() {
    char a[1002], b[1002], c[1002];
    cout << "Input: ";
    cin >> a >> b;
    
    addVeryLongIntegers(a, b, c);
    cout << "Output: " << c << endl;
    
    return 0;
}