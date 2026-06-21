<<<<<<< HEAD
/*#include <iostream>
using namespace std;
int main()
{
	int A[5];
	int i = 0, j = 0, max = 0, min = 0;
	for (i = 0; i < 5; i++)
	{
		cin >> A[i];
	}
	max = A[0];
	for (i = 0; i < 5; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	cout << "MAximum value is " << max<<endl;
	min = A[0];
	for (i = 0; i < 5; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
	}
	cout << "Minimum value is " << min;
}*/
=======
#include<iostream>
using namespace std;
int main()
{
	bool correctday = true;
	int crm = 0, crd = 0, cry = 0, finalday = 0, finalmonth = 0, finalyear = 0;
	int pd = 0, pm = 0, py = 0;
	cout << "Enter present date in this format(DD/MM/YY)\n";
	cin >> crd >> crm >> cry;
	cout << "Enter your date of brith is this format(DD/MM/YY)\n";
	cin >> pd >> pm >> py;
	while (pm > 12 || crm > 12)
	{
		if (crm > 12)
		{
			cout << "Enter correct mounth in current date\n";
			cin >> crm;
		}
		if (pm > 12)
		{
			cout << "Enter correct mounth in date of birth\n";
			cin >> pm;
		}
	}
	while (py > cry)
	{
		cout << "Enter correct year of your born date\n";
		cin >> py;
	}
	while (correctday)
	{
		if (pm == 1 || crm == 1)
		{
			while (pd > 31)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 31)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		if (pm == 2 || crm == 2)
		{
			if ((py % 4 == 0 && py % 100 != 0) || (py % 100 == 0 && py % 400 == 0))
			{
				while (pd > 29)
				{
					cout << "Enter correct day in date of birth\n";
					cin >> pd;
				}
				while (crd > 29)
				{
					cout << "Enter correct currenct date\n";
					cin >> crd;
				}
			}
			else {
				while (pd > 28)
				{
					cout << "Enter correct day in date of birth\n";
					cin >> pd;
				}
				while (crd > 28)
				{
					cout << "Enter correct currenct date\n";
					cin >> crd;
				}
			}
		}
		if (pm == 3 || crm == 3)
		{
			while (pd > 31)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 31)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		if (pm == 4 || crm == 4)
		{
			while (pd > 30)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 30)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		if (pm == 5 || crm == 5)
		{
			while (pd > 31)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 31)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		if (pm == 6 || crm == 6)
		{
			while (pd > 30)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 30)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		if (pm == 7 || crm == 7)
		{
			while (pd > 31)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 31)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		if (pm == 8 || crm == 8)
		{
			while (pd > 31)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 31)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		if (pm == 9 || crm == 9)
		{
			while (pd > 30)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 30)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}

		if (pm == 10 || crm == 10)
		{
			while (pd > 31)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 31)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}

		if (pm == 11 || crm == 11)
		{
			while (pd > 30)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 30)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}

		if (pm == 12 || crm == 12)
		{
			while (pd > 31)
			{
				cout << "Enter correct day in date of birth\n";
				cin >> pd;
			}
			while (crd > 31)
			{
				cout << "Enter correct currenct date\n";
				cin >> crd;
			}
		}
		correctday = false;
	}
	if (pd > crd)
	{
		if (crm == 1)
			crd += 31;
		if (crm == 2)
			crd += 31;
		if (crm == 3)
			crd += 28;
		if (crm == 4)
			crd += 31;
		if (crm == 5)
			crd += 30;
		if (crm == 6)
			crd += 31;
		if (crm == 7)
			crd += 30;
		if (crm == 8)
			crd += 31;
		if (crm == 9)
			crd += 31;
		if (crm == 10)
			crd += 30;
		if (crm == 11)
			crd += 31;
		if (crm == 12)
			crd += 30;
		crm -= 1;
	}
	finalday = crd - pd;
	if (pm > crm)
	{
		crm += 12;
		cry -= 1;
	}
	finalmonth = crm - pm;
	finalyear = cry - py;
	cout << "You are " << finalday << " days " << finalmonth << " Mouths and " << finalyear << " years Old";
}
>>>>>>> bb32fe2c3aaf374633a07d0948a2c51957adff7c
