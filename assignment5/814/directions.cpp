#include <iostream>
using namespace std;

bool directions(char* s1, char* s2) {
    char* ptr1 = s1;
    char* ptr2 = s2;
    
    while (*ptr1 != '\0' && *ptr2 != '\0') {
        if (*ptr1 != *ptr2) {
            return false;
        }
        ptr1++;
        ptr2++;
    }
    
    return (*ptr1 == '\0' && *ptr2 == '\0');
}

int main() {
    char direction[10];
    int steps;
    int x = 0, y = 0;
    
    while (cin >> direction >> steps) {
        char* ptr = direction;
        
        if (directions(ptr, "North")) {
            y += steps;
        } else if (directions(ptr, "South")) {
            y -= steps;
        } else if (directions(ptr, "East")) {
            x += steps;
        } else if (directions(ptr, "West")) {
            x -= steps;
        }
    }
    
    cout << x << " " << y << endl;
    
    return 0;
}
// to stop input Ctrl + Z then Enter