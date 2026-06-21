<<<<<<< HEAD
/*#include<iostream>
using namespace std;
int main()
{
	int m, n;
	cout << "Enter number of rows and colums"<<endl;
	cin >> m >> n;
	int  A[m][n];
	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < m; j++)
		{
			cin >> A[i][j];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
	}
}*/
=======
#include<iostream>
using namespace std;
int main()
{
	int num = 0,even=0,odd=0;
	cout << "Enter a number\n";
	cin >> num;
	while (num < 0)
	{
		cout << "Enter a valid positive number\n";
		cin >> num;
	}
	while (num != -1)
	{
		if (num % 2 == 0)
		{
			even += 1;
			cout << "Enter a number(-1 to exit)\n";
			cin >> num;
			while (num < -1)
			{
				cout << "Enter a valid positive number\n";
				cin >> num;
			}
		}
		if (num % 2 == 1)
		{
			odd += 1;
			cout << "Enter a number(-1 to exit)\n";
			cin >> num;
			while (num < -1)
			{
				cout << "Enter a positive valid number\n";
				cin >> num;
			}
		}
	}
	cout << "Frequency of even is " << even << endl;
	cout << "Frequency of odd is " << odd << endl;
}
>>>>>>> bb32fe2c3aaf374633a07d0948a2c51957adff7c
