#include <iostream>
#include <cstring>
using namespace std;

void formatNumber(char* input, char* output) {
    int len = strlen(input);
    char* outPtr = output;
    
    int firstGroupSize = len % 3;
    if (firstGroupSize == 0) firstGroupSize = 3;
    
    char* inPtr = input;
    
    for (int i = 0; i < firstGroupSize; i++) {
        *outPtr = *inPtr;
        outPtr++;
        inPtr++;
    }
    
    while (*inPtr != '\0') {
        *outPtr = ' ';
        outPtr++;
        
        for (int i = 0; i < 3 && *inPtr != '\0'; i++) {
            *outPtr = *inPtr;
            outPtr++;
            inPtr++;
        }
    }
    
    *outPtr = '\0';
}

int main() {
    char input[101];
    char output[150];
    cout << "Input: ";
    cin >> input;
    
    formatNumber(input, output);
    cout << "Output: " << output << endl;
    
    return 0;
}