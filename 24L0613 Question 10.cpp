#include <iostream>
using namespace std;

int main() {
    int num;
    float total = 0;

    cout << "Enter the number of students: ";
    cin >> num;
    for (int i = 1; i <= num; i++) {
        float grade;
        cout << "Enter grade for student " << i << ": ";
        cin >> grade;
        while (grade < 0 || grade>100)
        {
            cout << "Enter valid grade\n";
            cin >> grade;
        }
        total =total + grade;
    }
    float average = total / num;
    cout << "Average grade: " << average << endl;

    return 0;
}