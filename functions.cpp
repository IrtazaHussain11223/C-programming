//#include<iostream>
//using namespace std;
//int main()
//{
//	char Arr[8][6];
//	int choice = 0;
//	bool check = false;
//	while (choice != -1)
//	{
//		cout << "Enter the floor in which you wanna book a room\nFloor 1 and 2 for first class\nFloor 3 to 8 are economy class\nFloor 1 to 5 are for non-smokers\nFloor 6 to 8 are for smokers";
//		cin >> choice;
//		if (choice == 1 || choice == 2)
//		{
//			for (int i = choice; i <= 2; i++)
//			{
//				for (int j = 0; j < 6; j++)
//				{
//					cin >> Arr[i][j];
//				}
//			}
//		}
//		if (choice > 2 && choice < 8)
//		{
//			for (int i = choice; i <= 8; i++)
//			{
//				for (int j = 0; j < 6; j++)
//				{
//					cout << i << " " << j;
//				  cin >> Arr[i][j];
//				  if (Arr[i][j] == -1)
//				  {
//					  check = true;
//					  break;
//				  }
//
//				}
//				if (check == true)
//					break;
//			}
//		}
//		cout << "Again enter choice\n";
//		cin >> choice;
//	}
//}
//#include<iostream>
//using namespace std;
//int sum(int a, int b)
//{
//	 int plus=a + b;
//	 return plus;
//}
//int main()
//{
//	/*retrun value tyep fun name(argument list)              in c function name has first word small of  first word  and first word capital of 2 word
//	{
//	statemnts
//	}
//	
//	
//	
//	*/
//	char x, y;
//	cout << "enter values for addition";
//	cin >> x >> y;
//	cout << "Result is " << sum(x, y);
//}
/*#include<iostream>
using namespace std;
//int trisum(int num);//here we can remove name as function will only match the type 
//int main()
//{
//	int n = 5;
//	cout << "Triangle sum is " << trisum(n);
//	return 0;
//}
//int trisum(int num)
//{
//	int ts = 0;
//	for (int c = 1; c <= num; c++)
//	{
//		ts += c;
//	}
//	return ts;
//}
void swap(int &a, int &b)//here & poinst to the memeroy location where data is
//stored all primitive data types are pass by values i.e not actual datais sne dbut a copy of data is 
// send and after the exectuion that copy is delected
{
	int temp;
	temp = a;
	a = b;//in pass by value original value is not changed and copy of value is chnaged where as in passby refernce original value is chnaged
	b = temp;
}
int main()
{
	int x = 2;
	int y = 3;
	swap(x, y);
	cout << x << " " << y;
	return 1;
}*/
