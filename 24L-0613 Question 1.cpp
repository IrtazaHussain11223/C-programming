<<<<<<< HEAD
/*#include<iostream>
using namespace std;
int main()
{
	int lim = 0,i=0,j=0,z=0;
	cout << "Enter the height\n";
	cin >> lim;
	for (i = 1; i <= lim; i++)
	{
		for (z = lim; z >= i; z--)
		{
			cout << " ";
		}
		for (j = 1; j <=i; ++j)
		{
			cout << j<<" ";
		}
		cout << "\n";
	}
}*/
=======
#include<iostream>
using namespace std;
int main()
{
	int num1 = 0, num2 = 0, GCD = 0, LCM = 0, REM = 0;
	cout << "Enter number 1 and number 2\n";
	cin >> num1 >> num2;
	while (num1 < 0 || num2 < 0)
	{
		cout << "Enter positive number\n";
		cin >> num1 >> num2;
	}
	LCM = num1 * num2;
	if (num1 > num2)
	{
		while (num2 != 0)
		{
			REM = num1 % num2;
			num1 = num2;
			num2 = REM;
		}
		GCD = num1;
	}
	if (num2 > num1)
	{
		while (num1 != 0)
		{
			REM = num2 % num1;
			num2 = num1;
			num1 = REM;
		}
		GCD = num2;
	}
	LCM = LCM / GCD;
	cout << "LCM is " <<LCM;
	
}
>>>>>>> bb32fe2c3aaf374633a07d0948a2c51957adff7c
