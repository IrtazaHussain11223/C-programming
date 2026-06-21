#include<iostream>
using namespace std;
int main()
{
	long int num = 0;
	int i = 0, j = 1, k = 2;
	long int result=0;
	cout << "Enter the number\n";
	cin >> num;
	while (num < 0)
	{
		cout << "Enter a positive number\n";
		cin >> num;
	}

	while ((result!=num)&&(result<=num))
	{

		result = i * j * k;
		if (result != num)
		{
			i += 1;
			j += 1;
			k += 1;
		}
	}
	if (result == num)
		cout <<"Numbers are " << i << " " << j << " " << k;
	else
		cout << "no consective number exists whose product is equal to "<<num;
}