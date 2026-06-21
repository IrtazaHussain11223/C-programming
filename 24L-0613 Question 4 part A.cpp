#include<iostream>
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0, limit = 1000;
	for (a = 0; a <= limit; a++)
	{
		for (b = 0; b <= limit; b++)
		{
			for (c = 0; c <= limit; c++)
			{
				if ((a * a + b * b + c * c )== 1000)
				{
					cout << a << " " << b << " " << c<<endl;
				}
			}
		}
	}
}