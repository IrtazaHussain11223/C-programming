#include<iostream>
using namespace std;
int main()
{
	int num = 0,even=0,odd=0;
	cout << "Enter a number\n";
	cin >> num;
	while (num < 0)
	{
		cout << "Enter a valid positive number\n";
		cin >> num;
	}
	while (num != -1)
	{
		if (num % 2 == 0)
		{
			even += 1;
			cout << "Enter a number(-1 to exit)\n";
			cin >> num;
			while (num < -1)
			{
				cout << "Enter a valid positive number\n";
				cin >> num;
			}
		}
		if (num % 2 == 1)
		{
			odd += 1;
			cout << "Enter a number(-1 to exit)\n";
			cin >> num;
			while (num < -1)
			{
				cout << "Enter a positive valid number\n";
				cin >> num;
			}
		}
	}
	cout << "Frequency of even is " << even << endl;
	cout << "Frequency of odd is " << odd << endl;
}