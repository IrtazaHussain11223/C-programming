#include<iostream>
using namespace std;
int main()
{
int H=10, J=5, S=3, D=0; 
// H is Height, J is  jump, S is slip, D is distance covered.
cout<< "enter H, J, S respectively : ";
cin>>H>>J>>S;
int JumpCount=0;   
if(J<=S && H>J)
{
  cout<<"Frog is imprisoned forever...!"<<endl;
  return 0;
    }
do
{
 D+=J;
 if(D<H)
    D -= S;
 JumpCount++;
}while(D<H);
cout<<"Total Jumps: "<<JumpCount<<endl;
return 0;
}
