#include <iostream>
using namespace std;

bool compare(char* s1, int size1, char* s2, int size2) {
    if (size1 != size2) {
        return false;
    }
    
    char* ptr1 = s1;
    char* ptr2 = s2;
    
    for (int i = 0; i < size1; i++) {
        if (*(ptr1 + i) != *(ptr2 + i)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char str1[101], str2[101]; 
    cout << "Input 1: ";
    cin >> str1;
    int size1 = 0;
    char* ptr1 = str1;
    while (*(ptr1 + size1) != '\0') {
        size1++;
    }
    
    cout << "Input 2: ";
    cin >> str2;
    int size2 = 0;
    char* ptr2 = str2;
    while (*(ptr2 + size2) != '\0') {
        size2++;
    }
    
    if (compare(str1, size1, str2, size2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}