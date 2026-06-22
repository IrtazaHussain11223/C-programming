#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<math.h>
using namespace std;
int main()
{
int fd[2];
pipe(fd);
int fd1[2];
pipe(fd1);
pid_t par=fork();
if(par!=0)
{
int num;
cout<<"Enter the integetr you want to sqwuare\n";
cin>>num;
int size_p = write(fd[1],&num,sizeof(int));
close(fd[0]);
int newnum;
int size_p2= read(fd1[0],&newnum,sizeof(int));
cout<<"The sqyuare root from child is"<<newnum;
}
else
{
int num2;
int size_c= read(fd[0],&num2,sizeof(int));
cout<<num2;
close(fd[1]);
int num3=sqrt(num2);
int size_c1=write(fd1[1],&num3,sizeof(int));
close(fd1[0]);

}
}
