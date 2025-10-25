#include <iostream>
using namespace std;

bool isPalindrome(char* str, int size) {
    char* left = str;
    char* right = str + size - 1;
    
    while (left < right) {
        if (*left != *right) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    char str[101]; 
    cout << "Input: ";
    cin >> str;
    
    int size = 0;
    char* ptr = str;
    while (*ptr != '\0') {
        size++;
        ptr++;
    }
    
    if (isPalindrome(str, size)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}