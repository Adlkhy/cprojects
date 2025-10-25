#include <iostream>
#include <cctype>
using namespace std;

bool isValidIP(char* ip) {
    char* ptr = ip;
    int partCount = 0;
    int currentNum = 0;
    int digitCount = 0;
    
    while (*ptr != '\0') {
        if (*ptr == '.') {
            if (digitCount == 0 || currentNum < 0 || currentNum > 255) {
                return false;
            }
            partCount++;
            currentNum = 0;
            digitCount = 0;
        } else if (isdigit(*ptr)) {
            currentNum = currentNum * 10 + (*ptr - '0');
            digitCount++;
            
            if (digitCount > 1 && currentNum == 0) {
                return false;
            }
            
            if (currentNum > 255) {
                return false;
            }
        } else {
            return false;
        }
        ptr++;
    }
    
    if (digitCount == 0 || currentNum < 0 || currentNum > 255) {
        return false;
    }
    partCount++;
    
    return partCount == 4;
}

int main() {
    char ip[16];
    cout << "Input: ";
    cin >> ip;
    
    if (isValidIP(ip)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}