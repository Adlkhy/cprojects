#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

bool isStrongPassword(const string& password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char c : password) {
        if (isupper(c)) {
            hasUpper = true;
        } else if (islower(c)) {
            hasLower = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (ispunct(c)) { 
            hasSpecial = true;
        }
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    string userPassword;
    cout << "Enter your password: ";
    cin >> userPassword;

    if (isStrongPassword(userPassword)) {
        cout << "Password is valid." << endl;
    } else {
        cout << "Password is invalid." << endl;
    }

    return 0;
}