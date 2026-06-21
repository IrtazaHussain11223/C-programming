<<<<<<< HEAD
/*#include<iostream>
using namespace std;
int main()
{
	int lim = 0, i = 0, j = 0, z = 0;
	cout << "Enter the height\n";
	cin >> lim;
	for (i = 1; i <= lim; i++)
	{
		for (z = 1; z <= i; z++)
		{
			cout << " ";
		}
		for (j = lim; j >= i; --j)
		{
			cout << "*" << " ";
		}
		cout << "\n";
	}
}*/
=======
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
>>>>>>> bb32fe2c3aaf374633a07d0948a2c51957adff7c
