/*#include<iostream>
using namespace std;
int main()
{
	int A[5];
	int index = 0;
	cout << "Enter 5 elements in array\n";
	for (int p = 0; p < 5; p++)
	{
		cin >> A[p];
	}
	int min = 0, temp = 0;
	for (int i = 0; i < 5; i++)
	{
		min = i;

		for (index = i; index < 5; index++)
		{
			if (A[index] < A[min])
			{
				min = index;
			}
		}
		temp = A[min];
		A[min] = A[i];
		A[i] = temp;
	}
	for (int k = 0; k < 5; k++)
	{
		cout << A[k] << " ";
	}
}*/
	
