#include <iostream>
#include <cctype>
using namespace std;

bool findIITU(char* str) {
    char* ptr = str;
    
    while (*ptr != '\0') {
        if (toupper(*ptr) == 'I' && toupper(*(ptr + 1)) == 'T' && toupper(*(ptr + 2)) == 'U') {
            return true;
        }
        ptr++;
    }
    return false;
}

int main() {
    char line[1001];
    cout << "Input: ";
    cin.getline(line, 1001);
    
    if (findIITU(line)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}