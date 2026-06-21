//#include<iostream> 
//using namespace std;
//int main()
//{
//	int count = 0;
//	int Arr[100];
//	cout << "Enter the elemenst of array and enter -1 to stop\n";
//	for (int i = 0; i < 100; i++)
//	{
//		cin >> Arr[i];
//		if (Arr[i] == -1)
//		{
//			break;
//		}
//		count++;
//	}
//	for (int i = 0; i < count; i++)
//	{
//		while (Arr[i] > 1 || Arr[i] < -1)
//		{
//			cout << "This " << Arr[i] << " is incorrect value enter again\n ";
//			cin >> Arr[i];
//		}
//	}
//	for (int i = 0; i < 1; i++)
//	{
//		for (int j = 0; j < count; j++)
//		{
//			if (Arr[j] == 0)
//			{
//				cout << Arr[j] << " ";
//			}
//			if (Arr[j] == -1)
//			{
//				break;
//			}
//		}
//		for (int j = 0; j < count; j++)
//		{
//			if (Arr[j] == 1)
//			{
//				cout << Arr[j] << " ";
//			}
//			if (Arr[j] == -1)
//			{
//				break;
//			}
//		}
//	}
//}