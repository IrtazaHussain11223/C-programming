//#include <iostream>
//using namespace std;
//
//int main() {
//    int Arr[100];
//    int arr[100];
//    int count = 0;
//
//    cout << "Enter elements of array and -1 to exit:\n";
//    for (int i = 0; i < 100; i++) {
//        cin >> Arr[i];
//        if (Arr[i] == -1)
//            break;
//        count++;
//    }
//
//    int i = 0;
//    int count2 = count;
//
//    while (i < count) {
//        for (int j = 0; j < count2 - 1; j++) {
//            if (Arr[j] > Arr[j + 1]) {
//                int temp = Arr[j];
//                Arr[j] = Arr[j + 1];
//                Arr[j + 1] = temp;
//            }
//        }
//        arr[i] = Arr[count2 - 1];
//        i++;
//        count2--;
//
//        if (i >= count) break;
//
//        for (int j = 0; j < count2 - 1; j++) {
//            if (Arr[j] < Arr[j + 1]) {
//                int temp = Arr[j];
//                Arr[j] = Arr[j + 1];
//                Arr[j + 1] = temp;
//            }
//        }
//        arr[i] = Arr[count2 - 1];
//        i++;
//        count2--;
//    }
//
//    cout << "Array in max-min order: ";
//    for (int p = 0; p < count; p++) {
//        cout << arr[p] << " ";
//    }
//
//    return 0;
//}#include <iostream>

#include<iostream>
using namespace std;
int main()
{
	int Arr[100];
	int Fab[100];
	int Pri[100];
	int non[100];
	int count = 0;
	int max = 0, temp = 0;
	cout << "Enter the elements of array and enter -1 to termiante\n";
	for (int i = 0; i < 100; i++)
	{
		cin >> Arr[i];
		if (Arr[i] == -1)
			break;
		count++;
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
			}
		}
	}
	max = Arr[count - 1];
	int count2 = 0;
	int n1 = 0, n2 = 1, next = 0;
	for (int i = 0; i < max; i++)
	{
		next = n1 + n2;
		n1 = n2;
		n2 = next;
		if (next > max)
			break;
		Fab[i] = next;
		count2++;
	}
	int p = 0, count3 = 0;
	for (int i = 2; i < max; i++)
	{
		bool isPrime = true;
		for (int j = 2; j * j <= i; j++)
		{
			count3++;
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			Pri[p++] = i;
		}
	}


	for (int i = 0; i < count3; i++)
		cout << Pri[i] << " ";
}
