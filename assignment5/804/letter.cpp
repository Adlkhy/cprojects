#include <iostream>
#include <cctype>
using namespace std;

void letters(char* source, char* destination) {
    char* src = source;
    char* dest = destination;
    
    while (*src != '\0') {
        if (isalpha(*src)) {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0'; 
}

int main() {
    char input[101]; 
    char output[101]; 
    cout << "Input: ";
    cin >> input;
    
    letters(input, output);
    cout << "Output: " << output << endl;

    return 0;
}