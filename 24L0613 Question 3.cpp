/*#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int Limit, num, originalNum, sum, count, digit;

    cout << "Enter the upper limit  ";
    cin >> Limit;

    while (Limit <= 100) {
        cout << " Enter a number greater than 100: ";
        cin >>Limit;
    }

    cout << "Armzstronge numbers are ";

    for (num = 100; num <= Limit; num++) {
        originalNum = num;
        sum = 0;
        count = 0;

        while (originalNum != 0) {
            originalNum /= 10;
            count++;
        }

        originalNum = num;
        po(digit,count
        while (originalNum != 0) {
            digit = originalNum % 10;
            originalNum /= 10;
        }

        if (sum == num) {
            cout << num << " ";
        }
    }

    
}*/