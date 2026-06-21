#include<iostream>
using namespace std;
int main()
{
	int deposite = 0, withdraw = 0, current = 0, initial = 0, option = 0;
	cout << "Bank Account menu\n1. Deposite 2.Withdraw -1.Quit";
	cout << "choose an option\n";
	cin >> option;
	while ((option <= -1) || (option >= 2))
	{
		cout << "Enter the correct option\n";
		cin >> option;
	}
	while (option != -1)
	{
		if (option == 1)
		{
			cout << "Enter amount to deposit\n";
			cin >> deposite;
			cout << "Deposited" << " " << deposite << endl;
			current = deposite;
			cout << "Current Balance" << " " << current << endl;
			cout << "Again enter choice\n";
			cin >> option;
		}
		if (option == 2)
		{
			cout << "Enter amount to withdraw\n" << endl;
			cin >> withdraw;
			while (withdraw >= deposite)
			{
				cout << "Insufficient balance\n";
				cout << "Enter amount to withdraw\n" << endl;
				cin >> withdraw;

			}
			cout << "Withdrawn amount is " << withdraw << endl;
			current = deposite - withdraw;
			cout << "Current balance is " << current << endl;
			cout << "Again enter choice\n";
			cin >> option;

		}
		if (option == -1)
		{
			cout << "Final balance is " << current;
		}
	}
}