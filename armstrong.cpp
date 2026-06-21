/*#include<iostream>
using namespace std;
int main()
{
	int num = 0,num2=0,count=0,arm=0,arm1=1;
	cout << "Enter the number\n";
	cin >> num;
	int orgnum = num;
	int dummy = num;
	int dummy1 = 0;
	while (dummy > 0)
	{
		dummy1 = dummy % 10;
		dummy /= 10;
		count++;
	}
	
	while (num > 0)
	{
		arm1 = 1;
		num2 = num % 10;
		num /= 10;
		for (int i = 0; i < count; i++)
		{
			arm1 *= num2;
		}
		arm += arm1;
	}
	if (arm == orgnum)
	{
		cout << "It is an armstrong number\n ";
	}
	else
		cout << "not an arm strong";
}*/