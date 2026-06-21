//#include<iostream>
//using namespace std;
//int main()
//{
//	int count = 0, temp = 0;
//	int Arr[20];
//	int disArr[20];
//	int UnArr[20];
//	cout << "Enter elements and enter -99 to stop\n";
//	for (int i = 0; i < 20; i++)
//	{
//		cin >> Arr[i];
//		if (Arr[i] == -99)
//		{
//			break;
//		}
//		count++;
//	}
//	int count2 = 0;
//	int count3 = 0;
//
//	for (int i = 0; i < count; i++)
//	{
//		count2 = 0;
//		for (int j = 0; j < count; j++)
//		{
//			if (Arr[i] == disArr[j] && i != j)
//			{
//				count2++;
//			}
//
//		}
//		if (count2 == 0)
//		{
//			disArr[count3] = Arr[i];
//			count3++;
//		}
//	}
//	for (int k = 0; k < count3 - 1; k++)
//	{
//		for (int p = 0; p < count3 - k - 1; p++)
//		{
//			if (disArr[p] > disArr[p + 1])
//			{
//				temp = disArr[p];
//				disArr[p] = disArr[p + 1];
//				disArr[p + 1] = temp;
//
//			}
//		}
//	}
//	cout << "Array of Distinct elements is \n";
//	for (int q = 0; q < count3; q++)
//	{
//		cout << disArr[q] << " ";
//	}
//	cout << "\nUNique elements of aray are \n";
//	int count4 = 0;
//	int count5 = 0;
//	int l = 0;
//	for (int i = 0; i < count; i++)
//	{
//		count4 = 0;
//		for (int j = 0; j < count; j++)
//		{
//			if (Arr[i] == Arr[j] && i != j)
//			{
//				count4++;
//			}
//
//		}
//		if (count4 == 0)
//		{
//			cout << Arr[i] << " ";
//			for (int l = 0; l < count5; l++)
//			{
//				UnArr[l] = Arr[i];
//			}
//			l++;
//			count5++;
//		}
//
//	}
//	for (int g = 0; g < count - 20; g++)
//	{
//		cout << UnArr[g] << " ";
//	}
//}