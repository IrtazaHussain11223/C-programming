#include <iostream>
using namespace std;

int main() {
    int num = 0, i = 0;
    cout << "Enter the number \n";
    cin >> num;
     while (num != -1) 
     {
        i = 0; 
        while ((i * i) <= num) 
        {
            if (num == i * i) {
                cout << "It is a perfect square of " << i << endl;
                break;
            }
            i++;
        }
        if (num != i * i) 
        {
            cout << "Not a perfect square\n";
        }

        cout << "Again Enter a number \n";
        cin >> num; 
     }

   
}