#include<iostream>
using namespace std;
int main()
{
	long int limit = 4000000,sum=0;
	int n1 = 0, n2 = 1, next_term = 0;
    while (next_term <= limit)
	{
		next_term = n1 + n2;
		n1 = n2;
		n2 = next_term;
		if (next_term % 2 == 0)
		{
			sum += next_term;
		}
	}
	cout <<"The sum of even fabnonci numbers is  " << sum;
}