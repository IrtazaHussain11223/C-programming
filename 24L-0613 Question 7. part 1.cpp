#include<iostream>
using namespace std;
int main()
{
	long int limit = 0,n1=0,n2=1,next_term=0,choice=0,i,tries=0;
	cout << "How many Fibonacci Numbers you want to ask:\n";
	cin >> limit;
	while (tries < limit)
	{
		n1 = 0, n2 = 1, next_term = 0;
		cout << "Which Fibonacci\n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "F1=0\n";
		}
		if (choice == 2)
		{
			cout << "F2=1\n";
		}
		for (i = 2; i < choice; i++)
		{
			next_term = n1 + n2;
			n1 = n2;
			n2 = next_term;
		}
		if (choice != 1 && choice != 2)
		{
			cout << "F" << i << "=" << next_term << endl;
		}
			tries++;
		
	}
		
	
}