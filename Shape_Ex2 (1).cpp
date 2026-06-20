#include<iostream>
using namespace std;

int main()
{int H; //height
    char symbol;
    cout << "Enter height: ";
    cin >> H;
    cout << "Enter symbol: ";
    cin >> symbol;
    for(int ln = 1; ln <= H; ln++)
    {
        for(int j = 1; j < ln; j++)
        {
            cout<<" ";
        }
		for(int k = H; k >= ln;  k--)
        {
            cout<<symbol;
        }
        
        cout<<endl;
    }


system("pause");
return 0;

}

