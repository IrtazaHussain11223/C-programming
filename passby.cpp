///*#include<iostream>
//using namespace std;
//int swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//	return 0;
//}
//int main()
//{
//	int a = 20, b = 10;
//	swap(a, b);
//	cout << "a is " << a << endl;
//	cout << "B is " << b << endl;
//}*/
//#include<iostream>
//using namespace std;
//
//bool symmetric(int A[], int size);
//
//int main()
//{
//    int size = 5;
//    int A[5];
//    cout << "Enter values of array\n";
//    for (int i = 0; i < size; i++)
//    {
//        cin >> A[i];
//    }
//    bool result = symmetric(A, size);
//    if (result)
//        cout << "Yes";
//    else
//        cout << "No";
//
//    return 0;
//}
//
//bool symmetric(int A[], int size)
//{
//    for (int i = 0; i < size / 2; i++)
//    {
//        if (A[i] != A[size - 1 - i])
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
