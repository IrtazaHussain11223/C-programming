//#include<iostream>
//using namespace std;
//int main()
//{
//	int Arr[100];
//	int count = 0;
//	cout << "enter elemts of array and enter -1 to termiante the array\n";
//	for (int i = 0; i < 100; i++)
//	{
//		cin >> Arr[i];
//		if (Arr[i] == -1)
//			break;
//		count++;
//	}
//	int temp = 0;
//	for (int i = 0; i < count; i+=2)
//	{
//		for (int j = 0; j < count-2;j+=2)
//		{
//			
//			if (j % 2 == 0)
//			{
//				if (Arr[j] > Arr[j + 2])
//				{
//					temp = Arr[j];
//					Arr[j] = Arr[j + 2];
//					Arr[j + 2] = temp;
//				}
//			}
//			
//			
//		}
//	}
//	int temp2 = 0;
//	for (int i = 1; i < count; i+=2)
//	{
//		for (int j = 1; j < count-2; j+=2)
//		{
//			if (j % 2 == 1)
//			{
//				if (Arr[j] < Arr[j + 2])
//				{
//					temp2 = Arr[j];
//					Arr[j] = Arr[j + 2];
//					Arr[j + 2] = temp2;
//				}
//			}
//		}
//	}
//	cout << "Index ";
//	for (int i = 0; i < count; i++)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "Values ";
//	for (int i = 0; i < count; i++)
//	{
//		cout << Arr[i] << " ";
//	}
//
//}