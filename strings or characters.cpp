//#include<iostream>
//using namespace std;
//int main()
//{
///*Do not use string class eg    string str={x,y,z}; if we use it it will result in ezro marks
//if we declre a string of 20 charcters and put 4 in it result will have garbage and to avoid it we will put \0 in it  eg= char name[20];    
//input = [Razi\0] if \0 is not put here remaining 16 spaces will also print gaving garbage value
//also decalr a space for null character if it not decalred it will result in error*/
//	/*const char str[] = "Hello class";//here 1 space is used for \0 or null
//	char str[] = { 'H','e','l','l','o','\0'};//Here is null is missed it will reuslt in garbage value
//	cout <<"Size of this string is " << str;*/
//	/*char str[5];
//	cin >> str;
//	for (int i = 0; i <= 5; i++)
//	{
//		cin >> str[i];
//	}
//	for (int j = 0; j <= 5; j++)
//	{
//		cout << str[j];
//	}*/
//	/*char str[20] = { 'H','e','l','l','o','\0' };
//	cin >> str;//this one will terminate when null is achieved
//	for (int i = 0; i < 20; i++)//this in inefficnet loop 
//	{
//		cin >> str[i];
//	}*/
//	/*cin.getline(str,100)  this  will terminate when enter is pressed by the user and will end with \0 or null problem with cin is that
//	it stops at space but this getline one will not 
//	char str[20];
//	cin.getline(str, 20);
//	cout << str;*/
//	/*char name[20];
//	char address[20];
//	cin >> name;
//	cin.ignore();//this will remove the given problem or problem down here they both automatically append null or \0
//	cin.getline(address,30);//Here cin ends when will use new line or enter key and geline will thoghts that as cin has ended and enter is \0 so getline will take tkae \0 and will not take any input from user
//	cout << address;// in order to resolve this problem we use cin.ignore(); aftr cin*/
//	/*const int size = 100;
//	char str[size];
//	cin >> str;
//
//	int lenght = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (str[i] == '\0')
//		{
//			break;
//		}
//		lenght++;
//	}
//	bool ispalindrome = true;
//	for (int i = 0; i < lenght / 2; i++)
//	{
//		if(str[i])
//	}*/
//}