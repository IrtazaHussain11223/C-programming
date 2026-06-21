//#include <iostream>
//using namespace std;
//
//int main()
//{
//    char Arr[10];
//    int n = 10;
//    cin.getline(Arr, n);
//    cin.ignore();
//    int maxl = 0, crl = 0;
//    int i = 0;
//    while (true)
//    {
//        if (Arr[i] == ' ' || Arr[i] == '\0')
//        {
//            if (crl > maxl)
//                maxl = crl;
//            crl = 0;
//        }
//        else
//            crl++;
//        if(Arr[i]=='\0')
//        {
//            break;
//        }
//        i++;
//    }
//
//    cout << "You entered: " << maxl << endl;
//    return 0;
//}
