/*This program will take a number from the user and check
whether its a palindrome or not*/
# include<iostream>
using namespace std;
int main()
{
int number=0,orignal_Num=0,remainder=0,rev_Num=0;
cout<<"Enter a postive number: ";
cin>>number; //121=1+0*10=1*10+2=12*10=120+1=121
orignal_Num=number;
while(number>0)
{remainder=number%10;//12%10==>2==>1%10=1
rev_Num=rev_Num*10+remainder; //rev_Num=10+2=12*10=120+1=121 
number/=10;	//121/10==>12/10==>1
}
if(orignal_Num==rev_Num)
{cout<<orignal_Num<<" is a Palindrome"<<endl;
}else{
cout<<orignal_Num<<" is not a Palindrome"<<endl;
}
return 0;
}

