#include <iostream>
using namespace std;

void swap2(unsigned int* a, unsigned int* b) {
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    unsigned int a, b;
    cout << "Input: ";
    cin >> a >> b;
    
    swap2(&a, &b);
    cout << "Output: " << a << " " << b << endl;
    return 0;
}