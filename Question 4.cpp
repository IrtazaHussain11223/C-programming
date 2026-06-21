//#include <iostream>
//using namespace std;
//
//int main() {
//    int Arr[100];
//    int Fib[100];
//    int Non[100];
//    int Pri[100];
//    int count = 0;
//
//    cout << "Enter the elements of the array and enter -1 to terminate:\n";
//    for (int i = 0; i < 100; i++) 
//    {
//        cin >> Arr[i];
//        if (Arr[i] == -1)
//            break;
//        count++;
//    }
//
//    int max = Arr[0];
//
//    for (int i = 0; i < count; i++) 
//    {
//        if (Arr[i] > max) 
//        {
//            max = Arr[i];
//        }
//    }
//
//    int n1 = 0, n2 = 1, next = 0;
//    int fibCount = 0;
//
//    while (next <= max)
//    {
//        Fib[fibCount++] = next;
//        next = n1 + n2;
//        n1 = n2;
//        n2 = next;
//    }
//
//    int priCount = 0;
//    for (int i = 2; i <= max; i++) 
//    {
//        bool isPrime = true;
//        for (int j = 2; j * j <= i; j++) 
//        {
//            if (i % j == 0) 
//            {
//                isPrime = false;
//                break;
//            }
//        }
//        if (isPrime)
//        {
//            Pri[priCount++] = i;
//        }
//    }
//
//    int nonCount = 0;
//    int outputCount = 0;
//    int output[100];
//
//    for (int i = 0; i < count; i++)
//    {
//        bool isFibonacci = false;
//        bool isPrime = false;
//
//        for (int j = 0; j < fibCount; j++)
//        {
//            if (Arr[i] == Fib[j])
//            {
//                isFibonacci = true;
//                break;
//            }
//        }
//
//        for (int j = 0; j < priCount; j++) 
//        {
//            if (Arr[i] == Pri[j])
//            {
//                isPrime = true;
//                break;
//            }
//        }
//
//        if (isFibonacci)
//        {
//            output[outputCount++] = Arr[i];
//        }
//    }
//
//    for (int i = 0; i < count; i++)
//    {
//        bool isFibonacci = false;
//        bool isPrime = false;
//
//        for (int j = 0; j < fibCount; j++) 
//        {
//            if (Arr[i] == Fib[j]) 
//            {
//                isFibonacci = true;
//                break;
//            }
//        }
//
//        for (int j = 0; j < priCount; j++)
//        {
//            if (Arr[i] == Pri[j]) 
//            {
//                isPrime = true;
//                break;
//            }
//        }
//
//        if (isFibonacci && !isPrime) 
//        {
//            output[outputCount++] = Arr[i];
//        }
//    }
//
//    for (int i = 0; i < count; i++)
//    {
//        bool isFibonacci = false;
//        bool isPrime = false;
//
//        for (int j = 0; j < fibCount; j++)
//         {
//            if (Arr[i] == Fib[j])
//            {
//                isFibonacci = true;
//                break;
//            }
//        }
//
//        for (int j = 0; j < priCount; j++) 
//        {
//            if (Arr[i] == Pri[j])
//            {
//                isPrime = true;
//                break;
//            }
//        }
//         
//        if (isPrime) 
//        {
//            output[outputCount++] = Arr[i];
//        }
//    }
//
//    cout << "Final segregated array:\n";
//    for (int i = 0; i < outputCount; i++) 
//    {
//        cout << output[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
