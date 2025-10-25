#include <iostream>
#include <cctype>
using namespace std;

void toUpperCase(char* word) {
    char* ptr = word;
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

void toLowerCase(char* word) {
    char* ptr = word;
    while (*ptr != '\0') {
        *ptr = tolower(*ptr);
        ptr++;
    }
}

bool compareWords(char* word1, char* word2) {
    char* ptr1 = word1;
    char* ptr2 = word2;
    
    while (*ptr1 != '\0' && *ptr2 != '\0') {
        if (tolower(*ptr1) != tolower(*ptr2)) {
            return false;
        }
        ptr1++;
        ptr2++;
    }
    return (*ptr1 == '\0' && *ptr2 == '\0');
}

void mostRecent(char* text, char* word) {
    char words[500][101]; 
    int counts[500] = {0};
    int wordCount = 0;
    
    char* textPtr = text;
    
    while (*textPtr != '\0') {
        while (*textPtr != '\0' && !isalpha(*textPtr)) {
            textPtr++;
        }
        
        if (*textPtr == '\0') break;
        
        char currentWord[101];
        char* currentPtr = currentWord;
        
        while (*textPtr != '\0' && isalpha(*textPtr)) {
            *currentPtr = *textPtr;
            currentPtr++;
            textPtr++;
        }
        *currentPtr = '\0';
        
        if (currentWord[0] != '\0') {
            toLowerCase(currentWord);
            
            bool found = false;
            for (int i = 0; i < wordCount; i++) {
                if (compareWords(words[i], currentWord)) {
                    counts[i]++;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                char* destPtr = words[wordCount];
                char* srcPtr = currentWord;
                while (*srcPtr != '\0') {
                    *destPtr = *srcPtr;
                    destPtr++;
                    srcPtr++;
                }
                *destPtr = '\0';
                counts[wordCount] = 1;
                wordCount++;
            }
        }
    }
    
    int maxCount = 0;
    int maxIndex = 0;
    
    for (int i = 0; i < wordCount; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            maxIndex = i;
        }
    }
    
    char* srcPtr = words[maxIndex];
    char* destPtr = word;
    
    while (*srcPtr != '\0') {
        *destPtr = toupper(*srcPtr);
        destPtr++;
        srcPtr++;
    }
    *destPtr = '\0';
}

int main() {
    char text[1001];
    char result[101];
    cout << "Input: ";
    cin.getline(text, 1001);
    
    mostRecent(text, result);
    cout << "Output: " << result << endl;

    return 0;
}