#include <iostream>
#include <cctype>
using namespace std;

void formatNumber(char* digits, char* result) {
    int len = 0;
    char* ptr = digits;
    while (*ptr != '\0') {
        len++;
        ptr++;
    }
    
    char* resPtr = result;
    
    int firstGroupSize = len % 3;
    if (firstGroupSize == 0) firstGroupSize = 3;
    
    ptr = digits;
    for (int i = 0; i < firstGroupSize; i++) {
        *resPtr = *ptr;
        resPtr++;
        ptr++;
    }
    
    while (*ptr != '\0') {
        *resPtr = ' ';
        resPtr++;
        
        for (int i = 0; i < 3 && *ptr != '\0'; i++) {
            *resPtr = *ptr;
            resPtr++;
            ptr++;
        }
    }
    
    *resPtr = '\0';
}

void findLongestDigitSequence(char* text, char* result) {
    char* textPtr = text;
    char longestSeq[1001] = "";
    int maxLen = 0;
    
    while (*textPtr != '\0') {
        if (isdigit(*textPtr)) {
            char* seqStart = textPtr;
            char currentSeq[1001];
            char* currPtr = currentSeq;
            int currentLen = 0;
            
            while (isdigit(*textPtr)) {
                *currPtr = *textPtr;
                currPtr++;
                textPtr++;
                currentLen++;
            }
            *currPtr = '\0';
            
            if (currentLen > maxLen) {
                maxLen = currentLen;
                char* dest = longestSeq;
                char* src = currentSeq;
                while (*src != '\0') {
                    *dest = *src;
                    dest++;
                    src++;
                }
                *dest = '\0';
            }
        } else {
            textPtr++;
        }
    }
    
    if (maxLen > 0) {
        formatNumber(longestSeq, result);
    } else {
        result[0] = '\0';
    }
}

int main() {
    char text[1001];
    char result[1001];
    cout << "Input: ";
    cin.getline(text, 1001);
    
    findLongestDigitSequence(text, result);
    cout << "Output: " << result << endl;
    
    return 0;
}