//#include <iostream>
//using namespace std;
//
//int main() {
//    int Arr[100];
//    int arr[100];
//    int count = 0;
//
//    cout << "Enter elements of array and -1 to exit:\n";
//    for (int i = 0; i < 100; i++) 
//    {
//        cin >> Arr[i];
//        if (Arr[i] == -1)
//            break;
//        count++;
//    }
//
//    int i = 0;
//    int count2 = count;
//
//    while (i < count)
// {
//        for (int j = 0; j < count2 - 1; j++)
//        {
//            if (Arr[j] > Arr[j + 1]) 
//            {
//                int temp = Arr[j];
//                Arr[j] = Arr[j + 1];
//                Arr[j + 1] = temp;
//            }
//        }
//        arr[i] = Arr[count2 - 1];
//        i++;
//        count2--;
//
//        if (i >= count) 
//            break;
//
//        for (int j = 0; j < count2 - 1; j++)
//        {
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
//    cout << "Array in max-min order ";
//    for (int p = 0; p < count; p++) 
//    {
//        cout << arr[p] << " ";
//    }
//
//    return 0;
//}
