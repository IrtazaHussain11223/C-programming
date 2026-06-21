//#include<iostream>
//using namespace std;
//int main()
//{
//
//	char Arr[8][6];
//	char want;
//	int choice = 0;
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			Arr[i][j] = 'A';
//		}
//	}
//	cout << "Enter the floor in which you wanna book a room\nFloor 1 and 2 for first class\nFloor 3 to 8 are economy class\nFloor 1 to 5 are for non-smokers\nFloor 6 to 8 are for smokers";
//	cin >> choice;
//	while (choice != -1)
//	{
//		if (choice == 1 || choice == 2)
//		{
//			for (int i = choice - 1; i < 2; i++)
//			{
//				for (int j = 0; j < 6; j++)
//				{
//					cout << "Do you want this room y for yes n for no" << i << " " << j;
//					cin >> want;
//					if (want == 'y' || want == 'Y')
//					{
//						Arr[i][j] = 'B';
//					}
//				}
//			}
//		}
//		if (choice > 2 && choice < 8)
//		{
//
//		}
//		cout << "Enter your choice again\n";
//		cin >> choice;
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			cout << Arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//}