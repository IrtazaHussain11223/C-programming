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