#include <iostream>
#include <cctype>
using namespace std;

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

void deleteDuplicates(char* text, char* result) {
    char words[500][31];
    int counts[500] = {0};
    int wordCount = 0;
    
    char* resPtr = result;
    char* textPtr = text;
    
    while (*textPtr != '\0') {
        if (isalpha(*textPtr)) {
            char currentWord[31];
            char* currPtr = currentWord;
            
            while (isalpha(*textPtr)) {
                *currPtr = *textPtr;
                currPtr++;
                textPtr++;
            }
            *currPtr = '\0';
            
            bool found = false;
            for (int i = 0; i < wordCount; i++) {
                if (compareWords(words[i], currentWord)) {
                    counts[i]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                char* dest = words[wordCount];
                char* src = currentWord;
                while (*src) {
                    *dest = *src;
                    dest++;
                    src++;
                }
                *dest = '\0';
                counts[wordCount] = 1;
                wordCount++;
            }
        } else {
            textPtr++;
        }
    }
    
    textPtr = text;
    resPtr = result;
    bool firstOccurrence[500] = {false};
    
    while (*textPtr != '\0') {
        if (isalpha(*textPtr)) {
            char currentWord[31];
            char* currPtr = currentWord;
            char* start = textPtr;
            
            while (isalpha(*textPtr)) {
                *currPtr = *textPtr;
                currPtr++;
                textPtr++;
            }
            *currPtr = '\0';
            
            int idx = -1;
            for (int i = 0; i < wordCount; i++) {
                if (compareWords(words[i], currentWord)) {
                    idx = i;
                    break;
                }
            }
            
            if (idx != -1 && (!firstOccurrence[idx] || counts[idx] == 1)) {
                char* temp = start;
                while (temp < textPtr) {
                    *resPtr = *temp;
                    resPtr++;
                    temp++;
                }
                firstOccurrence[idx] = true;
            }
        } else {
            *resPtr = *textPtr;
            resPtr++;
            textPtr++;
        }
    }
    *resPtr = '\0';
}

int main() {
    char text[1001];
    char result[1001];
    cout << "Input: ";
    cin.getline(text, 1001);
    
    deleteDuplicates(text, result);
    cout << "Output: " << result << endl;
    
    return 0;
}