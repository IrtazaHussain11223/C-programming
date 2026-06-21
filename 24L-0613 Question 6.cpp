#include<iostream>
using namespace std;
int main()
{
	int n = 501,sum=0;
	while (n > 500 && n < 3000)
	{
		if (n % 3 == 0)
		{
			sum += n;
		}
		if (n % 5 == 0)
		{
			sum += n;
        }
		if ((n % 3 == 0) && (n % 5 == 0))
		{
			sum = sum - (2 * n);
		}
		n++;
	}
	cout << "Sum is " << sum;
}