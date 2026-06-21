#include <iostream>
using namespace std;

bool isPalindrome(char str[]) {
    int length = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

void modifyPalindrome(char password[]) {
    int length = sizeof(password) / sizeof(password[0]);
    if (length % 2 == 0) {
        password[length / 2 - 1] = password[length / 2 - 1] == 'Z' ? 'A' : password[length / 2 - 1] + 1;
        password[length / 2] = password[length / 2] == 'Z' ? 'A' : password[length / 2] + 1;
    }
    else {
        password[length / 2] = password[length / 2] == 'Z' ? 'A' : password[length / 2] + 1;
    }
}

int PasswordModification(char username[], char password[], char forbidden[], int minChars) {
    int modifications = 0;
    int passwordLength = sizeof(password) / sizeof(password[0]);
    int usernameLength = sizeof(username) / sizeof(username[0]);

    if (passwordLength < minChars) {
        int i = 0;
        while (passwordLength < minChars) {
            password[passwordLength++] = username[i++];
            modifications++;
        }
        password[passwordLength] = '\0';
    }

    bool hasUpper = false, hasLower = false;
    for (int i = 0; i < passwordLength; i++) {
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
    }

    if (!hasUpper || !hasLower) {
        if (!hasUpper) {
            password[0] = toupper(password[0]);
            modifications++;
        }
        if (!hasLower) {
            password[0] = tolower(password[0]);
            modifications++;
        }
    }

    bool hasDigit = false;
    for (int i = 0; i < passwordLength; i++) {
        if (isdigit(password[i])) {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        password[passwordLength - 1] = '0' + usernameLength;
        modifications++;
    }

    if (strstr(password, forbidden) != nullptr) {
        char* pos = strstr(password, forbidden);
        while (pos != nullptr) {
            strncpy(pos, "XXX", 3);
            modifications++;
            pos = strstr(password, forbidden);
        }
    }

    if (isPalindrome(password)) {
        modifyPalindrome(password);
        modifications++;
    }

    return modifications;
}

int main() {
    char username[] = "Alice_W";
    char password[] = "password123";
    char forbidden[] = "123";
    int minChars = 8;

    int changes = PasswordModification(username, password, forbidden, minChars);
    cout << "Modified password: " << password << endl;
    cout << "Number of modifications: " << changes << endl;

    return 0;
}
