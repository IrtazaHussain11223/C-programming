#include<iostream>
using namespace std;
int main()
{
	int limit, n1 = 0,n2=1,next_term=0;
	cout << "You want to Print Up to\n";
	cin >> limit;
	if (limit == 0)
	{
		cout << "0 ";
	}
	if (limit == 1)
	{
		cout << "0 1 ";
	}
	if (limit > 1)
	{
		cout << "0 1 ";
	}
	while(next_term<limit)
	{
		next_term = n1 + n2;
		n1 = n2;
		n2 = next_term;
		if (next_term <= limit)
		{
			cout << next_term << " ";
		}
	}
}