///*#include<iostream>
//using namespace std;
//int main()
//{
//	int num = 0,arm=0,org=0,new1=0,count=0,i=0;
//	cout << "Enter the number\n";
//	cin >> num;
//	 while (num <= 0)
//	 {
//		 cout << "Enter a valid number\n";
//		 cin >> num;
//	 }
//	 org = num;
//	while (num > 0)
//	{
//		new1 = num % 10;
//		num /= 10;
//		count += 1;
//		for ( i = 0; i < count; i++)
//		{
//			arm+=new1
//		}
//	}
//	if (arm == org)
//	{
//		cout << "It is armstrong\n";
//	}
//	else
//		cout << "Not";
//	return 0;
//	
//	}*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	int Arr[5];
//	int tmp = 0;
//	cout << "Enter the elements of array\n";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> Arr[i];
//	}
//	for (int i = 0; i < 5 - 1; i++)
//	{
//		for (int j = 0; j < 5 - 1 - i; j++)
//		{
//			if (Arr[j] > Arr[j + 1])
//			{
//				tmp = Arr[j];
//				Arr[j] = Arr[j + 1];
//				Arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (int k = 0; k < 5; k++)
//	{
//		cout << Arr[k] << " ";
//	}
//}