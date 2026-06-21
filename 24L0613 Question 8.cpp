#include <iostream>
using namespace std;
int main() {
    int num,i=3;
    cout << "Enter a number\n";
    cin >> num;
    cout << "Prime factors of are: \n";
     while (num % 2 == 0) 
     {
        cout << 2 << " ";
        num =num/2;
     }
      while (num > 1) {
        while (num % i == 0) {
            cout << i << " ";
            num /= i;
        }
        i =i+2;
      }    
}
