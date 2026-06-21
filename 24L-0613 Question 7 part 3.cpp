#include<iostream>
using namespace std;
int main()
{
	int start = 0, end = 0, n1 = 0, n2 = 1, next_term = 0;
	cout << "Enter the starting digit\n";
	cin >> start;
	cout << "Enter the last digit\n";
	cin >> end;
	while (start < 0 || end < 0)
	{
		if (start < 0)
		{
			cout << "Enter correct starting value\n";
		}
	}
	if (start == 0)
	{
		cout << "0 1 ";
	}
	if (start == 1)
	{
		cout << "1 ";
	}
	while (next_term <= end)
	{
		next_term = n1 + n2;
		n1 = n2;
		n2 = next_term;
		if (next_term >= start && next_term <= end)
		{
			cout << next_term << " ";
		}
		
		
	}

}