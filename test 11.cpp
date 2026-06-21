////#include<iostream>
////#include<stdlib.h>
////#include<time.h>
////#include<fstream>
////#include<string>
////using namespace std;
////int main()
////{
////	int arr[5] = { 5,4,1,2,3 };
////	int N = 5;
////	int min, count=0, tmp=0, index=0;
////	for (int count = 0; count < N; count++)
////	{
////		min = count;
////		for (int index = count; index < N; index++)
////		{
////			if (arr[index] < arr[min])
////			{
////				min = index;
////			}
////		}
////		tmp = arr[min];
////		arr[min] = arr[count];
////		arr[count] = tmp;
////	}
////	
////	for (int i = 0; i < N; i++)
////	{
////		cout << arr[i] << " ";
////	}
////}
////#include<iostream>
////using namespace std;
////
////int main()
////{
////    int H; //height
////    char symbol;
////    cout << "Enter height: ";
////    cin >> H;
////    cout << "Enter symbol: ";
////    cin >> symbol;
////    for (int ln = 1; ln <= H; ln++)
////    {
////        for (int j = 1; j < ln; j++)
////        {
////            cout << " ";
////        }
////        for (int k = H; k >= ln; k--)
////        {
////            cout << symbol;
////        }
////
////        cout << endl;
////    }
////
////
////    system("pause");
////    return 0;
////
////}
////#include<iostream>
////using namespace std;
////int main()
////{
////	for (int i = 0; i < 5; i++)
////	{
////		for (int j = 0; j <= i; j++)
////		{
////			cout << " ";
////		}
////		for (int k = 5; k > i; k--)
////		{
////			cout << " *";
////		}
////		cout << endl;
////	}
////}
////# include<iostream>
////using namespace std;
////int main()
////{
////	int height;
////	cout << "Enter height: ";
////	cin >> height;
////	int row = 0;
////	while (row < height)
////	{
////		int count = 0;
////		while (count < height - row)
////		{
////			cout << " ";
////			count++;
////		}
////		count = 0;
////		while (count < 2 * row + 1)
////		{
////			cout << "*";
////			count++;
////		}
////		cout << endl;
////		row++;
////	}
////	while (row >= 0)
////	{
////		int count = 0;
////		while (count < height - row)
////		{
////			cout << " ";
////			count++;
////		}
////		count = 0;
////		while (count < 2 * row + 1)
////		{
////			cout << "*";
////			count++;
////		}
////		cout << endl;
////		row--;
////
////	}
////	return 0;
////}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int height;
//    cout << "Enter height: ";
//    cin >> height;
//
//    // Upper part of the diamond
//    for (int row = 0; row < height; row++) {
//        // Print spaces
//        for (int space = 0; space < height - row; space++) {
//            cout << " ";
//        }
//        // Print stars
//        for (int star = 0; star < 2 * row + 1; star++) {
//            cout << "*";
//        }
//        cout << endl;
//    }
//
//    // Lower part of the diamond
//    for (int row = height - 1; row >= 0; row--) {
//        // Print spaces
//        for (int space = 0; space < height - row; space++) {
//            cout << " ";
//        }
//        // Print stars
//        for (int star = 0; star < 2 * row + 1; star++) {
//            cout << "*";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
//
//
//
