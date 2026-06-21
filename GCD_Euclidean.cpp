#include<iostream>
using namespace std;

int main()
{int num1,num2,gcd;
char dummy,option;
do{

cout<<"Please Enter two Integers: ";
cin>>num1>>dummy>>num2;
while(num2>0)
{gcd=num1%num2;
num1=num2;
num2=gcd;
}
cout<<"GCD of two Numbers is: "<<num1<<endl;
cout<<"Do you Want to continue...(Y/N)";
cin>>option;
}while(option=='Y'||option=='y');

system("pause");
return 0;

}

