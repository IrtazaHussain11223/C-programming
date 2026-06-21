/*This progam will take a number from the user and check
whether its prime number of not*/
# include<iostream>
using namespace std;
int main()
{
int n;
cout<<"Enter a positive number: ";
cin>>n;
bool isPrime=true;
if(n==1||n==0)
{isPrime=false;
}

int i=2;
while(i<=n/2)  
{if(n%i==0)
  {
  isPrime=false;
  break;
}
i++;
}
if(isPrime)
{cout<<n<<" is a Prime Number"<<endl;
}else
{cout<<n<<" is not a Prime Number"<<endl;
}
return 0;
}

