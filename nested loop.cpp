#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int size;
	cout << "Enter the size of table";
	cin >> size;
	int row = 1,col,product;
	while (row <= size)
	{
		col = 1;
		while (col <= size)
		{
			product = row * col;
			if (row != col)
			{
				cout << setw(4) << product;
			}
			else
			{
				cout << setw(4) << 0;
			}
			col++;
		}
			row++;
			cout << "\n";
	
	}





	return 0;
}