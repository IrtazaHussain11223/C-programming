/*#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int matrix[m][n];
    int num = 2;

    for (int i = 0; i < m; ++i)
    {
    for (int j = 0; j < n; ++j) 
    {
    bool is_prime = false;
    while (!is_prime)
    {
    is_prime = true;
    for (int k = 2; k * k <= num; ++k)
    {
     if (num % k == 0) 
     {
     is_prime = false;
     break;
     }
     }
     if (is_prime) 
     {
        matrix[i][j] = num;
     }
     else 
     {
     num++;
     }
     }
            num++;
    }
    }

    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/