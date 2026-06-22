#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<math.h>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;
int processseg(int *arr,int L,int R)
{
int segsize=R-L+1;
if(segsize<10)// base case
{
int max=arr[L];
for(int i=L;i<=R;i++)
{
if(arr[i]>max)
max=arr[i];}
cout<<"PID is "<<getpid()<<endl;
cout<<"PPID is "<<getppid()<<endl;
cout<<"MAX :"<<max<<endl;
exit(max);
}
else
{
int Max=(L+R)/2;
pid_t childL=fork();
if(childL==0)
{

processseg(arr,L,Max);// L to max
exit(0);
}
pid_t childR=fork();
if(childR==0)
{
processseg(arr,Max+1,R);// Max+1 to R for 2nd part
exit(0);
}
int statusL,statusR;
waitpid(childL,&statusL,0);
waitpid(childR,&statusR,0);
int infoL=WEXITSTATUS(statusL);
int infoR=WEXITSTATUS(statusR);
int maxvalue;
if(infoL>infoR)
maxvalue=infoL;
else
maxvalue=infoR;
cout<< "PID: "<< getpid();
cout<< " PPID: "<< getppid();
cout<<" MAX overall is: "<<maxvalue << endl;
exit(maxvalue);
}

};
int main(int argc,char* argv[])
{

int size=stoi(argv[1]);
int *arr= new int[size];
srand(time(NULL));
for (int i=0;i<size;i++)
{arr[i]=rand()%256;
}

for (int i=0;i<size;i++)
{
cout<<arr[i]<<endl;
}
processseg(arr,0,size-1);}
