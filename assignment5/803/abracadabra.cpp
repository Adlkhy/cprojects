#include <iostream>
using namespace std;

int countChar(char* str, char target) {
    int count = 0;
    char* ptr = str;
    
    while (*ptr != '\0') {
        if (*ptr == target) {
            count++;
        }
        ptr++;
    }
    return count;
}

int main() {
    int N;
    cout << "Input: ";
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        char target;
        char str[21];
        cin >> target >> str;
        
        int count = countChar(str, target);
        cout << count << " " << target << " in " << str << endl;
    }
    
    return 0;
}