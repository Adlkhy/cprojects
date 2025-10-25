#include <iostream>
using namespace std;

void decrypt(char* cypher, int k) {
    char* ptr = cypher;
    
    while (*ptr != '\0') {
        char decrypted = *ptr - k;
        
        while (decrypted < 'A') {
            decrypted += 26;
        }
        
        *ptr = decrypted;
        ptr++;
    }
}

int main() {
    char cypher[101];
    int k;
    cout << "Input: ";
    cin >> cypher;
    cin >> k;
    
    decrypt(cypher, k);
    
    cout << "Output: " << cypher << endl;
    
    return 0;
}