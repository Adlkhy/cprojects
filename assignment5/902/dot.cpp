#include <iostream>
using namespace std;

void replace(char* source, char* dest) {
    char* srcPtr = source;
    char* destPtr = dest;
    
    while (*srcPtr != '\0') {
        if (*srcPtr == '!') { 
            *destPtr = '.';
        } else {
            *destPtr = *srcPtr;
        }
        srcPtr++;
        destPtr++;
    }
    *destPtr = '\0';
}

int main() {
    char source[1001];
    char dest[1001];
    cout << "Input: ";
    cin.getline(source, 1001);
    
    replace(source, dest);
    cout << "Output: " << dest << endl;
    
    return 0;
}