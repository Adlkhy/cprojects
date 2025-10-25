#include <iostream>
#include <cstring>
using namespace std;

int compare(char* num1, char* num2) {
    char* ptr1 = num1;
    char* ptr2 = num2;
    
    int len1 = 0, len2 = 0;
    while (*ptr1 != '\0') {
        len1++;
        ptr1++;
    }
    while (*ptr2 != '\0') {
        len2++;
        ptr2++;
    }
    
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    
    ptr1 = num1;
    ptr2 = num2;
    while (*ptr1 != '\0') {
        if (*ptr1 > *ptr2) return 1;
        if (*ptr1 < *ptr2) return -1;
        ptr1++;
        ptr2++;
    }
    return 0;
}

void findMax(char* num1, char* num2, char* num3, char* result) {
    char* maxNum = num1;
    
    if (compare(num2, maxNum) > 0) {
        maxNum = num2;
    }
    
    if (compare(num3, maxNum) > 0) {
        maxNum = num3;
    }
    
    char* src = maxNum;
    char* dest = result;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char num1[101], num2[101], num3[101]; 
    char result[101];
    cin >> num1 >> num2 >> num3;

    findMax(num1, num2, num3, result);
    cout << result << endl;
    
    return 0;
}