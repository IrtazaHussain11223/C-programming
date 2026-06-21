#include <iostream>
using namespace std;

double stonum(char num[]) {
    double result = 0.0;
    double decimalPlace = 0.1;
    bool isNegative = false;
    bool isDecimal = false;
    int i = 0;

    if (num[0] == '-') {
        isNegative = true;
        i = 1;
    }

    for (; num[i] != '\0'; i++) {
        if (num[i] == '.') {
            if (isDecimal) {
                cout << "Error: Invalid input with multiple decimal points." << endl;
                return -1;
            }
            isDecimal = true;
        }
        else if (!isdigit(num[i])) {
            cout << "Error: Invalid input containing non-numeric characters." << endl;
            return -1;
        }
        else {
            if (isDecimal) {
                result += (num[i] - '0') * decimalPlace;
                decimalPlace /= 10;
            }
            else {
                result = result * 10 + (num[i] - '0');
            }
        }
    }

    if (isNegative) {
        result = -result;
    }

    return result;
}

int main() {
    char input1[] = "321.110";
    char input2[] = "-2341";
    char input3[] = "231d99";

    cout << "Input: \"" << input1 << "\" Return Value: " << stonum(input1) << endl;
    cout << "Input: \"" << input2 << "\" Return Value: " << stonum(input2) << endl;
    cout << "Input: \"" << input3 << "\" Return Value: " << stonum(input3) << endl;

    return 0;
}
